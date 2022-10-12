#define OFFSET_UWORLD			            0xDF0FE00
#define OFFSET_FNAMEPOOL                    0xDF42880
#define OFFSET_PERISTANT_LEVEL              0x30       // UWorld->PersistentLevel<ULevel>
#define OFFSET_GAMEINSTANCE                 0x1a8      // UWorld->OwningGameInstance<UGameInstance>
#define OFFSET_LOCALPLAYERS                 0x38       // UGameInstance->LocalPlayers<TArray<ULocalPlayer*>>
#define OFFSET_PLAYERCONTROLLER             0x30       // UPlayer->PlayerController<APlayerController>
#define OFFSET_LOCALPAWN                    0x328      // APlayerController->AcknowledgedPawn<APawn>
#define OFFSET_ROOT_COMPONENT               0x190      // AActor->RootComponent<USceneComponent>       
#define OFFSET_PLAYER_CAMERA_MANAGER        0x338      // APlayerController->PlayerCameraManager<APlayerCameraManager>
#define OFFSET_PLAYER_STATE                 0x2a8      // APawn->PlayerState<APlayerState>
#define OFFSET_TEAM_INDEX                   0x1048     // AFortPlayerStateAthena->TeamIndex<char>
#define OFFSET_ACTOR_COUNT                  0xA0
#define OFFSET_AACTORS                      0x98             
#define OFFSET_REVIVE_DBNO_TIME             0x4170     // AFortPlayerPawnAthena->ReviveFromDBNOTime<float>
#define OFFSET_ATTACH_PARENT                0xb0       // AFortPlayerPawn->USceneComponent->AttachParent<USceneComponent>
#define OFFSET_CURRENTVEHICLE               0x2290     // AFortPlayerPawn->CurrentVehicle<Aactor>
#define OFFSET_RELATIVE_LOCATION            0x128      // USceneComponent->RelativeLocation<FVector>
#define OFFSET_LEVELS                       0x160      // UWorld->Levels<TArray<ULevel*>>
#define OFFSET_FS_ACCURACY_WAIT_TIME        0x1380     // AFortWeaponRanged->FirstShotAccuracyMinWaitTime<float>
#define OFFSET_CURRENT_WEAPON               0x858      // AFortPawn->CurrentWeapon<AFortWeapon>
