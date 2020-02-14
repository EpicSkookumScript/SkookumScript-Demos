// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "FireBot.h"

// Implementation of generated SkookumScript bindings
#include <SkUEProjectGeneratedBindings.generated.inl> 

#include "BurnComponentBase.h"
#include <SkookumScript/SkBrain.hpp>


class FFireBotModule : public FDefaultGameModuleImpl
  {
  public:

    // IModuleInterface implementations

    virtual void StartupModule() override
      {
      // This is only necessary if you use Sk bindings directly
      // If you use UFUNCTION macros to expose functions, this call is not needed
      SkBrain::register_bind_atomics_func(&UBurnComponentBase::register_bindings);
      }

    virtual void ShutdownModule() override
      {
      // This is only necessary if you use Sk bindings directly
      // If you use UFUNCTION macros to expose functions, this call is not needed
      SkBrain::unregister_bind_atomics_func(&UBurnComponentBase::register_bindings);
      }

  };

IMPLEMENT_PRIMARY_GAME_MODULE(FFireBotModule, FireBot, "FireBot" );

