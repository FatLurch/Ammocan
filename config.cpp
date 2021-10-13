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
		magazines[] = 
		{
			"Ammocan_200Rnd_127x99_mag",
			"Ammocan_200Rnd_127x99_mag_Tracer_Red",
			"Ammocan_200Rnd_127x99_mag_Tracer_Yellow",
			"Ammocan_200Rnd_127x99_mag_Tracer_Green",
			"Ammocan_200Rnd_127x99_mag_SLAP",
			"Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red",
			"Ammocan_100Rnd_127x99_mag",
			"Ammocan_100Rnd_127x99_mag_Tracer_Red",
			"Ammocan_100Rnd_127x99_mag_Tracer_Yellow",
			"Ammocan_100Rnd_127x99_mag_Tracer_Green",
			"Ammocan_100Rnd_127x99_mag_SLAP",
			"Ammocan_100Rnd_127x99_mag_SLAP_Tracer_Red",
			"Ammocan_130Rnd_338_mag",
			"Ammocan_RHS_48Rnd_40mm_MK19_M430A1",
			"Ammocan_RHS_48Rnd_40mm_MK19_M1001",
			"Ammocan_96Rnd_40mm_G_belt",
			"Ammocan_RHS_96Rnd_40mm_MK19_M1001",
			"Ammocan_RHS_48Rnd_40mm_MK19_M1001",
			"Ammocan_rhs_mag_762x51_M240_200_M80",
			"Ammocan_rhs_mag_762x51_M240_200",
			"Ammocan_rhs_mag_400rnd_127x99_mag",
			"Ammocan_400Rnd_127x99_mag_Tracer_Red", 
			"Ammocan_400Rnd_127x99_mag_SLAP",
			"Ammocan_400Rnd_127x99_mag_SLAP_Tracer_Red", 
			"Ammocan_rhs_mag_TOW",
			"Ammocan_rhs_mag_TOWB",
			"Ammocan_rhs_mag_ITOW",
			"Ammocan_rhs_mag_TOW2",
			"Ammocan_rhs_mag_TOW2A",
			"Ammocan_rhs_mag_TOW2b",
			"Ammocan_rhs_mag_TOW2b_aero",
			"Ammocan_rhs_mag_TOW2bb",
			"Ammocan_2000Rnd_762x51_Belt_T_Red",
			"Ammocan_1Rnd_GAT_missiles", 
			"Ammocan_UK3CB_BAF_32Rnd_40mm_G_Box", 
			"Ammocan_CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", 
			"Ammocan_1000Rnd_762x51", 
			"Ammocan_900Rnd_127x99"
		};
	};
};


class cfgVehicles
{	
	class Land_FireExtinguisher_F;
	class Test_thing:Land_FireExtinguisher_F
	{
 		ammocan = "true";
 		ammo = "";
 		author = "Fat_Lurch";
 		displayName = "M2A1 Ammocan";
 		picture = "\Ammocan\data\ammocan.paa";
 		model = "\Ammocan\M2A1.p3d";
 		hiddenSelections[] = {"camo"};								// List of model selections which can be changed with hiddenSelectionTextures[]
		hiddenSelectionsTextures[] = {"Ammocan\data\Marking_100x_M2.paa"};	// The textures for the selections defined above.
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
 		//model = "\A3\Structures_F_EPB\Items\Military\Ammobox_rounds_F.p3d";
 		model = "\Ammocan\M2A1.p3d";
 		mass = 50;
 	};
 	
 	 // 400x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_rhs_mag_400rnd_127x99_mag:ammocan_base
 	{
 		//RHS
 		//Vurtual HMMWV
		displayName = " Ammocan - 400x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag", "vurtual_400Rnd_127x99_belt"};
		count=400;
	};
 	
 	class Ammocan_400Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_mag_Tracer_Red"};
		count=400;
	};
	
	class Ammocan_400Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag"};
		count=400;
	};

	class Ammocan_400Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 400x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>400 Rounds";
		magazines[] = {"rhs_mag_400rnd_127x99_SLAP_mag_Tracer_Red"};
		count=400;
	};
 	
 	// 200x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_200Rnd_127x99_mag:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag", "rhs_mag_200rnd_127x99_mag"};
		count=200;
	};
 	
 	class Ammocan_200Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Red", "rhs_mag_200rnd_127x99_mag_Tracer_Red"};
		count=200;
	};
	
	 class Ammocan_200Rnd_127x99_mag_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Yellow"};
		count=200;
	};
		
	class Ammocan_200Rnd_127x99_mag_Tracer_Green:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 200x .50 Cal (12.7x99) Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>200 Rounds";
		magazines[] = {"200Rnd_127x99_mag_Tracer_Green"};
		count=200;
	};
	
	class Ammocan_200Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag"};
		count=200;
	};

	class Ammocan_200Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 200x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>200 Rounds";
		magazines[] = {"rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red"};
		count=200;
	};
	
 	// 100x 12.7x99 NATO aka .50 BMG =====================================================================================================
 	
 	class Ammocan_100Rnd_127x99_mag:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag", "rhs_mag_100rnd_127x99_mag","CUP_100Rnd_127x99_M"};
		count=100;
	};
 	
 	class Ammocan_100Rnd_127x99_mag_Tracer_Red:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//CUP
 		//3CB
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Red Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red","CUP_100Rnd_TE4_Red_Tracer_127x99_M", "UK3CB_BAF_127_100Rnd"};
		count=100;
	};
	
	 class Ammocan_100Rnd_127x99_mag_Tracer_Yellow:ammocan_base
 	{
 		//Vanilla
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Yellow Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Yellow Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Yellow", "CUP_100Rnd_TE4_Yellow_Tracer_127x99_M"};
		count=100;
	};
		
	class Ammocan_100Rnd_127x99_mag_Tracer_Green:ammocan_base
 	{
 		//Vanilla
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) Green Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Green Tracer<br>100 Rounds";
		magazines[] = {"100Rnd_127x99_mag_Tracer_Green","CUP_100Rnd_TE4_Green_Tracer_127x99_M"};
		count=100;
	};
	
	class Ammocan_100Rnd_127x99_mag_Tracer_White:ammocan_base
 	{
 		//CUP
		displayName = " Ammocan - 100x .50 Cal (12.7x99) M2 White Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm White Tracer<br>100 Rounds";
		magazines[] = {"CUP_100Rnd_TE4_White_Tracer_127x99_M"};
		count=100;
	};
	
	class Ammocan_100Rnd_127x99_mag_SLAP:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) SLAP";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag"};
		count=100;
	};

	class Ammocan_100Rnd_127x99_mag_SLAP_Tracer_Red:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 100x .50 Cal (12.7x99) SLAP Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm SLAP Red Tracer<br>100 Rounds";
		magazines[] = {"rhs_mag_100rnd_127x99_SLAP_mag_Tracer_Red"};
		count=100;
	};
	
	 // 900x 12.7x99 NATO aka .50 BMG =====================================================================================================
	
	class Ammocan_900Rnd_127x99:ammocan_base
 	{
 		//Vurtual HMMWV
		displayName = " Ammocan - 900x .50 Cal (12.7x99) Ball";
		descriptionShort = "Ammocan<br>Caliber: 12.7x99 mm Ball<br>900 Rounds";
		magazines[] = {"vurtual_900Rnd_127x99_belt"};
		count=900;
	};
	
	// 130x .338 Magnum =====================================================================================================
	
	class Ammocan_130Rnd_338_mag:ammocan_base
 	{
 		//Vanilla
		displayName = " Ammocan - 130x .338 Norma Magnum";
		descriptionShort = "Ammocan<br>Caliber: .338 Norma Magnum<br>130 Rounds";
		magazines[] = {"130Rnd_338_Mag"};
		count=130;
	};
	
	// 32x 40mm =====================================================================================================
		
	class Ammocan_UK3CB_BAF_32Rnd_40mm_G_Box:ammocan_base
 	{
 		//3CB
		displayName = " Ammocan - 32x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>32 Rounds";
		magazines[] = {"UK3CB_BAF_32Rnd_40mm_G_Box"};
		count=32;
	};
	
	
	// 48x 40mm =====================================================================================================
	
	class Ammocan_RHS_48Rnd_40mm_MK19_M430A1:ammocan_base
 	{
 		//RHS
 		//CUP
 		//Vurtual HMMWV
		displayName = " Ammocan - 48x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>48 Rounds";
		magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1", "CUP_48Rnd_40mm_MK19_M", "vurtual_48Rnd_40mm_G_belt"};
		count=48;
	};
	
	class Ammocan_RHS_48Rnd_40mm_MK19_M1001:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 48x 40mm Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm Canister<br>48 Rounds";
		magazines[] = {"RHS_48Rnd_40mm_MK19_M1001"};
		count=48;
	};
	
	// 96x 40mm =====================================================================================================
	
	class Ammocan_96Rnd_40mm_G_belt:ammocan_base
 	{
 		//Vanilla
 		//RHS
 		//Vurtual HMMWV
		displayName = " Ammocan - 96x 40mm HEDP";
		descriptionShort = "Ammocan<br>Caliber: 40mm HEDP<br>96 Rounds";
		magazines[] = {"RHS_96Rnd_40mm_MK19_M430A1", "96Rnd_40mm_G_belt", "vurtual_96Rnd_40mm_G_belt"};
		count=96;
	};
	class Ammocan_RHS_96Rnd_40mm_MK19_M1001:ammocan_base
 	{
 		//RHS
		displayName = " Ammocan - 96x 40mm Canister";
		descriptionShort = "Ammocan<br>Caliber: 40mm Canister<br>96 Rounds";
		magazines[] = {"RHS_96Rnd_40mm_MK19_M1001",};
		count=96;
	};
	
	// 100x 7.62x51 NATO =====================================================================================================

	class Ammocan_CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M:ammocan_base
 	{
 		//CUP
 		
 		//Tracer every 4
		displayName = " Ammocan - 100x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>100 Rounds";
		magazines[] = {"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"};
		count=100;
	};
	
	// 200x 7.62x51 NATO =====================================================================================================

	class Ammocan_rhs_mag_762x51_M240_200:ammocan_base
 	{
 		//RHS
 		
 		
 		//Tracer every 5
		displayName = " Ammocan - 200x 7.62x51mm EPR";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm M80A1 EPR<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200"};
		count=200;
	};
	
	class Ammocan_rhs_mag_762x51_M240_200_M80:ammocan_base
 	{
 		//RHS
 		//3CB
 		//Vurtual HMMWV
 		//Foxhound LPPV
 		
 		//Tracer every 5
		displayName = " Ammocan - 200x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm Ball<br>200 Rounds";
		magazines[] = {"rhs_mag_762x51_M240_200_M80", "UK3CB_BAF_762_200Rnd", "UK3CB_BAF_762_200Rnd_T", "vurtual_200rnd_762x51_box", "vurtual_200Rnd_762x51_box_heli", "200Rnd_762x51_Belt_Red"};
		count=200;
	};
	
	// 1000x 7.62x51 NATO =================================================================================================
		
	class Ammocan_1000Rnd_762x51:ammocan_base
 	{
 		//Vurtual HMMWV
		displayName = " Ammocan - 1000x 7.62x51mm";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm<br>1000 Rounds";
		magazines[] = {"vurtual_1000rnd_762x51_box"};
		mass = 150;
		count=1000;
	};
		
	// 2000x 7.62x51 NATO =================================================================================================
		
	class Ammocan_2000Rnd_762x51_Belt_T_Red:ammocan_base
 	{
 		//Vanilla
 		//CUP (used in M134)
 		//Vurtual HMMWV
		displayName = " Ammocan - 2000x 7.62x51mm Red Tracer";
		descriptionShort = "Ammocan<br>Caliber: 7.62x51mm Red Tracer<br>2000 Rounds";
		magazines[] = {"CUP_2000Rnd_TE1_Red_Tracer_762x51_M134_M","2000Rnd_762x51_Belt_T_Red", "vurtual_2000Rnd_762x51_belt_heli", "vurtual_2000Rnd_762x51_belt"};
		mass = 150;
		count=2000;
	};
	
	// 1x TOW Missile =====================================================================================================

	class Ammocan_rhs_mag_TOW:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71A TOW Missile";
		descriptionShort = "Ammocan<br>BGM-71A";
		magazines[] = {"rhs_mag_TOW"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_rhs_mag_TOWB:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71B TOW Missile";
		descriptionShort = "Ammocan<br>BGM-71B";
		magazines[] = {"rhs_mag_TOWB"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_rhs_mag_ITOW:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71C ITOW Missile";
		descriptionShort = "Ammocan<br>BGM-71C";
		magazines[] = {"rhs_mag_ITOW"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_rhs_mag_TOW2:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71D TOW-2 Missile";
		descriptionShort = "Ammocan<br>BGM-71D";
		magazines[] = {"rhs_mag_TOW2"};
		mass = 80;
		count=1;
	};

	class Ammocan_rhs_mag_TOW2A:ammocan_base
 	{
 		//RHS
 		//CUP
		displayName = "Ammocan - BGM-71E TOW-2A Missile";
		descriptionShort = "Ammocan<br>BGM-71E";
		magazines[] = {"rhs_mag_TOW2a", "CUP_1Rnd_TOW2_M"};
		mass = 80;
		count=1;
	};

	class Ammocan_rhs_mag_TOW2b:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71F TOW-2B Missile";
		descriptionShort = "Ammocan<br>BGM-71F";
		magazines[] = {"rhs_mag_TOW2b"};
		mass = 80;
		count=1;
	};
	
	class Ammocan_rhs_mag_TOW2b_aero:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71F-3 TOW-2B Aero Missile";
		descriptionShort = "Ammocan<br>BGM-71F-3";
		magazines[] = {"rhs_mag_TOW2b_aero"};
		mass = 80;
		count=1;
	};

	class Ammocan_rhs_mag_TOW2bb:ammocan_base
 	{
 		//RHS
		displayName = "Ammocan - BGM-71H Bunker Buster Missile";
		descriptionShort = "Ammocan<br>BGM-71H ";
		magazines[] = {"rhs_mag_TOW2bb"};
		mass = 80;
		count=1;
	};
	
	
	// 1x AT Missile =====================================================================================================

	class Ammocan_1Rnd_GAT_missiles:ammocan_base
 	{
 		//Vanilla
		displayName = "Ammocan - 1x Titan AT Missile";
		descriptionShort = "Ammocan<br>Titan AT";
		magazines[] = {"1Rnd_GAT_missiles"};
		mass = 80;
		count=1;
	};

 };



