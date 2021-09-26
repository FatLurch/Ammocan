//This functions reloads the turret. If the magazine is empty then a simple reload is performed. If the magazine is partially spent, the partial is put into inventory

params["_player"];
_vehicle = vehicle _player;									
_turret = _vehicle unitTurret _player;						//current turret
_weapon = _vehicle currentWeaponTurret _turret;			//current turret weapon
_magazine = _vehicle currentMagazineTurret _turret;			//type of magazine in the turret
_ammo = [_vehicle, _turret] call fatLurch_fnc_getTurretAmmo;	//ammo count

if(!(_vehicle isKindOf "Air") && !(_vehicle isKindOf "Car") && !(_vehicle isKindOf "Tank") && !(_vehicle isKindOf "Ship")) exitWith {};		//*For now*, ignore turrets and others

if(_weapon == "Laserdesignator_mounted") exitWith {};

if(_ammo ==0) then 
{	
	//Just reload
	[_vehicle, _turret, _magazine] call fatLurch_fnc_loadAmmoFromInventory;
}
else
{
	_vehicle removeMagazineTurret [_magazine,_turret];							//Clear the magazine from the turret
	[_vehicle, _turret, _magazine] call fatLurch_fnc_loadAmmoFromInventory;		//Figure out what kind of ammocan corresponds to the magazine in the turret
	_vehicle addMagazineAmmoCargo [[_magazine] call fatLurch_fnc_findAmmocanType, 1, _ammo];		//place an ammocan in inventory with the equivalent round count as the partially spent magazine
};