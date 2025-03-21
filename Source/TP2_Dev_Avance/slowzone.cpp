#include "slowzone.h"
#include "TP2_Dev_AvanceCharacter.h" 
#include "GameplayTagContainer.h"   

Aslowzone::Aslowzone()
{
    PrimaryActorTick.bCanEverTick = false;

    // Création du BoxComponent
    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
    RootComponent = BoxCollider;
    BoxCollider->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));

    // Configuration des collisions
    BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    BoxCollider->SetCollisionResponseToAllChannels(ECR_Ignore);
    BoxCollider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void Aslowzone::BeginPlay()
{
    Super::BeginPlay();

    if (BoxCollider)
    {
        BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &Aslowzone::OnOverlapBegin);
        BoxCollider->OnComponentEndOverlap.AddDynamic(this, &Aslowzone::OnOverlapEnd);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("BoxCollider is null in Aslowzone!"));
    }
}

void Aslowzone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this && OtherComp)
    {
        // Cast vers ATP2_Dev_AvanceCharacter
        if (ATP2_Dev_AvanceCharacter* Character = Cast<ATP2_Dev_AvanceCharacter>(OtherActor))
        {
            FGameplayTag SlowdownTag = FGameplayTag::RequestGameplayTag(FName("Gameplay.Debuff.Slowdown"));
            if (SlowdownTag.IsValid())
            {
                Character->GameplayTags.AddTag(SlowdownTag); // Ajout du tag
            }
        }
    }
}

void Aslowzone::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor != this && OtherComp)
    {
        // Cast vers ATP2_Dev_AvanceCharacter
        if (ATP2_Dev_AvanceCharacter* Character = Cast<ATP2_Dev_AvanceCharacter>(OtherActor))
        {
            FGameplayTag SlowdownTag = FGameplayTag::RequestGameplayTag(FName("Gameplay.Debuff.Slowdown"));
            if (SlowdownTag.IsValid())
            {
                Character->GameplayTags.RemoveTag(SlowdownTag); // Retrait du tag
            }
        }
    }
}