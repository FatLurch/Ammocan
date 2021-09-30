//This function calls for ammo conversion and adds event handlers for a particular vehicle

params["_vehicle"];

//Check to see if a vehicle is supported

if(!([_vehicle, true] call fatLurch_fnc_compatabilityCheck)) exitWith {};	//Do not load the ammocan functions onto the vehicle if it has unsupported weapons

_turretIndex = [];

if (isServer || isDedicated) then {[_vehicle] spawn fatLurch_fnc_convertTurretAmmo};

_vehicle addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

	_found = false;	
	
	_vehicle = vehicle _unit;
	
	_turretIndex = [_unit, _weapon, _gunner] call fatLurch_fnc_getTurretIndex;	//retrieve the turret index of the current weapon system being fired
	_ammo = [_unit, _turretIndex, _weapon] call fatLurch_fnc_getWeaponAmmo;	//BIS functions for getting ammo from a (secondary) turret are bugged
	
	if(_ammo == 0) then
	{	
		//_ai = !(isPlayer gunner _unit);
		_ai = !(isPlayer (_vehicle turretUnit _turretIndex));
		
		diag_log format["### initAmmocan  ammo = 0      _ai: %1 - _vehicle: %2 - _turretIndex: %3 - _gunner: %4", str(_ai), _vehicle, _turretindex, _vehicle turretUnit _turretIndex];
		
		if(_ai) then
		{
			[_unit, _turretIndex, _magazine] call fatLurch_fnc_loadAmmoFromInventory;
		}
		else
		{	
			if(missionnamespace getVariable "Fat_Lurch_Ammocan_Hint") then {hint "Press R to reload the turret";};		
		};
		
	};
}];

_vehicle addEventHandler ["ContainerClosed", {
	//Handle condition where weapon goes Winchester and later someone loads ammo into the vehicle for an AI
	
	params ["_vehicle", "_unit"];	
	//_vehicle = the vehicle acting as a container
	//_unit = the unit that closed the inventory
	
	{
		_turretIndex = _x;
		_weapon = _vehicle currentWeaponTurret _turretIndex;
		_ammo = [_vehicle, _turretIndex, _weapon] call fatLurch_fnc_getWeaponAmmo;	//BIS functions for getting ammo from a (secondary) turret are bugged
		
		if(_ammo == 0) then
		{		
			_ai = !(isPlayer (_vehicle turretUnit _turretIndex));
			
			if(_ai) then
			{
				[_vehicle, _turretIndex, _magazine] call fatLurch_fnc_loadAmmoFromInventory;
			};		
			
		};
	
	}forEach allTurrets [_vehicle, false];
		
}];
