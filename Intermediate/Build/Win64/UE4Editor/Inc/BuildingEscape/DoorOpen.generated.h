// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BUILDINGESCAPE_DoorOpen_generated_h
#error "DoorOpen.generated.h already included, missing '#pragma once' in DoorOpen.h"
#endif
#define BUILDINGESCAPE_DoorOpen_generated_h

#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_SPARSE_DATA
#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_RPC_WRAPPERS
#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDoorOpen(); \
	friend struct Z_Construct_UClass_UDoorOpen_Statics; \
public: \
	DECLARE_CLASS(UDoorOpen, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BuildingEscape"), NO_API) \
	DECLARE_SERIALIZER(UDoorOpen)


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUDoorOpen(); \
	friend struct Z_Construct_UClass_UDoorOpen_Statics; \
public: \
	DECLARE_CLASS(UDoorOpen, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BuildingEscape"), NO_API) \
	DECLARE_SERIALIZER(UDoorOpen)


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDoorOpen(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDoorOpen) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDoorOpen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDoorOpen); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDoorOpen(UDoorOpen&&); \
	NO_API UDoorOpen(const UDoorOpen&); \
public:


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDoorOpen(UDoorOpen&&); \
	NO_API UDoorOpen(const UDoorOpen&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDoorOpen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDoorOpen); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDoorOpen)


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetYaw() { return STRUCT_OFFSET(UDoorOpen, TargetYaw); } \
	FORCEINLINE static uint32 __PPO__Trigger_Volume() { return STRUCT_OFFSET(UDoorOpen, Trigger_Volume); } \
	FORCEINLINE static uint32 __PPO__DoorCloseDelay() { return STRUCT_OFFSET(UDoorOpen, DoorCloseDelay); } \
	FORCEINLINE static uint32 __PPO__TotalMassToOpen() { return STRUCT_OFFSET(UDoorOpen, TotalMassToOpen); } \
	FORCEINLINE static uint32 __PPO__AudioComponent() { return STRUCT_OFFSET(UDoorOpen, AudioComponent); }


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_11_PROLOG
#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_PRIVATE_PROPERTY_OFFSET \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_SPARSE_DATA \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_RPC_WRAPPERS \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_INCLASS \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_PRIVATE_PROPERTY_OFFSET \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_SPARSE_DATA \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_INCLASS_NO_PURE_DECLS \
	BuildingEscape_Source_BuildingEscape_DoorOpen_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BUILDINGESCAPE_API UClass* StaticClass<class UDoorOpen>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BuildingEscape_Source_BuildingEscape_DoorOpen_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
