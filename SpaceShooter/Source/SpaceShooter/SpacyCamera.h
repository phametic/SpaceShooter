

#pragma once

#include "GameFramework/Actor.h"
#include "SpacyCamera.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API ASpacyCamera : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CameraActor)
		UCameraComponent* CameraComponent;

	void Tick(float DeltaTime) override;
public:
	ASpacyCamera* returnSelf() { return this; }
private:
	void Movement(float DeltaTime);
};
