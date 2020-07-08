params["_vehicle"];

sleep 1;	

_turretWeapons = [];

{
	_magazine = _x select 0;
	_turretIndex = _x select 1;
	_ammo = _x select 2;
	_count = count(_vehicle magazinesTurret _turretIndex);
	_foundType =[_magazine] call fatLurch_fnc_findAmmocanType;
	
	if(_foundType != "" && _ammo > 0) then
	{			
		If(_vehicle canAdd _foundType) then
		{
			diag_log format["### Ammocan Debug  - convertTurretAmmo.sqf - Converting ammo in vehicle %1, foundType: %2,  _magazine: %3", _vehicle, _foundType, _magazine];
			_vehicle addMagazineCargoGlobal [_foundType, 1];
			[_vehicle, [_magazine,_turretIndex]] remoteExec ["removeMagazinesTurret", _vehicle]; 	
			[_vehicle, [_magazine,_turretIndex]] remoteExec ["addMagazineTurret", _vehicle]; 	
		};
	};

}forEach magazinesAllTurrets _vehicle;