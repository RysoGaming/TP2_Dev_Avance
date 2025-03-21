#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h" // Inclure pour utiliser UBoxComponent
#include "slowzone.generated.h"

UCLASS()
class TP2_DEV_AVANCE_API Aslowzone : public AActor
{
	GENERATED_BODY()

public:
	// Constructeur
	Aslowzone();

protected:
	// Appelé lorsque le jeu commence ou quand l'acteur est spawné
	virtual void BeginPlay() override;

private:
	// Composant de collision (BoxComponent)
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* BoxCollider;

	// Fonctions pour gérer les collisions
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};