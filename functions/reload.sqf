//This functions reloads the turret. If the magazine is empty then a simple reload is performed. If the magazine is partially spent, the partial is put into inventory

params["_player"];

_vehicle = vehicle _player;	

if(!([_vehicle] call fatLurch_fnc_compatabilityCheck)) exitWith {};	

_turret = _vehicle unitTurret _player;						//current turret
_weapon = _vehicle currentWeaponTurret _turret;			//current turret weapon
_magazine = _vehicle currentMagazineTurret _turret;			//type of magazine in the turret
_ammo = [_vehicle, _turret, _weapon] call fatLurch_fnc_getTurretAmmo;	//ammo count

_found = false;

if((weaponState [_vehicle, _turret, _weapon] select 6) > 0) exitWith {};	//Do not interrupt a reload

if(_magazine == "") then {_ammo = 0};	//If there's no magazine in the gun, just say the ammo is 0

//Perform reload
if(!(_vehicle isKindOf "staticWeapon")) then
{
	//Air, Car, Tank and Ship can all be handled the same because they all have containers/inventory
	_ammoType = [_vehicle, _turret, _magazine, _weapon] call fatLurch_fnc_loadAmmoFromInventory;
	
	if(count(_ammoType)>0)  then
	{
		_vehicle removeMagazineTurret [_magazine,_turret];												//Clear the magazine from the turret
		[_vehicle, _weapon, _ammoType select 0, _ammoType select 1, _turret] call fatLurch_fnc_loadAmmo;	//Load the ammo
		
		if(_ammo > 0) then 
		{
			//place an ammocan in inventory with the equivalent round count as the partially spent magazine
			_vehicle addMagazineAmmoCargo [[_magazine] call fatLurch_fnc_findAmmocanType, 1, _ammo];
		};		
	};
}
else
{
	//Special handler for statics
	//SystemChat "It's a static!";
};
