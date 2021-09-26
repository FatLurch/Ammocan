//This function attempts to load preferred ammo into the turret. If preferred ammo cannot be found then the first acceptable type found is used. The preferred ammo type is assumed to be compatible with the weapon

params["_vehicle", "_turretIndex", ["_preferredMagType", ""]];

_vehCargoMags = magazineCargo _vehicle;		//Get an array of the magazines in the vehicle
_weapon = _vehicle currentWeaponTurret _turretIndex;	//get the weapon currently in use for the specified turret
_vehMags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");	//get an array of magazines that are compatible with the turret weapon

_found = false;

//Go through each of the magazines (ammocans) in the vehicle and see if they are the preferred ammo type
if(_preferredMagType != "") then 
{	

	{				
		_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
				
		if(_ammocan == "true") then	//this will only be true for items defined as ammocans				
		{			
			_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
							
			//If preferred ammo is found, load it
			if((_magArray findIf { _x == _preferredMagType; } != -1) && !_found) then
			{			
				[_vehicle, _weapon,  _preferredMagType, _x, _turretIndex] call fatLurch_fnc_loadAmmo;	//Load the preferred ammo
				_found = true;															//Prevents numerous cans from being loaded into the turret at once					
			};
			
		};
		
	}forEach _vehCargoMags;	
	
};


//Go through each of the magazines (ammocans) in the vehicle and see if they are a compatible type (assuming a preferred type wasn't found or specified)
{				
	_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
			
	if(_ammocan == "true") then	//this will only be true for items defined as ammocans				
	{			
		_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
		
		_matchMagazine = _vehMags arrayIntersect _magArray;	//see if there are matches between the ammo types the ammocan supports, and the types the weapon can use
		
		//If there the ammo types are compatible
		if(count _matchMagazine > 0 && !_found) then
		{
			[_vehicle, _weapon, _matchMagazine select 0, _x, _turretIndex] call fatLurch_fnc_loadAmmo;	//Load the ammo
			_found = true;													//Prevents numerous cans from being loaded into the turret at once
		};
		
	};
	
}forEach _vehCargoMags;	
