//This function loads a specific ammo type into a turret, consumes an ammo can, performs the turret reload and removes empty magazines from the turret

params["_vehicle", "_weapon", "_magType", "_ammoCanType", "_turretIndex"];

_magPool = [_vehicle] call fatLurch_fnc_getAvailableMagsAmmo;

if (count(_magPool) == 0) exitWith {diag_log format ["### Ammocan Debug - loadAmmo.sqf - No magazines in vehicle: %1 - Exiting loadAmmo", _vehicle]};

diag_log format ["### Ammocan Debug - loadAmmo.sqf - Loading magazine %1 to vehicle %2 turret %3 and consuming ammocan type %4 for weapon: %5",  _magType, _vehicle, _turretIndex, _ammoCanType, _weapon];

_magPoolTrim = [];

//create an array of round counts for magazines that are the type we're looking for
{
	if(_x select 0 == _ammoCanType) then
	{
		//If the mag type entry in the array matches the ammo type we're looking for, push the number of rounds that mag has into a new array
		_magPoolTrim pushBack (_x select 1);
	};
}
forEach _magPool;

_max = _magPoolTrim call CBA_fnc_findMax select 0;		//largest ammo count of the selected mag type

//Reload the turret
[_vehicle] call fatLurch_fnc_removeEmptyMagsTurret;				//Remove any empty magazines from the turret. The order of these events is important - reloading won't happen on some guns without removing the empty magazines first
_vehicle addMagazineTurret [_magType,_turretIndex];			//Add a magazine to the turret
_vehicle loadMagazine [_turretIndex, _weapon, _magType]; 		//"load" the magazine (this is distinct from "adding")
_vehicle setMagazineTurretAmmo [_magType, _max, _turretIndex];	//Set the turret ammo to the number of rounds available from the ammocan that was in inventory

if(!(_vehicle isKindOf "staticWeapon")) then
{
	[_vehicle, _ammoCanType, 1, _max] call CBA_fnc_removeMagazineCargo;	//Consume an ammocan from the inventory
}
else
{
	//special handler for static turrets //TODO
};