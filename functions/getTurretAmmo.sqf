params["_vehicle", "_turretPath"];

//diag_log format["### getTurretAmmo - _vehicle:%1, _turretPath: %2", _vehicle, _turretPath];

//returns ammo count for a given turretPath. Returns null if unable to find ammo for the indicated turret

//ARMA BUG/NOTE: Only works when there is a unit in the turret being queried.

_magazines = magazinesAllTurrets _vehicle;

{

	_currentMag = _vehicle currentMagazineTurret _turretPath;
	
	diag_log format["### getTurretAmmo - _currentMag:%1, _x: %2", _currentMag, _x];

	if(_currentMag == _x select 0) exitWith {_x select 2};
//Use currentMagazineTurret function. Iterate through the magazinesAllTurrets array and only return ammo if the ammo type matches that from currentMagazineTurret
	
}forEach _magazines;