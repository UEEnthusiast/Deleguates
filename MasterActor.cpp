#include "MasterActor.h"

#include "Net/UnrealNetwork.h"

void AMasterActor::SetBooleanValue(const bool booleanValue)
{
    if (booleanValue != bBooleanValue)
    {
        bBooleanValue = booleanValue;
        OnBooleanValueChanged.Broadcast();
    }
}

void AMasterActor::BeginPlay()
{
    StartAsyncTask();
}

void AMasterActor::StartAsyncTask()
{
    (new FAutoDeleteAsyncTask<FMyAsyncTask>(this))->StartSynchronousTask();
}

void AMasterActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AMasterActor, bBooleanValue);
}
