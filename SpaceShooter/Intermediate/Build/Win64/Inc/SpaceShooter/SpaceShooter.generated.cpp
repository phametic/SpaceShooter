// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SpaceShooter.h"
#include "SpaceShooter.generated.dep.h"
void EmptyLinkFunctionForGeneratedCodeSpaceShooter() {}
	void ASpacyCamera::StaticRegisterNativesASpacyCamera()
	{
	}
	IMPLEMENT_CLASS(ASpacyCamera, 2530936582);
	void ABasicEnemy::StaticRegisterNativesABasicEnemy()
	{
	}
	IMPLEMENT_CLASS(ABasicEnemy, 2506064328);
	void AProjectile::StaticRegisterNativesAProjectile()
	{
		FNativeFunctionRegistrar::RegisterFunction(AProjectile::StaticClass(),"Hit",(Native)&AProjectile::execHit);
	}
	IMPLEMENT_CLASS(AProjectile, 3939837463);
	void AShip::StaticRegisterNativesAShip()
	{
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"MoveLeftRight",(Native)&AShip::execMoveLeftRight);
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"MoveUpDown",(Native)&AShip::execMoveUpDown);
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"OnFirePressed",(Native)&AShip::execOnFirePressed);
		FNativeFunctionRegistrar::RegisterFunction(AShip::StaticClass(),"OnFireReleased",(Native)&AShip::execOnFireReleased);
	}
	IMPLEMENT_CLASS(AShip, 339490856);
	void ASpaceShooterGameMode::StaticRegisterNativesASpaceShooterGameMode()
	{
	}
	IMPLEMENT_CLASS(ASpaceShooterGameMode, 3405153599);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_UEngineTypes_FHitResult();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_UObject_FVector();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpacyCamera_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpacyCamera();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ABasicEnemy_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ABasicEnemy();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AProjectile_Hit();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AProjectile_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AProjectile();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_MoveLeftRight();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_MoveUpDown();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_OnFirePressed();
	SPACESHOOTER_API class UFunction* Z_Construct_UFunction_AShip_OnFireReleased();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceShooterGameMode_NoRegister();
	SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceShooterGameMode();
	SPACESHOOTER_API class UPackage* Z_Construct_UPackage_SpaceShooter();
	UClass* Z_Construct_UClass_ASpacyCamera_NoRegister()
	{
		return ASpacyCamera::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpacyCamera()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = ASpacyCamera::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				UProperty* NewProp_CameraComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CameraComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(CameraComponent, ASpacyCamera), 0x00000000004a001d, Z_Construct_UClass_UCameraComponent_NoRegister());
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SpacyCamera.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SpacyCamera.h"));
				MetaData->SetValue(NewProp_CameraComponent, TEXT("Category"), TEXT("CameraActor"));
				MetaData->SetValue(NewProp_CameraComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CameraComponent, TEXT("ModuleRelativePath"), TEXT("SpacyCamera.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpacyCamera(Z_Construct_UClass_ASpacyCamera, TEXT("ASpacyCamera"));
	UClass* Z_Construct_UClass_ABasicEnemy_NoRegister()
	{
		return ABasicEnemy::StaticClass();
	}
	UClass* Z_Construct_UClass_ABasicEnemy()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = ABasicEnemy::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				UProperty* NewProp_MeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MeshComponent, ABasicEnemy), 0x00000000004a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BasicEnemy.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BasicEnemy.h"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("Category"), TEXT("StaticMesh"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("ModuleRelativePath"), TEXT("BasicEnemy.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasicEnemy(Z_Construct_UClass_ABasicEnemy, TEXT("ABasicEnemy"));
	UFunction* Z_Construct_UFunction_AProjectile_Hit()
	{
		struct Projectile_eventHit_Parms
		{
			AActor* SelfActor;
			AActor* TargetActor;
			FVector NormalImpulse;
			FHitResult Hit;
		};
		UClass* OuterClass=Z_Construct_UClass_AProjectile();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Hit"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00840401, 65535, sizeof(Projectile_eventHit_Parms));
			UProperty* NewProp_Hit = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Hit"), RF_Public|RF_Transient|RF_Native) UStructProperty(CPP_PROPERTY_BASE(Hit, Projectile_eventHit_Parms), 0x0000000000000080, Z_Construct_UScriptStruct_UEngineTypes_FHitResult());
			UProperty* NewProp_NormalImpulse = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("NormalImpulse"), RF_Public|RF_Transient|RF_Native) UStructProperty(CPP_PROPERTY_BASE(NormalImpulse, Projectile_eventHit_Parms), 0x0000000000000080, Z_Construct_UScriptStruct_UObject_FVector());
			UProperty* NewProp_TargetActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TargetActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(TargetActor, Projectile_eventHit_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			UProperty* NewProp_SelfActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SelfActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(SelfActor, Projectile_eventHit_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
			MetaData->SetValue(NewProp_Hit, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
			MetaData->SetValue(NewProp_NormalImpulse, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
			MetaData->SetValue(NewProp_TargetActor, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
			MetaData->SetValue(NewProp_SelfActor, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProjectile_NoRegister()
	{
		return AProjectile::StaticClass();
	}
	UClass* Z_Construct_UClass_AProjectile()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = AProjectile::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AProjectile_Hit());

				UProperty* NewProp_MeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MeshComponent, AProjectile), 0x00000000004a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_ColliderComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ColliderComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(ColliderComponent, AProjectile), 0x00000000004a001d, Z_Construct_UClass_USphereComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AProjectile_Hit()); // 2297635872
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Projectile.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("Category"), TEXT("StaticMesh"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("ToolTip"), TEXT("UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Movement)\nTSubobjectPtr<UProjectileMovementComponent> MovementComponent;"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("Category"), TEXT("Collision"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("ModuleRelativePath"), TEXT("Projectile.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProjectile(Z_Construct_UClass_AProjectile, TEXT("AProjectile"));
	UFunction* Z_Construct_UFunction_AShip_MoveLeftRight()
	{
		struct Ship_eventMoveLeftRight_Parms
		{
			float value;
		};
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MoveLeftRight"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535, sizeof(Ship_eventMoveLeftRight_Parms));
			UProperty* NewProp_value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("value"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(value, Ship_eventMoveLeftRight_Parms), 0x0000000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Left & Right movement"));
			MetaData->SetValue(NewProp_value, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AShip_MoveUpDown()
	{
		struct Ship_eventMoveUpDown_Parms
		{
			float value;
		};
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MoveUpDown"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535, sizeof(Ship_eventMoveUpDown_Parms));
			UProperty* NewProp_value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("value"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(value, Ship_eventMoveUpDown_Parms), 0x0000000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Up & Down movement"));
			MetaData->SetValue(NewProp_value, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AShip_OnFirePressed()
	{
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnFirePressed"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AShip_OnFireReleased()
	{
		UClass* OuterClass=Z_Construct_UClass_AShip();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnFireReleased"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
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
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_SpaceShooter();
			OuterClass = AShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AShip_MoveLeftRight());
				OuterClass->LinkChild(Z_Construct_UFunction_AShip_MoveUpDown());
				OuterClass->LinkChild(Z_Construct_UFunction_AShip_OnFirePressed());
				OuterClass->LinkChild(Z_Construct_UFunction_AShip_OnFireReleased());

				UProperty* NewProp_MeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MeshComponent, AShip), 0x00000800004a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_MoveLeftRight()); // 949887137
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_MoveUpDown()); // 4028128031
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_OnFirePressed()); // 735349037
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShip_OnFireReleased()); // 780212354
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Ship.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("Category"), TEXT("StaticMesh"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShip(Z_Construct_UClass_AShip, TEXT("AShip"));
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
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x209002AC;


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
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpaceShooterGameMode(Z_Construct_UClass_ASpaceShooterGameMode, TEXT("ASpaceShooterGameMode"));
	UPackage* Z_Construct_UPackage_SpaceShooter()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/SpaceShooter")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0x41A21B1B;
			Guid.B = 0xE9CC1E09;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);
		}
		return ReturnPackage;
	}
#endif

