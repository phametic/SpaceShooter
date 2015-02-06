// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SpaceShooter.h"
#include "SpaceShooter.generated.dep.h"
void EmptyLinkFunctionForGeneratedCodeSpaceShooter() {}
	void AShip::StaticRegisterNativesAShip()
	{
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"MoveLeftRight",(Native)&AShip::execMoveLeftRight);
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"MoveUpDown",(Native)&AShip::execMoveUpDown);
	}
	IMPLEMENT_CLASS(AShip);
	void ASpaceShooterGameMode::StaticRegisterNativesASpaceShooterGameMode()
	{
	}
	IMPLEMENT_CLASS(ASpaceShooterGameMode);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_MoveLeftRight();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_MoveUpDown();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceShooterGameMode_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceShooterGameMode();
	SPACESHOOTER_API class UPackage* Z_Construct_UPackage_SpaceShooter();
	UFunction* Z_Construct_UFunction_AShip_MoveLeftRight()
	{
		struct Ship_eventMoveLeftRight_Parms
		{
			float Value;
		};
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("MoveLeftRight"), RF_Public|RF_Transient|RF_Native) UFunction(FPostConstructInitializeProperties(), NULL, 0x00080401, 65535, sizeof(Ship_eventMoveLeftRight_Parms));
			UProperty* NewProp_Value = new(ReturnFunction, TEXT("Value"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(Value, Ship_eventMoveLeftRight_Parms), 0x0000000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Left & Right movement"));
			MetaData->SetValue(NewProp_Value, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AShip_MoveUpDown()
	{
		struct Ship_eventMoveUpDown_Parms
		{
			float Value;
		};
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("MoveUpDown"), RF_Public|RF_Transient|RF_Native) UFunction(FPostConstructInitializeProperties(), NULL, 0x00080401, 65535, sizeof(Ship_eventMoveUpDown_Parms));
			UProperty* NewProp_Value = new(ReturnFunction, TEXT("Value"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(Value, Ship_eventMoveUpDown_Parms), 0x0000000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Up & Down movement"));
			MetaData->SetValue(NewProp_Value, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShip_NoRegister()
	{
		return AShip::StaticClass();
	}
	UClass* Z_Construct_UClass_AShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = AShip::StaticClass();
			UObjectForceRegistration(OuterClass);
			OuterClass->ClassFlags |= 0x00900080;

			OuterClass->LinkChild(Z_Construct_UFunction_AShip_MoveLeftRight());
			OuterClass->LinkChild(Z_Construct_UFunction_AShip_MoveUpDown());

			OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_MoveLeftRight());
			OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_MoveUpDown());
			OuterClass->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
			MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation AI|Navigation Pawn|Character|InternalEvents"));
			MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Ship.h"));
			MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShip(Z_Construct_UClass_AShip);
	UClass* Z_Construct_UClass_ASpaceShooterGameMode_NoRegister()
	{
		return ASpaceShooterGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpaceShooterGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = ASpaceShooterGameMode::StaticClass();
			UObjectForceRegistration(OuterClass);
			OuterClass->ClassFlags |= 0x009002A4;


			OuterClass->ClassConfigName = FName(TEXT("Game"));
			OuterClass->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
			MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Input Movement Collision Rendering Utilities|Transformation Info MovementReplication Replication Actor"));
			MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SpaceShooterGameMode.h"));
			MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SpaceShooterGameMode.h"));
			MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpaceShooterGameMode(Z_Construct_UClass_ASpaceShooterGameMode);
	UPackage* Z_Construct_UPackage_SpaceShooter()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/SpaceShooter")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0xB4D984A6;
			Guid.B = 0x15642528;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);
		}
		return ReturnPackage;
	}
#endif

