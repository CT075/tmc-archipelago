@ Cloud Tops NPC4E at first Mysterious Cloud
@ Reponsible for Kinstone cutscenes
SCRIPT_START script_Npc4EFirstCloud
	BeginBlock
	SetAnimationState 0x0004
	DoPostScriptAction 0x000b
	DoPostScriptAction 0x0008
	Call sub_0806DAAC
	JumpIf script_0800D6AE
	Call sub_0806DAD0
	CallWithArg sub_0806DA04, 0x00000002
	EndBlock
script_0800D636:
	_0807EA4C
	_0807E9F0
	Call sub_0806DAAC
	JumpIf script_0800D650
	Call EnablePauseMenu
	EnablePlayerControl
	Jump script_0800D636
script_0800D650:
	SetPlayerIdle
	Call DisablePauseMenuAndPutAwayItems
	Call sub_0807FBC4
	Call sub_0807FBA0
	SetEntitySpeed 0x0700
	SetScrollSpeed 7
	CameraTargetEntity
	_0807EDD4 0x01e8, 0x01b8
	Wait 0x003c
	Call sub_0806DAE8
	Wait 0x0078
	Call sub_0806DB44
	JumpIfNot script_Npc4EKinstoneFused
	LoadRoomEntityList gUnk_080DD730
	DoPostScriptAction 0x0006
SCRIPT_END
