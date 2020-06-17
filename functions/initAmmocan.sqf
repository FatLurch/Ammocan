params["_vehicle"];

_turretIndex = [];

if (isServer || isDedicated) then{[_vehicle] spawn fatLurch_fnc_convertTurretAmmo};

_vehicle addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

	_found = false;	
	
	_turretIndex = [_unit, _weapon, _gunner] call fatLurch_fnc_getTurretIndex;	//retrieve the turret index of the current weapon system being fired
	_ammo = [_unit, _turretIndex, _weapon] call fatLurch_fnc_getWeaponAmmo;	//BIS functions for getting ammo from a (secondary) turret are bugged
	
	//Push ammo into the turret at 1 round remaining, otherwise the various turret types don't reload automatically, even when commanded to with "loadMagazine" and "reload"
	if(_ammo ==1) then
	{	
		_vehCargoMags = magazineCargo _unit;	//Get an array of the magazines in the vehicle
		_vehMags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");	//get an array of the types of magazines the weapon can use
		
		//Go through each of the magazines (ammocans) in the vehicle and see if they'll work with the weapon being fired
		{			
			_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
			if(_ammocan == "true") then
			{
				_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
				_matchMagazine = _vehMags arrayIntersect _magArray;	//see if there are matches between the ammo types the ammocan supports, and the types the weapon can use
				
				//If there the ammo types are compatible
				if(count _matchMagazine > 0 && !_found) then
				{
					diag_log format ["### Ammocan Debug - initAmmocan.sqf - Fired EH - Processing ammocan: %1  Adding magazine %2 to vehicle %3", _x, _matchMagazine,_unit];
					_unit addMagazineTurret [_matchMagazine select 0,_turretIndex];			//Add the ammo to the turret
					[_unit, _x]call fatLurch_fnc_removeMagazine;							//Remove ammocan from vehicle inventory
					_found = true;														//Prevents numerous canms from being loaded into the turret at once
				};
			};
		}forEach _vehCargoMags;
	};
}];

_vehicle addEventHandler ["ContainerClosed", {
	//Handle condition where weapon goes Winchester and later someone loads ammo into the vehicle
	
	params ["_container", "_unit"];
	
	_found=false;
	_index = [];
	_array = [];
	_matchMagazine = [];
	_vehMags =[];
	_magArray = [];
	_magazinesAllTurrets = magazinesAllTurrets _container;
	
	{
		_turretPath = _x;
		_turretWeapons = [_container, _turretPath] call fatLurch_fnc_getTurretWeapons;	//Return an array of weapons associated with the current turret path
		
		{
			//evaluate the ammo of each weapon in the turret
			
			_ammo = [_container, _turretPath, _x] call fatLurch_fnc_getWeaponAmmo;	//return the ammo SPECIFIC to the weapon being evaluated
			_weapon = _x;	//Current turret weapon being evaluated
			
			if(_ammo ==0) then			
			{				
				_vehMags = [_weapon] call bis_fnc_compatibleMagazines;		//ammo the vehicle weapon can accept
				_vehMags = [_vehMags] call fatLurch_fnc_toLowerArray;		//Convert all string elements to lowercase
				_vehCargoMags = magazineCargo _container;	//Get an array of the magazines in the vehicle

				//Go through each of the magazines (ammocans) in the vehicle and see if they'll work with the weapon being fired
				{			
					_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
					if(_ammocan == "true") then
					{
						_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply	
						_magArray = [_magArray] call fatLurch_fnc_toLowerArray;		//Convert all string elements to lowercase
						_matchMagazine = _vehMags arrayIntersect _magArray;	//see if there are matches between the ammo types the ammocan supports, and the types the weapon can use
						
						//If a compatible ammocan is found
						if(count _matchMagazine > 0 && !_found) then
						{	
							diag_log format["### Ammocan Debug - initAmmocan.sqf - Container Closed EH - container: %1", _container];
							diag_log format["### Ammocan Debug - initAmmocan.sqf - Container Closed EH - found: %1", _found];
							
							
							_container addMagazineTurret [_matchMagazine select 0, _turretPath];			//Add the ammo to the turret
							[_container, _x]call fatLurch_fnc_removeMagazine;							//Remove ammocan from vehicle inventory	
							_found = true;															//Prevents numerous cans from being loaded into the turret at once
							_container loadMagazine [_turretPath, _weapon, _matchMagazine select 0];			//Load the newly added turret magazine	
							reload _container;							
						};
						
					};
					
				}forEach _vehCargoMags;
			};		
			
		}forEach _turretWeapons;	
		
	}forEach allTurrets _container;	
}];
