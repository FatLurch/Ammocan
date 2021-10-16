class CfgPatches
 {
 	class Fat_Lurch_Ammocan
 	{
 		units[] = {};	
 		weapons[] = {};
 		requiredVersion = 0.1;
 		requiredAddons[] = {"A3_Weapons_F_Mark", "cba_main"};	
		version="0.1";
		author="Fat_Lurch";
 	};
 };
 
  //required for Zeus to see the item?
class CfgAddons 
{
	class PreloadAddons 
	{
		class Fat_Lurch_Ammocan
		{
			list[] = 
			{
				"Fat_Lurch_Ammocan"
			};
		};
	};
};

class CfgEditorCategories
{
	class fatLurch_edCat_Ammocans // Category class, you point to it in editorCategory property
	{
		displayName = "Ammocans"; // Name visible in the list
	};
};


class CfgEditorSubcategories
{
	class fatLurch_edsubCat_ammocan_762x51 // Category class, you point to it in editorSubcategory property
	{
		displayName = "7.62x51mm (.308)"; // Name visible in the list
	};

	class fatLurch_edsubCat_ammocan_338_Norma 
	{
		displayName = ".338 Norma Magnum"; 
	};
	
	class fatLurch_edsubCat_ammocan_127x99
	{
		displayName = "12.7x99mm (.50 BMG)"; // 
	};

	class fatLurch_edsubCat_ammocan_40mm
	{
		displayName = "40x53mm (Grenade)"; // 
	};

	class fatLurch_edsubCat_ammocan_missiles
	{
		displayName = "Missiles"; // 
	};
};


class CfgFunctions
{
	class fatLurch
	{
		class ammocan
		{
						
			//[_vehicle]call fatLurch_fnc_initAmmocan;
			class initAmmocan {file = "Ammocan\functions\initAmmocan.sqf";};
			
			//[_vehicle]call fatLurch_fnc_removeEmptyMagsTurret;
			class removeEmptyMagsTurret {file = "Ammocan\functions\removeEmptyMagsTurret.sqf";};
			
			//[_ammoType]call fatLurch_fnc_findAmmocanType;
			class findAmmocanType {file = "Ammocan\functions\findAmmocanType.sqf";};
			
			//[_vehicle]call fatLurch_fnc_convertTurretAmmo;
			class convertTurretAmmo {file = "Ammocan\functions\convertTurretAmmo.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_getTurretAmmo;
			class getTurretAmmo {file = "Ammocan\functions\getTurretAmmo.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_nonEmptyMagsTurret;
			class nonEmptyMagsTurret {file = "Ammocan\functions\nonEmptyMagsTurret.sqf";};
			
			//[_vehicle, _turretPath]call fatLurch_fnc_getTurretWeapons;
			class getTurretWeapons {file = "Ammocan\functions\getTurretWeapons.sqf";};
			
			//[_vehicle, _turretPath, _weapon]call fatLurch_fnc_getWeaponAmmo;
			class getWeaponAmmo {file = "Ammocan\functions\getWeaponAmmo.sqf";};
			
			//[_array]call fatLurch_fnc_toLowerArray;
			class toLowerArray {file = "Ammocan\functions\toLowerArray.sqf";};
			
			//[_vehicle, _turretIndex, _preferredAmmoType (optional)] call fatLurch_fnc_loadAmmoFromInventory;
			class loadAmmoFromInventory {file = "Ammocan\functions\loadAmmoFromInventory.sqf";};
			
			//[_vehicle, _magType, _ammoCanType, _turretIndex] call fatLurch_fnc_loadAmmo;
			class loadAmmo {file = "Ammocan\functions\loadAmmo.sqf";};
			
			//[player] call fatLurch_fnc_reload;
			class reload {file = "Ammocan\functions\reload.sqf";};
			
			//[player] call fatLurch_fnc_selectAmmo;
			class selectAmmo {file = "Ammocan\functions\selectAmmo.sqf";};
			
			//[] call fatLurch_fnc_registerKeybinds;
			class registerKeybinds {file = "Ammocan\functions\registerKeybinds.sqf";};
			
			//[vehicle] call fatLurch_fnc_getAvailableMags;
			class getAvailableMags {file = "Ammocan\functions\getAvailableMags.sqf";};
			
			//[vehicle] call fatLurch_fnc_getAvailableMagsAmmo;
			class getAvailableMagsAmmo {file = "Ammocan\functions\getAvailableMagsAmmo.sqf";};
			
			//[vehicle] call fatLurch_fnc_compatabilityCheck;
			class compatabilityCheck {file = "Ammocan\functions\compatabilityCheck.sqf";};
			
			//[vehicle] call fatLurch_fnc_convertInventoryMagazines;
			class convertInventoryMagazines {file = "Ammocan\functions\convertInventoryMagazines.sqf";};
			
			//[vehicle, blacklist] call fatLurch_fnc_needTurretAmmoConversion;
			class needTurretAmmoConversion {file = "Ammocan\functions\needTurretAmmoConversion.sqf";};
			
			//[vehicle, turretIndex, weapon] call fatLurch_fnc_turretWeaponMagazineCount;
			class turretWeaponMagazineCount {file = "Ammocan\functions\turretWeaponMagazineCount.sqf";};
			
			//[] call fatLurch_fnc_weaponBlacklist;
			class weaponBlacklist {file = "Ammocan\functions\weaponBlacklist.sqf";};

		};
	};
};

class Extended_InitPost_EventHandlers 
{
	class air
	{
        	class Fat_Lurch_ammocan_air {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
   	
   	class car
	{
        	class Fat_Lurch_ammocan_car {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
   	
   	class tank
	{
        	class Fat_Lurch_ammocan_tank {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
     	class ship
	{
        	class Fat_Lurch_ammocan_ship {init = "(_this select 0) call fatLurch_fnc_initAmmocan;";};
   	};
};

class Extended_PreInit_EventHandlers
{
    class fatLurch_Ammocan_PreInits
    {
        // This snippet runs once and only on client machines
        clientInit = "[] call fatLurch_fnc_registerKeybinds;";
    };

};


// ##############################################################################################
// ######  IMPORTANT! New Ammocan types must be lsited here for the system to work properly!
// ##############################################################################################
class cfgWeapons
{
	class Rifle_Base_F;
	class ammocan_fake_gun:Rifle_Base_F
	{
		scope=2;
		displayName = "";
		magazines[] = 
		{
			"Ammocan_762x51_100x",
			"Ammocan_762x51_120x",			
			"Ammocan_762x51_200x_M80",
			"Ammocan_762x51_200x",
			"Ammocan_762x51_1000x",  
			"Ammocan_762x51_1200x",
			"Ammocan_762x51_2000x_Tracer_Red",

			"Ammocan_338_130x",

			"Ammocan_127x99_100x",
			"Ammocan_127x99_100x_Tracer_Red",
			"Ammocan_127x99_100x_Tracer_Yellow",
			"Ammocan_127x99_100x_Tracer_Green",
			"Ammocan_127x99_100x_SLAP",
			"Ammocan_127x99_100x_SLAP_Tracer_Red",
			"Ammocan_127x99_200x",
			"Ammocan_127x99_200x_Tracer_Red",
			"Ammocan_127x99_200x_Tracer_Yellow",
			"Ammocan_127x99_200x_Tracer_Green",
			"Ammocan_127x99_200x_SLAP",
			"Ammocan_127x99_200x_SLAP_Tracer_Red",
			"Ammocan_127x99_400x",
			"Ammocan_127x99_400x_Tracer_Red", 
			"Ammocan_127x99_400x_SLAP",
			"Ammocan_127x99_400x_SLAP_Tracer_Red", 
			"Ammocan_127x99_900x",
			
			"Ammocan_40mm_32x_HEDP", 
			"Ammocan_40mm_48x_HEDP",
			"Ammocan_40mm_48x_Canister",
			"Ammocan_40mm_96x_HEDP",
			"Ammocan_40mm_96x_Canister",
					
			"Ammocan_TOW_1x",
			"Ammocan_TOW_1x_B",
			"Ammocan_ITOW_1x",
			"Ammocan_TOW_1x_2",
			"Ammocan_TOW_1x_2A",
			"Ammocan_TOW_1x_2b",
			"Ammocan_TOW_1x_2b_aero",
			"Ammocan_TOW_1x_2bb",
			
			"Ammocan_GAT_1x"
			
		};
	};

	class ammocan_fake_gun_4:ammocan_fake_gun
	{
		cursor = "rocket";
		type=4;
	};

	//

	class ammocan_fake_gun_5:ammocan_fake_gun
	{
		cursor = "mg";
	};
	
	class ammocan_fake_gun_6:ammocan_fake_gun
	{
		cursor = "srifle";
	};
};


class cfgVehicles
{	

	class Item_Base_F; // External class reference
	class fatLurch_Ammocan_base: Item_Base_F
	{
		scope = 0;
		scopeCurator = 0;
		author = "Fat Lurch";
		vehicleClass = "Small_items";
		editorCategory = "fatLurch_edCat_Ammocans";
		mapSize = 0.2;  	
	};

	// Eden Object Setup #############################################################################################

	// 7.62x51 ---------------------------------------------------------------------------------------

	class fatLurch_Ammocan_762x51_100x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 100x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_100x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_762x51_120x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 120x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_120x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_762x51_200x_M80: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 200x EPR";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_200x_M80";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_762x51_200x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 200x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_200x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_762x51_1000x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 1000x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_1000x";
				count = 1;
			};
		};
	};


	class fatLurch_Ammocan_762x51_1200x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 1200x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_1200x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_762x51_2000x_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "7.62x51mm 2000x Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_762x51";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_762x51_2000x_Tracer_Red";
				count = 1;
			};
		};
	};

	// .338 Norma Magnum ---------------------------------------------------------------------------------------

	class fatLurch_Ammocan_338_130x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = ".338 Norma Magnum 130x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_338_norma";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_338_130x";
				count = 1;
			};
		};
	};



	// 12.7x99 (.50 BMG) ---------------------------------------------------------------------------------------

	class fatLurch_Ammocan_127x99_100x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_100x_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x_Tracer_Red";
				count = 1;
			};
		};
	};


	class fatLurch_Ammocan_127x99_100x_Tracer_Yellow: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x Yellow Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x_Tracer_Yellow";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_100x_Tracer_Green: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x Green Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x_Tracer_Green";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_100x_SLAP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x SLAP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x_SLAP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_100x_SLAP_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 100x SLAP Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_100x_SLAP_Tracer_Red";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x_Tracer_Red";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x_Tracer_Yellow: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x Yellow Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x_Tracer_Yellow";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x_Tracer_Green: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x Green Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x_Tracer_Green";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x_SLAP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x SLAP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x_SLAP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_200x_SLAP_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 200x SLAP Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_200x_SLAP_Tracer_Red";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_400x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 400x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_400x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_400x_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 400x Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_400x_Tracer_Red";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_400x_SLAP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 400x SLAP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_400x_SLAP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_400x_SLAP_Tracer_Red: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 400x SLAP Red Tracer";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_400x_SLAP_Tracer_Red";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_127x99_900x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "12.7x99mm 900x";
		editorSubcategory = "fatLurch_edsubCat_ammocan_127x99";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_127x99_900x";
				count = 1;
			};
		};
	};

	// 40mm ---------------------------------------------------------------------------------------

	class fatLurch_Ammocan_40mm_32x_HEDP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "40mm 32x HEDP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_40mm";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_40mm_32x_HEDP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_40mm_48x_HEDP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "40mm 48x HEDP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_40mm";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_40mm_48x_HEDP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_40mm_48x_Canister: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "40mm 48x Canister";
		editorSubcategory = "fatLurch_edsubCat_ammocan_40mm";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_40mm_48x_Canister";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_40mm_96x_HEDP: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "40mm 96x HEDP";
		editorSubcategory = "fatLurch_edsubCat_ammocan_40mm";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_40mm_96x_HEDP";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_40mm_96x_Canister: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "40mm 96x Canister";
		editorSubcategory = "fatLurch_edsubCat_ammocan_40mm";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_40mm_96x_Canister";
				count = 1;
			};
		};
	};

	/*

	fatLurch_edsubCat_ammocan_missiles
	*/

	// Missiles ---------------------------------------------------------------------------------------

	class fatLurch_Ammocan_TOW_1x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW A Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_B: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW B Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_B";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_ITOW_1x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "ITOW Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_ITOW_1x";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_2: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW 2 Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_2";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_2A: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW 2A Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_2A";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_2B: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW 2B Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_2B";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_2B_aero: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW 2B Aero Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_2B_aero";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_TOW_1x_2BB_aero: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "TOW 2 Bunker Buster Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_TOW_1x_2BB_aero";
				count = 1;
			};
		};
	};

	class fatLurch_Ammocan_GAT_1x: fatLurch_Ammocan_base
	{

		scope = 2;
		scopeCurator = 2;
		displayName = "Guided Anti-Tank Missile";
		editorSubcategory = "fatLurch_edsubCat_ammocan_missiles";
		class TransportItems
		{
			class transport
			{
				name = "Ammocan_GAT_1x";
				count = 1;
			};
		};
	};



};



class CfgMagazines
 {
 	// Base Config Setup #############################################################################################
 	class 30Rnd_556x45_Stanag;
 	class ammocan_base:30Rnd_556x45_Stanag
 	{
 		ammocan = "true";
 		ammo = "";
 		author = "Fat_Lurch";
 		picture = "\Ammocan\data\ammocan.paa";
		model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
 		//model = "\Ammocan\M2A1.p3d";
 		mass = 50;
 	};
 	// #################################################################################################



	// 100x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_127x99_100x:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>100 Rounds";
		magazines[] = {"100rnd_127x99_mag", "rhs_mag_100rnd_127x99_mag","CUP_100rnd_127x99_M"};
		count=100;
	};
 	
 	class Ammocan_127x99_100x_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//CUP
 		//3CB
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>100 Rounds";
		magazines[] = {"100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red","CUP_100rnd_TE4_Red_Tracer_127x99_M", "UK3CB_BAF_127_100rnd"};
		count=100;
	};
	
	class Ammocan_127x99_100x_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>100 Rounds";
		magazines[] = {"100rnd_127x99_mag_Tracer_Yellow", "CUP_100rnd_TE4_Yellow_Tracer_127x99_M"};
		count=100;
	};
		
	class Ammocan_127x99_100x_Tracer_Green:ammocan_base
 	{
 		//Vanilla
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>100 Rounds";
		magazines[] = {"100rnd_127x99_mag_Tracer_Green","CUP_100rnd_TE4_Green_Tracer_127x99_M"};
		count=100;
	};
	
	class Ammocan_127x99_100x_Tracer_White:ammocan_base
 	{
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 White Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm White Tracer<br>100 Rounds";
		magazines[] = {"CUP_100rnd_TE4_White_Tracer_127x99_M"};
		count=100;
	};
	
	class Ammocan_127x99_100x_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag"};
		count=100;
	};

	class Ammocan_127x99_100x_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag_Tracer_Red"};
		count=100;
	};
 	
 	// 200x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_127x99_200x:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>200 Rounds";
		magazines[] = {"200rnd_127x99_mag", "rhs_mag_200rnd_127x99_mag"};
		count=200;
	};
 	
 	class Ammocan_127x99_200x_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>200 Rounds";
		magazines[] = {"200rnd_127x99_mag_Tracer_Red", "rhs_mag_200rnd_127x99_mag_Tracer_Red"};
		count=200;
	};
	
	 class Ammocan_127x99_200x_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>200 Rounds";
		magazines[] = {"200rnd_127x99_mag_Tracer_Yellow"};
		count=200;
	};
		
	class Ammocan_127x99_200x_Tracer_Green:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>200 Rounds";
		magazines[] = {"200rnd_127x99_mag_Tracer_Green"};
		count=200;
	};
	
	class Ammocan_127x99_200x_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag"};
		count=200;
	};

	class Ammocan_127x99_200x_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red"};
		count=200;
	};
	
 	// 400x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_127x99_400x:ammocan_base
 	{
 		//RHS
 		//Vurtual HMMWV
		displayName = " Ammocan - 400x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag", "vurtual_400rnd_127x99_belt"};
		count=400;
	};
 	
 	class Ammocan_127x99_400x_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag_Tracer_Red"};
		count=400;
	};
	
	class Ammocan_127x99_400x_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag"};
		count=400;
	};

	class Ammocan_127x99_400x_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag_Tracer_Red"};
		count=400;
	};

	// 900x 12.7x99 NATO aka .50 BMG =====================================================================================================
	
	class Ammocan_127x99_900x:ammocan_base
 	{
 		//Vurtual HMMWV
		displayName = " Ammocan - 900x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Ball<br>900 Rounds";
		magazines[] = {"vurtual_900rnd_127x99_belt"};
		count=900;
	};
	
	// 130x .338 Magnum =====================================================================================================
	
	class Ammocan_338_130x:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 130x .338 Norma Magnum";
		descriptionShort = "Ammocan<br>Caliber: .338 Norma Magnum<br>130 Rounds";
		magazines[] = {"130rnd_338_Mag"};
		count=130;
	};
	
	// 32x 40mm =====================================================================================================
		
	class Ammocan_40mm_32x_HEDP:ammocan_base
 	{
 		//3CB
 		//BWMod
 		
		displayName = " Ammocan - 32x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>32 Rounds";
		magazines[] = {"UK3CB_BAF_32rnd_40mm_G_Box", "32rnd_40mm_G_belt", "CUP_32Rnd_40mm_MK19_M"};
		count=32;
	};
	
	
	// 48x 40mm =====================================================================================================
	
	class Ammocan_40mm_48x_HEDP:ammocan_base
 	{
 		//RHS
 		//CUP
 		//Vurtual HMMWV
		displayName = " Ammocan - 48x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>48 Rounds";
		magazines[] = {"RHS_48rnd_40mm_MK19_M430A1", "CUP_48rnd_40mm_MK19_M", "vurtual_48rnd_40mm_G_belt"};
		count=48;
	};
	
	class Ammocan_40mm_48x_Canister:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 48x 40mm Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm Canister<br>48 Rounds";
		magazines[] = {"RHS_48rnd_40mm_MK19_M1001"};
		count=48;
	};
	
	// 96x 40mm =====================================================================================================
	
	class Ammocan_40mm_96x_HEDP:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//Vurtual HMMWV
		//CUP

		displayName = " Ammocan - 96x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>96 Rounds";
		magazines[] = {"RHS_96rnd_40mm_MK19_M430A1", "96rnd_40mm_G_belt", "vurtual_96rnd_40mm_G_belt", "CUP_96Rnd_40mm_MK19_M"};
		count=96;
	};
	class Ammocan_40mm_96x_Canister:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 96x 40mm Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm Canister<br>96 Rounds";
		magazines[] = {"RHS_96rnd_40mm_MK19_M1001",};
		count=96;
	};
	
	// 100x 7.62x51 NATO =====================================================================================================

	class Ammocan_762x51_100x:ammocan_base
 	{
 		//CUP
 		
 		//Tracer every 4
		displayName = " Ammocan - 100x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>100 Rounds";
		magazines[] = {"CUP_100rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"};
		count=100;
	};
	
	// 120x 7.62x51 NATO =====================================================================================================

	class Ammocan_762x51_120x:ammocan_base
 	{
 		//BWMod
 		
 		//Tracer every 4
		displayName = " Ammocan - 120x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>120 Rounds";
		magazines[] = {"BWA3_120rnd_762x51_soft"};
		count=120;
	};
	
	// 200x 7.62x51 NATO =====================================================================================================

	class Ammocan_762x51_200x:ammocan_base
 	{
 		//RHS
 		
 		
 		//Tracer every 5
		displayName = " Ammocan - 200x 7.62x51mm EPR";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm M80A1 EPR<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200_M80"};
		count=200;
	};
	
	class Ammocan_762x51_200x_M80:ammocan_base
 	{
 		//RHS
 		//3CB
 		//Vurtual HMMWV
 		//Foxhound LPPV
		//CUP
 		
 		//Tracer every 5
		displayName = " Ammocan - 200x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm Ball<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200", "UK3CB_BAF_762_200rnd", "UK3CB_BAF_762_200rnd_T", "vurtual_200rnd_762x51_box", "vurtual_200rnd_762x51_box_heli", "200rnd_762x51_Belt_Red", "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"};
		count=200;
	};
	
	// 1000x 7.62x51 NATO =================================================================================================
		
	class Ammocan_762x51_1000x:ammocan_base
 	{
 		//Vurtual HMMWV
		displayName = " Ammocan - 1000x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>1000 Rounds";
		magazines[] = {"vurtual_1000rnd_762x51_box"};
		mass = 150;
		count=1000;
	};
		
	// 1200x 7.62x51 NATO =================================================================================================
		
	class Ammocan_762x51_1200x:ammocan_base
 	{
 		//BWMod
 		
		displayName = " Ammocan - 1200x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>1200 Rounds";
		magazines[] = {"BWA3_1200rnd_762x51"};
		mass = 150;
		count=1200;
	};
		
	// 2000x 7.62x51 NATO =================================================================================================
		
	class Ammocan_762x51_2000x_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//CUP (used in M134)
 		//Vurtual HMMWV
		displayName = " Ammocan - 2000x 7.62x51mm Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm Red Tracer<br>2000 Rounds";
		magazines[] = {"CUP_2000rnd_TE1_Red_Tracer_762x51_M134_M","2000rnd_762x51_Belt_T_Red", "vurtual_2000rnd_762x51_belt_heli", "vurtual_2000rnd_762x51_belt"};
		mass = 150;
		count=2000;
	};
	
	// 1x TOW Missile =====================================================================================================

	class Ammocan_TOW_1x:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71A TOW Missile";
		descriptionShort = "Ammocan<br>BGM-71A";
		magazines[] = {"rhs_mag_TOW"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_TOW_1x_B:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71B TOW Missile";
		descriptionShort = "Ammocan<br>BGM-71B";
		magazines[] = {"rhs_mag_TOWB"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_ITOW_1x:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71C ITOW Missile";
		descriptionShort = "Ammocan<br>BGM-71C";
		magazines[] = {"rhs_mag_ITOW"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_TOW_1x_2:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71D TOW-2 Missile";
		descriptionShort = "Ammocan<br>BGM-71D";
		magazines[] = {"rhs_mag_TOW2"};
		mass = 80;
		count=1;
	};

	class Ammocan_TOW_1x_2A:ammocan_base
 	{
 		//RHS
 		//CUP
		displayName = " Ammocan - BGM-71E TOW-2A Missile";
		descriptionShort = "Ammocan<br>BGM-71E";
		magazines[] = {"rhs_mag_TOW2a", "CUP_1rnd_TOW2_M"};
		mass = 80;
		count=1;
	};

	class Ammocan_TOW_1x_2b:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71F TOW-2B Missile";
		descriptionShort = "Ammocan<br>BGM-71F";
		magazines[] = {"rhs_mag_TOW2b"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_TOW_1x_2b_aero:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71F-3 TOW-2B Aero Missile";
		descriptionShort = "Ammocan<br>BGM-71F-3";
		magazines[] = {"rhs_mag_TOW2b_aero"};
		mass = 80;
		count=1;
	};

	class Ammocan_TOW_1x_2bb:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - BGM-71H Bunker Buster Missile";
		descriptionShort = "Ammocan<br>BGM-71H ";
		magazines[] = {"rhs_mag_TOW2bb"};
		mass = 80;
		count=1;
	};
	
	
	// 1x AT Missile =====================================================================================================

	class Ammocan_GAT_1x:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 1x Titan AT Missile";
		descriptionShort = "Ammocan<br>Titan AT";
		magazines[] = {"1rnd_GAT_missiles"};
		mass = 80;
		count=1;
	};

 };