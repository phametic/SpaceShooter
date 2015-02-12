#pragma once

#include "GameFramework/Character.h"
#include "Ship.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AShip : public ACharacter
{
	GENERATED_UCLASS_BODY()

		virtual void BeginPlay() override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StaticMesh)
	TSubobjectPtr<class UStaticMeshComponent> MeshComponent;
	//Up & Down movement
	UFUNCTION()
		void MoveUpDown(float value);

	//Left & Right movement
	UFUNCTION()
		void MoveLeftRight(float value);
};
