params["_vehicle"];

sleep 2;		//Was 1 second - changed to 2 in hopes of alleviating Zeus issue

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
			_vehicle removeMagazinesTurret [_magazine,_turretIndex];		//This isn't working on Zeus spawned vehicles
			_vehicle addMagazineTurret [_magazine,_turretIndex];
		};
	};

}forEach magazinesAllTurrets _vehicle;