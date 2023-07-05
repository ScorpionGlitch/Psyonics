// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PsyonicCharacterBase.h"
#include "DialogSystem/ActorComponents/DialogComponent.h"
#include "PsyonicPlayer.generated.h"

class UMotionWarpingComponent;
class UAbilitySystemComponent;

UCLASS(config=Game)
class APsyonicPlayer : public APsyonicCharacterBase
{
	GENERATED_BODY()

public:
	APsyonicPlayer(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UDialogComponent> Dialog;

	static FName DialogComponentName;
	
	virtual void BeginPlay() override;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Run Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* RunAction;

	UFUNCTION()
	void DialogStart();

	UFUNCTION()
	void DialogEnd();

	UFUNCTION()
	void SetEnablePlayerControls(bool MovementControls, bool AbilitiesControls, bool CameraControls);

	UPROPERTY()
	bool MovementControlsEnabled = true;

	UPROPERTY()
	bool AbilitiesControlsEnabled = true;

	UPROPERTY()
	bool CameraControlsEnabled = true;

	virtual void Jump() override;
	virtual void StopJumping() override;

	virtual void Run() override;
	virtual void StopRunning() override;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
};

