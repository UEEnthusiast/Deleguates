#include "ListenerActor.h"

#include "MasterActor.h"
#include "Net/UnrealNetwork.h"

void AListenerActor::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    if (TargetActor)
    {
        TargetActor->OnBooleanValueChanged.AddDynamic(this, &AListenerActor::OnBooleanValueChanged);
    }
}

void AListenerActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AListenerActor, bShouldDestroy);
}

void AListenerActor::OnBooleanValueChanged()
{
    if (IsValid(this))
    {
        bShouldDestroy = true;
        Destroy();
    }
}
