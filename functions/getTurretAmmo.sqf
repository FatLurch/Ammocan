//returns ammo count for a given turretPath and weapon. Returns 0 if unable to find ammo for the indicated turret

//ARMA BUG/NOTE: Only works when there is a unit in the turret being queried.

params["_vehicle", "_turretPath", "_weapon"];

weaponState [_vehicle , _turretPath, _weapon] select 4;

