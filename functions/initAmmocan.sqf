//This function calls for ammo conversion and adds event handlers for a particular vehicle

params["_vehicle"];

_turretIndex = [];

if (isServer || isDedicated) then{[_vehicle] spawn fatLurch_fnc_convertTurretAmmo};

_vehicle addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

	_found = false;	
	
	_turretIndex = [_unit, _weapon, _gunner] call fatLurch_fnc_getTurretIndex;	//retrieve the turret index of the current weapon system being fired
	_ammo = [_unit, _turretIndex, _weapon] call fatLurch_fnc_getWeaponAmmo;	//BIS functions for getting ammo from a (secondary) turret are bugged
	
	if(_ammo == 0) then
	{	
		//_ai = !(isPlayer gunner _unit);
		_ai = !(isPlayer (_vehicle turretUnit _turretIndex));
		
		if(missionnamespace getVariable "Fat_Lurch_Ammocan_Hint") then {hint "Press R to reload the turret";};
		
		if(_ai) then
		{
			[_unit, _turretIndex, _magazine] call fatLurch_fnc_loadAmmoFromInventory;
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
