uint64_t uWorld = 0xE11FDC8;//0x190
uint64_t game_instance = 0x1b8;//0x190
uint64_t local_players = 0x38;
uint64_t player_controller = 0x30;
uint64_t acknowledged_pawn = 0x330; //mb 0x2A8
uint64_t levels = 0x160;
uint64_t persistent_level = 0x30;
uint64_t player_camera_manager = 0x328;
uint64_t aactors = 0x98;
uint64_t actor_count = 0xA0;

//pawn
uint64_t revivefrom_dbno = 0x3FC8;
uint64_t mesh = 0x310; //mb 288
uint64_t relative_loc = 0x128;
uint64_t player_state = 0x2B8;
uint64_t team_index = 0x10E8;
uint64_t root_component = 0x190;

CamewaDescwipsion UndetectedCamera(__int64 a1)
{
__int64 v1;
//__int64 v6;
//__int64 v7;
//__int64 v8;

v1 = sexxx::RPM<__int64>(LocalPlayers + 0xD0);
__int64 v9 = sexxx::RPM<__int64>(v1 + 0x10);


VirtualCamera.FieldOfView = 80.f / (sexxx::RPM<double>(v9 + 0x620) / 1.19f);


VirtualCamera.Rotation.x = sexxx::RPM<double>(v9 + 0x870);
VirtualCamera.Rotation.y = sexxx::RPM<double>(a1 + 0x148);

//v6 = sexxx::RPM<__int64>(LocalPlayers + 0x70);
//v7 = sexxx::RPM<__int64>(v6 + 0x98);
//v8 = sexxx::RPM<__int64>(v7 + 0xF8);

uint64_t FGC_Pointerloc = sexxx::RPM<uint64_t>(Uworld + 0x100);
VirtualCamera.Location = sexxx::RPM<Vector3>(FGC_Pointerloc);


return VirtualCamera;
}

char* v2 = buff; // rdi
int v4; // edx
__int64 result = nameLength; // rax
__int64 v6; // r8
unsigned int v7; // edx

v4 = 22;

if (result)
{
v6 = (unsigned int)result;
do
{
v7 = v4 + 0xB0F1;
*v2 = v7 + ~*v2;
result = v7 << 8;
++v2;
v4 = result | (v7 >> 8);
--v6;
} while (v6);

Also for linora namespace StaticOffsets {
uintptr_t OwningGameInstance = 0x1b8;
uintptr_t LocalPlayers = 0x38;
uintptr_t PlayerController = 0x30;
uintptr_t PlayerCameraManager = 0x2C0;
uintptr_t AcknowledgedPawn = 0x328;
uintptr_t PrimaryPickupItemEntry = 0x2F8;
uintptr_t ItemDefinition = 0x18;
uintptr_t DisplayName = 0xFA8;
uintptr_t Tier = 0x74;
uintptr_t WeaponData = 0x3D8;
uintptr_t LastFireTime = 0x9E4;
uintptr_t LastFireTimeVerified = 0x9E8;
uintptr_t LastFireAbilityTime = 0x1238;
uintptr_t CurrentWeapon = 0x790;
uintptr_t bADSWhileNotOnGround = 0x3E51;

uintptr_t Levels = 0x148;
uintptr_t PersistentLevel = 0x30;
uintptr_t AActors = 0x98;
uintptr_t ActorCount = 0xA0;

uintptr_t RootComponent = 0x190;
uintptr_t FireStartLoc = 0x8B8;
uintptr_t RelativeLocation = 0x128;
uintptr_t RelativeRotation = 0x128;
uintptr_t PlayerState = 0x2a8;
uintptr_t Mesh = 0x310;
uintptr_t TeamIndex = 0x1098;
}
