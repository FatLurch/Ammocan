//This functions reloads the turret. If the magazine is empty then a simple reload is performed. If the magazine is partially spent, the partial is put into inventory

params["_player"];
_vehicle = vehicle _player;	

if(!([_vehicle] call fatLurch_fnc_compatabilityCheck)) exitWith {};	

_turret = _vehicle unitTurret _player;						//current turret
_weapon = _vehicle currentWeaponTurret _turret;			//current turret weapon
_magazine = _vehicle currentMagazineTurret _turret;			//type of magazine in the turret
_ammo = [_vehicle, _turret] call fatLurch_fnc_getTurretAmmo;	//ammo count

if((weaponState [_vehicle, _turret, _weapon] select 6) > 0) exitWith {};	//Do not interrupt a reload

if(_magazine == "") then {_ammo = 0};	//If there's no magazine in the gun, just say the ammo is 0

if(!(_vehicle isKindOf "Air") && !(_vehicle isKindOf "Car") && !(_vehicle isKindOf "Tank") && !(_vehicle isKindOf "Ship") && !(_vehicle isKindOf "staticWeapon")) exitWith {};		

if(_weapon == "Laserdesignator_mounted") exitWith {};

if(_ammo == 0) then 
{	
	//Just reload
	if(!(_vehicle isKindOf "staticWeapon")) then
	{
		//Air, Car, Tank and Ship can all be handled the same because they all have containers/inventory
		[_vehicle, _turret, _magazine, _weapon] call fatLurch_fnc_loadAmmoFromInventory;
		//diag_log format["### reload.sqf - called loadAmmoFromInventory"];
	}
	else
	{
		//Special handler for statics
		//SystemChat "It's a static!";
	};
}
else
{
	//Handle partial reload
	if(!(_vehicle isKindOf "staticWeapon")) then
	{
		_vehicle removeMagazineTurret [_magazine,_turret];							//Clear the magazine from the turret
		[_vehicle, _turret, _magazine, _weapon] call fatLurch_fnc_loadAmmoFromInventory;		//Figure out what kind of ammocan corresponds to the magazine in the turret
		_vehicle addMagazineAmmoCargo [[_magazine] call fatLurch_fnc_findAmmocanType, 1, _ammo];		//place an ammocan in inventory with the equivalent round count as the partially spent magazine
		}
	else
	{
		//Special handler for statics
		//SystemChat "It's a static!";
	};
};