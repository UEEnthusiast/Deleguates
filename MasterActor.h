#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/Delegate.h"

#include "MasterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanValueChanged);

UCLASS()
class UEENTHUSIAST_API AMasterActor : public AActor
{
    GENERATED_BODY()

public:
    FBooleanValueChanged OnBooleanValueChanged;

    AMasterActor() = default;

    void SetBooleanValue(const bool booleanValue);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    virtual void BeginPlay() override;

private:
    void StartAsyncTask();

    UPROPERTY(Replicated)
    bool bBooleanValue = true;
};

class FMyAsyncTask : public FNonAbandonableTask
{
public:
    FMyAsyncTask(AMasterActor* masterActor) : MasterActor(masterActor) {}
    FORCEINLINE TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(FMyAsyncTask, STATGROUP_ThreadPoolAsyncTasks); }
    inline void DoWork() { MasterActor->SetBooleanValue(false); }

private:
    AMasterActor* MasterActor;
};
