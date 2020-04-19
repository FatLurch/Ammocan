params["_vehicle"];

if (isServer || isDedicated) then{[_vehicle] spawn fatLurch_fnc_convertTurretAmmo};

diag_log format ["### Ammocan Debug - initAmmocan called on %1", _vehicle];

_vehicle addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
	
	_turretIndex = [_unit, _weapon, _gunner] call fatLurch_fnc_getTurretIndex;	//retrieve the turret index of the current weapon system being fired
	_found = false;
	_ammo = (magazinesAllTurrets _unit select _turretIndex) select 2;	//ammo command has bug and won't return the ammo for a secondary turret. This is a workaround

	[_unit] call fatLurch_fnc_removeEmptyMagsTurret;		//Remove empty magazines so it's easier to detect an empty weapon
	
	//Push ammo into the turret at 1 round remaining, otherwise the various turret types don't reload automatically, even when commanded to with "loadMagazine" and "reload"
	if(_ammo ==1) then
	{	
	
		diag_log format ["### Ammocan Debug - ammo ==1 on %1", _unit];
	
		_vehCargoMags = magazineCargo _unit;	//Get an array of the magazines in the vehicle
		_vehMags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");	//get an array of the types of magazines the weapon can use
		
		//Go through each of the magazines (ammocans) in the vehicle and see if they'll work with the weapon being fired
		{
			
			_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
			
			//If the item in the vehicle inventory is an ammocan
			if(_ammocan == "true") then
			{
				
				
				_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply
				_matchMagazine = _vehMags arrayIntersect _magArray;	//see if there are matches between the ammo types the ammocan supports, and the types the weapon can use
				
				//If there the ammo types are compatible
				if(count _matchMagazine > 0 && !_found) then
				{
					diag_log format ["### Ammocan Debug - Processing ammocan: %1  Adding magazine %2 to vehicle %3", _x, _matchMagazine,_unit];
					_unit addMagazineTurret [_matchMagazine select 0,[_turretIndex]];			//Add the ammo to the turret
					[_unit, _x]call fatLurch_fnc_removeMagazine;							//Remove ammocan from vehicle inventory
					_found = true;														//This variable prevents the loop from loading ALL of the compatible ammo cans at once
				};
			};
		}forEach _vehCargoMags;
	};
}];



//Need to ensure logic for getting ammo count is correct

_vehicle addEventHandler ["ContainerClosed", {
	//Handle condition where weapon goes Winchester and later someone loads ammo into the vehicle
	
	params ["_container", "_unit"];
	
	_found=false;
	_index = [];
	_array = [];
	_matchMagazine = [];
	_magazinesAllTurrets = magazinesAllTurrets _container;
	
	[_container] call fatLurch_fnc_removeEmptyMagsTurret;	//Remove empty magazines so it's easier to detect an empty weapon
	
	{
		_index =  _x;
				
		//If the turret weapon is out of ammo (the magazine is deleted from the weapon when ammo == 0) in the fired EH above
		if(count(_container magazinesTurret _x) ==0) then
		{
			_array = getArray ([_container, _index] call BIS_fnc_turretConfig >> "weapons");
			_weapon = _array select 0;																										
			_vehMags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");		//ammo the vehicle weapon can accept
			_vehCargoMags = magazineCargo _container;	//Get an array of the magazines in the vehicle
					
			//Go through each of the magazines (ammocans) in the vehicle and see if they'll work with the weapon being fired
			{			
				_ammocan = toLower(getText(configFile >> "CfgMagazines" >> _x >> "ammocan"));	//Retrieve unique ammocan parameter (will only be "true" on ammocans)
				
				//If the item in the vehicle inventory is an ammocan
				if(_ammocan == "true") then
				{
					_magArray = getArray (configFile >> "CfgMagazines" >> _x >> "magazines");	//Get an array of which ammo types the ammocan can supply		
					_matchMagazine = _vehMags arrayIntersect _magArray;	//see if there are matches between the ammo types the ammocan supports, and the types the weapon can use
					
					//If there the ammo types are compatible
					if(count _matchMagazine > 0 && !_found) then
					{	
						_container addMagazineTurret [_matchMagazine select 0, _index];			//Add the ammo to the turret
						[_container, _x]call fatLurch_fnc_removeMagazine;							//Remove ammocan from vehicle inventory	
						_found = true;						
					};
				};
			}forEach _vehCargoMags;
		};			
	}forEach allTurrets [_container, false];	//the boolean sets wether to return FFV turrets or not.
}];
