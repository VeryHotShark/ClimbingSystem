// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMovementComponent.generated.h"

UENUM(BlueprintType)
namespace ECustomMovementMode
{
	enum Type
	{
		MOVE_Climb UMETA(DisplayName = "Climb Mode")
	};
}
/**
 * 
 */
UCLASS()
class CLIMBINGSYSTEM_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Character Movement: CLimbing", meta=(AllowPrivateAccess = "true"))
	TArray<TEnumAsByte<EObjectTypeQuery>> ClimbableSurfaceTraceTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Character Movement: CLimbing", meta=(AllowPrivateAccess = "true"))
	float ClimbCapsuleTraceRadius = 50.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Character Movement: CLimbing", meta=(AllowPrivateAccess = "true"))
	float ClimbCapsuleTraceHalfHeight = 72.0f;

	TArray<FHitResult> ClimbableSurfacesTracedResults;

	TArray<FHitResult> DoCapsuleTraceMultiObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false, bool bDrawPersistantShapes = false);
	FHitResult DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false, bool bDrawPersistantShapes = false);

	bool TraceClimbableSurfaces();
	FHitResult TraceFromEyeHeight(float TraceDistance, float TraceStartOffset = 0.0f);
	bool CanStartClimbing();

public:
	void ToggleClimbing(bool bEnableClimb);
	bool IsClimbing() const;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
