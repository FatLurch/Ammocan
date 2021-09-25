//returns ammo count for a given turretPath. Returns null if unable to find ammo for the indicated turret

//ARMA BUG/NOTE: Only works when there is a unit in the turret being queried.

params["_vehicle", "_turretPath"];

_magazines = magazinesAllTurrets _vehicle;

{
	_currentMag = _vehicle currentMagazineTurret _turretPath;
	
	diag_log format["### Ammocan Debug - getTurretAmmo.sqf - _currentMag:%1, _x: %2", _currentMag, _x];

	if(_currentMag == _x select 0) exitWith {_x select 2};
	
}forEach _magazines;