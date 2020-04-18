params["_vehicle"];

sleep 1;

_turretWeapons = [];

{
	_magazine = _x select 0;
	_turretIndex = _x select 1;
	_count = count(_vehicle magazinesTurret _turretIndex);
	_foundType =[_magazine] call fatLurch_fnc_findAmmocanType;
	
	if(_foundType != "") then
	{			
		If(_vehicle canAdd _foundType) then
		{
			diag_log format["### Ammocan Debug  - Converting ammo"];
			_vehicle addMagazineCargoGlobal [_foundType, 1];
			_vehicle removeMagazinesTurret [_magazine,_turretIndex];
			_vehicle addMagazineTurret [_magazine,_turretIndex];
		};
	};

}forEach magazinesAllTurrets _vehicle;