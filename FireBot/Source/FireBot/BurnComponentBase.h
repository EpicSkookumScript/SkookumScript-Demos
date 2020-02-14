//=======================================================================================
// SkookumScript Plugin for Unreal Engine 4
// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.
//
// Behavior component C++ example 
//
// Author: Markus Breyer
//=======================================================================================

#pragma once

//=======================================================================================
// Includes
//=======================================================================================

#include "SkookumScriptBehaviorComponent.h"
#include "BurnComponentBase.generated.h"

//=======================================================================================
// Global Defines / Macros
//=======================================================================================

//=======================================================================================
// Global Structures
//=======================================================================================

class SkInvokedCoroutine;
class SkInvokedMethod;
class SkInstance;

//---------------------------------------------------------------------------------------
// Customized SkookumScriptBehaviorComponent that exposes C++ SkookumScript routines for use by scripts
UCLASS(classGroup = Scripting, editinlinenew, BlueprintType, meta = (BlueprintSpawnableComponent), hideCategories = (Object, ActorComponent))
class FIREBOT_API UBurnComponentBase : public USkookumScriptBehaviorComponent
{

  GENERATED_UCLASS_BODY()

public:

  // Public Data Members

  /** Is this component active? */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  bool IsBurning;

  // Methods

  /** Start burning */
  UFUNCTION(BlueprintCallable, Category = "SkookumScript")
  void EnableBurn(bool enable = true);

	/** Set socket name for vfx attachment */
	UFUNCTION(BlueprintCallable, Category = "SkookumScript")
	void SetSocketName(FName SocketName) { mSocketName = SocketName; }


  // Register SkookumScript methods and coroutines
  static void register_bindings();

protected:

  // SkookumScript methods and coroutines
  static void mthd_do_stuff(SkInvokedMethod * scope_p, SkInstance ** result_pp);
  static bool coro_coro(SkInvokedCoroutine * scope_p);

  // UActorComponent interface
  virtual void OnRegister() override;
  virtual void InitializeComponent() override;
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type end_play_reason) override;
  virtual void UninitializeComponent() override;
  virtual void OnUnregister() override;

private:

	FName											mSocketName;
	UParticleSystemComponent* mPSComponent;

};  // UBurnComponentBase

