params["_vehicle", "_turretIndex", "_weapon"];

_allMagazines = _vehicle magazinesTurret [_turretIndex, false];

_allMagazines = [_allMagazines] call fatLurch_fnc_toLowerArray;

_weaponMatchedMagazines = [];

_weaponAcceptableMagazines = [_weapon] call CBA_fnc_compatibleMagazines;

_weaponAcceptableMagazines = [_weaponAcceptableMagazines] call fatLurch_fnc_toLowerArray;


{
	
	if(_x  in _weaponAcceptableMagazines) then
	{
		_weaponMatchedMagazines pushback _x;
	};
		
}forEach _allMagazines;

count(_weaponMatchedMagazines)