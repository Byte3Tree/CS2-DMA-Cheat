#include "Offsets.h"
#include "client_dll.hpp"
#include "offsets.hpp"

using namespace rapidjson;

bool Offset::UpdateOffsets()
{
	std::ifstream offsetsIfstream("offsets.json");
	if (offsetsIfstream.fail())
		return false;
	IStreamWrapper offsetsJsonisw(offsetsIfstream);
	Document offsets;
	offsets.ParseStream<0>(offsetsJsonisw);

	std::ifstream clientIfstream("client_dll.json");
	if (clientIfstream.fail())
		return false;
	IStreamWrapper clientisw(clientIfstream);
	Document client;
	client.ParseStream<0>(clientisw);

	Offset::EntityList = cs2_dumper::offsets::client_dll::dwEntityList;
	Offset::Matrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
	Offset::ViewAngle = cs2_dumper::offsets::client_dll::dwViewAngles;
	Offset::LocalPlayerController = cs2_dumper::offsets::client_dll::dwLocalPlayerController;
	Offset::LocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
	Offset::ForceJump = 0;
	Offset::GlobalVars = cs2_dumper::offsets::client_dll::dwGlobalVars;


	Offset::Health = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iHealth;
	Offset::TeamID = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iTeamNum;
	Offset::IsAlive = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bPawnIsAlive;
	Offset::PlayerPawn = cs2_dumper::schemas::client_dll::CCSPlayerController::m_hPlayerPawn;
	Offset::iszPlayerName = cs2_dumper::schemas::client_dll::CBasePlayerController::m_iszPlayerName;


	Offset::Pos = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_vOldOrigin;
	Offset::MaxHealth = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iMaxHealth;
	Offset::CurrentHealth = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iHealth;
	Offset::GameSceneNode = cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode;
	Offset::BoneArray = cs2_dumper::schemas::client_dll::CPlayer_CameraServices::m_fOverrideFogEnd;
	Offset::angEyeAngles = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_angEyeAngles;
	Offset::vecLastClipCameraPos = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_vecLastClipCameraPos;
	Offset::pClippingWeapon = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_pClippingWeapon;
	Offset::iShotsFired = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_iShotsFired;
	Offset::flFlashDuration = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_flFlashDuration;
	Offset::aimPunchAngle = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_aimPunchAngle;
	Offset::aimPunchCache = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_aimPunchCache;
	Offset::iIDEntIndex = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_iIDEntIndex;
	Offset::iTeamNum = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iTeamNum;
	Offset::CameraServices = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pCameraServices;
	Offset::iFovStart = cs2_dumper::schemas::client_dll::CCSPlayerBase_CameraServices::m_iFOVStart;
	Offset::fFlags = cs2_dumper::schemas::client_dll::C_BaseEntity::m_fFlags;
	int m_entitySpottedState = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_entitySpottedState;
	int m_bSpottedByMask = cs2_dumper::schemas::client_dll::EntitySpottedState_t::m_bSpottedByMask;

	//Offset::EntityList = offsets["client_dll"]["data"]["dwEntityList"]["value"].GetUint64();
	//Offset::Matrix = offsets["client_dll"]["data"]["dwViewMatrix"]["value"].GetUint64();
	//Offset::ViewAngle = offsets["client_dll"]["data"]["dwViewAngles"]["value"].GetUint64();
	//Offset::LocalPlayerController = offsets["client_dll"]["data"]["dwLocalPlayerController"]["value"].GetUint64();
	//Offset::LocalPlayerPawn = offsets["client_dll"]["data"]["dwLocalPlayerPawn"]["value"].GetUint64();
	//Offset::ForceJump = offsets["client_dll"]["data"]["dwForceJump"]["value"].GetUint64();
	//Offset::GlobalVars = offsets["client_dll"]["data"]["dwGlobalVars"]["value"].GetUint64();
	//
	//Offset::Health = client["C_BaseEntity"]["data"]["m_iHealth"]["value"].GetUint64();
	//Offset::TeamID = client["C_BaseEntity"]["data"]["m_iTeamNum"]["value"].GetUint64();
	//Offset::IsAlive = client["CCSPlayerController"]["data"]["m_bPawnIsAlive"]["value"].GetUint64();
	//Offset::PlayerPawn = client["CCSPlayerController"]["data"]["m_hPlayerPawn"]["value"].GetUint64();
	//Offset::iszPlayerName = client["CBasePlayerController"]["data"]["m_iszPlayerName"]["value"].GetUint64();
	//
	//Offset::Pos = client["C_BasePlayerPawn"]["data"]["m_vOldOrigin"]["value"].GetUint64();
	//Offset::MaxHealth = client["C_BaseEntity"]["data"]["m_iMaxHealth"]["value"].GetUint64();
	//Offset::CurrentHealth = client["C_BaseEntity"]["data"]["m_iHealth"]["value"].GetUint64();
	//Offset::GameSceneNode = client["C_BaseEntity"]["data"]["m_pGameSceneNode"]["value"].GetUint64();
	//Offset::BoneArray = client["CPlayer_CameraServices"]["data"]["m_fOverrideFogEnd"]["value"].GetUint64();
	//Offset::angEyeAngles = client["C_CSPlayerPawnBase"]["data"]["m_angEyeAngles"]["value"].GetUint64();
	//Offset::vecLastClipCameraPos = client["C_CSPlayerPawnBase"]["data"]["m_vecLastClipCameraPos"]["value"].GetUint64();
	//Offset::pClippingWeapon = client["C_CSPlayerPawnBase"]["data"]["m_pClippingWeapon"]["value"].GetUint64();
	//Offset::iShotsFired = client["C_CSPlayerPawnBase"]["data"]["m_iShotsFired"]["value"].GetUint64();
	//Offset::flFlashDuration = client["C_CSPlayerPawnBase"]["data"]["m_flFlashDuration"]["value"].GetUint64();
	//Offset::aimPunchAngle = client["C_CSPlayerPawn"]["data"]["m_aimPunchAngle"]["value"].GetUint64();
	//Offset::aimPunchCache = client["C_CSPlayerPawn"]["data"]["m_aimPunchCache"]["value"].GetUint64();
	//Offset::iIDEntIndex = client["C_CSPlayerPawnBase"]["data"]["m_iIDEntIndex"]["value"].GetUint64();
	//Offset::iTeamNum = client["C_BaseEntity"]["data"]["m_iTeamNum"]["value"].GetUint64();
	//Offset::CameraServices = client["C_BasePlayerPawn"]["data"]["m_pCameraServices"]["value"].GetUint64();
	//Offset::iFovStart = client["CCSPlayerBase_CameraServices"]["data"]["m_iFOVStart"]["value"].GetUint64();
	//Offset::fFlags = client["C_BaseEntity"]["data"]["m_fFlags"]["value"].GetUint64();
	//int m_entitySpottedState = client["C_CSPlayerPawnBase"]["data"]["m_entitySpottedState"]["value"].GetUint64();
	//int m_bSpottedByMask = client["EntitySpottedState_t"]["data"]["m_bSpottedByMask"]["value"].GetUint64();

	Offset::bSpottedByMask = m_entitySpottedState + m_bSpottedByMask;

	clientIfstream.close();
	offsetsIfstream.close();

	return true;
}