// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef SPACESHOOTER_Ship_generated_h
#error "Ship.generated.h already included, missing '#pragma once' in Ship.h"
#endif
#define SPACESHOOTER_Ship_generated_h

class AActor;
class UPrimitiveComponent;
struct FHitResult;
#define AShip_EVENTPARMS
#define AShip_RPC_WRAPPERS \
 \
 \
	DECLARE_FUNCTION(execOnFireReleased) \
	{ \
		P_FINISH; \
		this->OnFireReleased(); \
	} \
 \
 \
	DECLARE_FUNCTION(execOnFirePressed) \
	{ \
		P_FINISH; \
		this->OnFirePressed(); \
	} \
 \
 \
	DECLARE_FUNCTION(execMoveLeftRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,value); \
		P_FINISH; \
		this->MoveLeftRight(value); \
	} \
 \
 \
	DECLARE_FUNCTION(execMoveUpDown) \
	{ \
		P_GET_PROPERTY(UFloatProperty,value); \
		P_FINISH; \
		this->MoveUpDown(value); \
	} \
 \
 \
	DECLARE_FUNCTION(execHit) \
	{ \
		P_GET_OBJECT(AActor,TargetActor); \
		P_GET_OBJECT(UPrimitiveComponent,TargetComp); \
		P_GET_PROPERTY(UIntProperty,TargetByIndex); \
		P_GET_UBOOL(bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Out_SweepResult); \
		P_FINISH; \
		this->Hit(TargetActor,TargetComp,TargetByIndex,bFromSweep,Out_SweepResult); \
	}


#define AShip_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	} \
 \
 \
	DECLARE_FUNCTION(execOnFireReleased) \
	{ \
		P_FINISH; \
		this->OnFireReleased(); \
	} \
 \
 \
	DECLARE_FUNCTION(execOnFirePressed) \
	{ \
		P_FINISH; \
		this->OnFirePressed(); \
	} \
 \
 \
	DECLARE_FUNCTION(execMoveLeftRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,value); \
		P_FINISH; \
		this->MoveLeftRight(value); \
	} \
 \
 \
	DECLARE_FUNCTION(execMoveUpDown) \
	{ \
		P_GET_PROPERTY(UFloatProperty,value); \
		P_FINISH; \
		this->MoveUpDown(value); \
	} \
 \
 \
	DECLARE_FUNCTION(execHit) \
	{ \
		P_GET_OBJECT(AActor,TargetActor); \
		P_GET_OBJECT(UPrimitiveComponent,TargetComp); \
		P_GET_PROPERTY(UIntProperty,TargetByIndex); \
		P_GET_UBOOL(bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Out_SweepResult); \
		P_FINISH; \
		this->Hit(TargetActor,TargetComp,TargetByIndex,bFromSweep,Out_SweepResult); \
	}


#define AShip_CALLBACK_WRAPPERS
#define AShip_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAShip(); \
	friend SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip(); \
	public: \
	DECLARE_CLASS(AShip, APawn, COMPILED_IN_FLAGS(0), 0, SpaceShooter, NO_API) \
	DECLARE_SERIALIZER(AShip) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AShip*>(this); }


#define AShip_INCLASS \
	private: \
	static void StaticRegisterNativesAShip(); \
	friend SPACESHOOTER_API class UClass* Z_Construct_UClass_AShip(); \
	public: \
	DECLARE_CLASS(AShip, APawn, COMPILED_IN_FLAGS(0), 0, SpaceShooter, NO_API) \
	DECLARE_SERIALIZER(AShip) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AShip*>(this); }


#define AShip_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShip(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShip) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AShip(const AShip& InCopy); \
public:


#define AShip_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShip(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AShip(const AShip& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShip)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AShip


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AShip_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AShip_RPC_WRAPPERS \
	AShip_CALLBACK_WRAPPERS \
	AShip_INCLASS \
	AShip_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AShip_RPC_WRAPPERS_NO_PURE_DECLS \
	AShip_CALLBACK_WRAPPERS \
	AShip_INCLASS_NO_PURE_DECLS \
	AShip_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class Ship."); \
PRAGMA_POP


