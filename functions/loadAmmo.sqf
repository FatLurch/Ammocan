//This function loads a specific ammo type into a turret, consumes an ammo can, performs the turret reload and removes empty magazines from the turret

params["_vehicle", "_weapon", "_magType", "_ammoCanType", "_turretIndex"];

diag_log format ["### Ammocan Debug - loadAmmo.sqf - Loading magazine %1 to vehicle %2 turret %3 and consuming ammocan type %4",  _magType, _vehicle, _turretIndex, _ammoCanType];

_vehicle addMagazineTurret [_magType,_turretIndex];			//Add the ammo to the turret
[_vehicle, _ammoCanType]call fatLurch_fnc_removeMagazine;	//Remove ammocan from vehicle inventory
_vehicle loadMagazine [_turretIndex, _weapon, _magType]; 		//"load" the magazine
reload _vehicle;												//perform an actual reload action (animation, etc.)
[_vehicle] call fatLurch_fnc_removeEmptyMagsTurret;				//Remove any empty magazines from the turret

