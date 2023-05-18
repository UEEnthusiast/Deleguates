#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ListenerActor.generated.h"

class AMasterActor; // class forwarding

UCLASS()
class UEENTHUSIAST_API AListenerActor : public AActor
{
	GENERATED_BODY()

public:
    AListenerActor() = default;

    UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
    AMasterActor* TargetActor = nullptr;

protected:
    virtual void PostInitializeComponents() override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnBooleanValueChanged();


    UPROPERTY(Replicated)
    bool bShouldDestroy;
};
