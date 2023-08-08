// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/Enums/PsyonicAbilityID.h"
#include "PsyonicCharacterBase.generated.h"

class UMotionWarpingComponent;
class UAbilitySystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDiedDelegate, APsyonicCharacterBase*, character);

UCLASS(config=Game)
class PSYONIC_API APsyonicCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	APsyonicCharacterBase(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable, Category="Psyonic|Character")
	FCharacterDiedDelegate OnCharacterDied;

	//~ Begin IAbilitySystemInterface
	/** Returns our Ability System Component. */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/** Ability System Component. Required to use Gameplay Attributes and Gameplay Abilities. */
	//~ End IAbilitySystemInterface

	UFUNCTION(BlueprintCallable, Category="Psyonic|Character")
	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category="Psyonic|Character")
	virtual int32 GetAbilityLevel(PsyonicAbilityID AbilityID) const;

	virtual void RemoveCharacterAbilities();











	
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UMotionWarpingComponent> MotionWarping;
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	static FName MotionWarpingComponentName;

	

	

	

	

	virtual void Die();

	UFUNCTION(BlueprintCallable, Category="Psyonic|Character")
	virtual void FinishDying();

	UFUNCTION(BlueprintCallable, Category = "Psyonic|Characater|Attributes")
	int32 GetCharacterLevel() const;


	UFUNCTION(BlueprintCallable, Category="Psyonic|Characater|Attributes")
	float GetHealth() const;
	
	UFUNCTION(BlueprintCallable, Category="Psyonic|Characater|Attributes")
	float GetMaxHealth() const;
	
	UFUNCTION(BlueprintCallable, Category="Psyonic|Characater|Attributes")
	float GetPsyonic() const;
	
	UFUNCTION(BlueprintCallable, Category="Psyonic|Characater|Attributes")
	float GetMaxPsyonic() const;
	
	/** BEGIN Running functions and variables */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category=Character)
	float WalkingSpeed = 250.0f;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category=Character)
	float RunningSpeed = 500.0f;
	
	UPROPERTY(BlueprintReadOnly, Category=Character)
	bool bRunning = false;
	
	void Run();
	void StopRunning();
	/** End Running functions and variables */

	
	
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TWeakObjectPtr<class UPsyonicAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UPsyonicAttributeSetBase> AttributeSetBase;
	
protected:
	
	
	// To add mapping context
	virtual void BeginPlay() override;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveOnDeathTag;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Psyonic|Character")
	FText CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Psyonic|Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Psyonic|Abilities")
	TArray<TSubclassOf<class UPsyonicGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Psyonic|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Psyonic|Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	virtual void AddCharacterAbilities();

	virtual void InitializeAttributes();

	virtual void AddStartupEffects();

	virtual void SetHealth(float Health);
	virtual void SetMaxHealth(float MaxHealth);
	virtual void SetPsyonic(float Psyonic);
	virtual void SetMaxPsyonic(float MaxPsyonic);
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

