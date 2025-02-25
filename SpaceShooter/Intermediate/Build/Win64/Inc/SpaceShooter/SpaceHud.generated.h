// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef SPACESHOOTER_SpaceHud_generated_h
#error "SpaceHud.generated.h already included, missing '#pragma once' in SpaceHud.h"
#endif
#define SPACESHOOTER_SpaceHud_generated_h

#define ASpaceHud_EVENTPARMS
#define ASpaceHud_RPC_WRAPPERS
#define ASpaceHud_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define ASpaceHud_CALLBACK_WRAPPERS
#define ASpaceHud_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesASpaceHud(); \
	friend SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceHud(); \
	public: \
	DECLARE_CLASS(ASpaceHud, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, SpaceShooter, NO_API) \
	DECLARE_SERIALIZER(ASpaceHud) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<ASpaceHud*>(this); }


#define ASpaceHud_INCLASS \
	private: \
	static void StaticRegisterNativesASpaceHud(); \
	friend SPACESHOOTER_API class UClass* Z_Construct_UClass_ASpaceHud(); \
	public: \
	DECLARE_CLASS(ASpaceHud, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, SpaceShooter, NO_API) \
	DECLARE_SERIALIZER(ASpaceHud) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<ASpaceHud*>(this); }


#define ASpaceHud_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpaceHud(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpaceHud) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ASpaceHud(const ASpaceHud& InCopy); \
public:


#define ASpaceHud_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpaceHud(const class FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ASpaceHud(const ASpaceHud& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpaceHud)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME ASpaceHud


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
ASpaceHud_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ASpaceHud_RPC_WRAPPERS \
	ASpaceHud_CALLBACK_WRAPPERS \
	ASpaceHud_INCLASS \
	ASpaceHud_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ASpaceHud_RPC_WRAPPERS_NO_PURE_DECLS \
	ASpaceHud_CALLBACK_WRAPPERS \
	ASpaceHud_INCLASS_NO_PURE_DECLS \
	ASpaceHud_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP


