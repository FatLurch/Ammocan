//This function checks to see if turrets on the vehicle are currently supported. Any turret that doesn't have at least one supported mag type will return false 

params ["_vehicle", ["_verboseOutput", false]];

_blacklist = [] call fatLurch_fnc_weaponBlacklist;

_returnValue = true;

{
	_turretIndex = _x;
	
	//Don't waste time on turrets without weapons (e.g. FFV)
	if(count(getArray([_vehicle, _turretIndex] call BIS_fnc_turretConfig >> "weapons")) > 0) then
	{
		
		{
			_weapon = toLower(_x);
			
			if(!(_weapon in _blacklist)) then
			{	
				_turretMagazines = [_weapon] call CBA_fnc_compatibleMagazines;	//CBA call is apparently more robust than the BIS call
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
	
					_defaultMagazines = getArray([_vehicle, _turretIndex] call BIS_fnc_turretConfig >> "magazines");
					
					if(_verboseOutput) then 
					{
						diag_log format["### Ammocan - There are no supported magazine/ammocan types for weapon: %1 in vehicle type: %2 - Ammocan will not be loaded for this vehicle", _weapon, typeOf _vehicle];
						diag_log format["### Ammocan - The default magazine(s) for weapon: %1 are:", _weapon];
						diag_log format["### Ammocan - %1", _defaultMagazines];
					};
					
					_returnValue = false;
				};
			
			};
			
		}forEach (_vehicle weaponsTurret _turretIndex);
	};
}forEach allTurrets [_vehicle, true];

_returnValue

