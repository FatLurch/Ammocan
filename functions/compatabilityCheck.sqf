//This function checks to see if turrets on the vehicle are currently supported. Any turret that doesn't have at least one supported mag type will return false 

params ["_vehicle", ["_verboseOutput", false]];

_blacklist = ["UK3CB_BAF_Safe", "Laserdesignator_mounted"];	//This is a blacklist of special weapons that should simply be skipped instead of being evaluated

_returnValue = true;

{
	_turretIndex = _x;
	
	{
		_weapon = _x;
		
		if(!(_weapon in _blacklist)) then
		{	
			_turretMagazines = [_weapon] call BIS_fnc_compatibleMagazines;
			_count = 0;
				
			{
				_magType = _x;
				if([_magType] call fatLurch_fnc_findAmmocanType == "") then	
				{		
					if(_verboseOutput) then {diag_log format["### Ammocan - No supported ammocan for magazine type: %1 for weapon: %2 in vehicle type: %3", _magType, _weapon, typeOf _vehicle];};		
				}
				else
				{
					_count = _count + 1;							
				};
				
			}forEach _turretMagazines;
			
			if(_count == 0) exitWith 
			{
				if(_verboseOutput) then {diag_log format["### Ammocan - There are no supported magazine/ammocan types for weapon: %1 in vehicle type: %2 - Ammocan will not be loaded for this vehicle", _weapon, typeOf _vehicle];};	
				_returnValue = false;
			};
		
		};
		
	}forEach (_vehicle weaponsTurret _turretIndex);
	
}forEach allTurrets [_vehicle, false];

_returnValue

