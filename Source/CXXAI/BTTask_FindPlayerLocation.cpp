// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPlayerLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

UBTTask_FindPlayerLocation::UBTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer) : UBTTask_BlackboardBase(ObjectInitializer)
{
    NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
    {
        auto const PlayerLocation = Player->GetActorLocation();
        if (SearchRadius)
        {
            FNavLocation Loc;
            if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
            {
                if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, Loc))
                {
                    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
                    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
                    return EBTNodeResult::Succeeded;
                }
            }
        }
        else
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
            FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
            return EBTNodeResult::Succeeded;
        }
    }
    return EBTNodeResult::Failed;
}
