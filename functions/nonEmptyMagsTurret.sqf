//returns the number of non empty magazines for a given turret
params ["_vehicle", "_turretPath"];

//systemChat "nonEmptyMagsTurret called";

_count = 0;
{
	systemChat format["_x: %1  turretPath: %2", _x, _turretPath];

	if((_x select 1 isEqualTo _turretPath) && (_x select 2 > 0)) then {systemChat "match";_count = _count+1};

}forEach magazinesAllTurrets _vehicle;

_count


//_magazines = [vehicle player] call bis_fnc_compatibleMagazines;

//getArray ([cursorTarget, [0,0]] call BIS_fnc_turretConfig >> "weapons");