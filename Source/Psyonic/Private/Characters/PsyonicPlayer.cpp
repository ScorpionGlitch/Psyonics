// Copyright Epic Games, Inc. All Rights Reserved.

#include "Public/Characters/PsyonicPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

FName APsyonicPlayer::DialogComponentName(TEXT("Dialog"));

APsyonicPlayer::APsyonicPlayer(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	Dialog = CreateDefaultSubobject<UDialogComponent>(APsyonicPlayer::DialogComponentName);
}

void APsyonicPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	Dialog->OnDialogStart.AddDynamic(this, &APsyonicPlayer::DialogStart);
	Dialog->OnDialogEnd.AddDynamic(this, &APsyonicPlayer::DialogEnd);
}

//////////////////////////////////////////////////////////////////////////
// Input

void APsyonicPlayer::DialogStart()
{
	UE_LOG(LogTemp, Warning, TEXT("Dialog Started"))
	SetEnablePlayerControls(false, false, true);
	
	APlayerController* PlayerController = GetController<APlayerController>();
	check(PlayerController);
	if (PlayerController)
	{
		PlayerController->SetInputMode(FInputModeGameAndUI());
	}
}

void APsyonicPlayer::DialogEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Dialog Ended"))
	SetEnablePlayerControls(true, true, true);

	APlayerController* PlayerController = GetController<APlayerController>();
	check(PlayerController);
	if (PlayerController)
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
}

void APsyonicPlayer::SetEnablePlayerControls(bool MovementControls, bool AbilitiesControls, bool CameraControls)
{
	this->MovementControlsEnabled = MovementControls;
	this->AbilitiesControlsEnabled = AbilitiesControls;
	this->CameraControlsEnabled = CameraControls;
}

void APsyonicPlayer::Jump()
{
	if (MovementControlsEnabled)
		Super::Jump();
}

void APsyonicPlayer::StopJumping()
{
	if (MovementControlsEnabled)
		Super::StopJumping();
}

void APsyonicPlayer::Run()
{
	if (MovementControlsEnabled)
		Super::Run();
}

void APsyonicPlayer::StopRunning()
{
	if (MovementControlsEnabled)
		Super::StopRunning();
}

void APsyonicPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APsyonicPlayer::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APsyonicPlayer::StopJumping);

		//Running
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &APsyonicPlayer::Run);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &APsyonicPlayer::StopRunning);
		
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APsyonicPlayer::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APsyonicPlayer::Look);
	}

}

void APsyonicPlayer::Move(const FInputActionValue& Value)
{
	if (MovementControlsEnabled)
	{
		// input is a Vector2D
		const FVector2D MovementVector = Value.Get<FVector2D>();

		if (Controller != nullptr)
		{
			// find out which way is forward
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
			// get right vector 
			const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			// add movement 
			AddMovementInput(ForwardDirection, MovementVector.Y);
			AddMovementInput(RightDirection, MovementVector.X);
		}
	}
}

void APsyonicPlayer::Look(const FInputActionValue& Value)
{
	if (CameraControlsEnabled)
	{
		// input is a Vector2D
		const FVector2D LookAxisVector = Value.Get<FVector2D>();

		if (Controller != nullptr)
		{
			// add yaw and pitch input to controller
			AddControllerYawInput(LookAxisVector.X);
			AddControllerPitchInput(LookAxisVector.Y);
		}
	}
}