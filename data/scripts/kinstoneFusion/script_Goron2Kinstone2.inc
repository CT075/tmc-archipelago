@ 2nd Goron during Kinstone cutscene for 2nd Goron
SCRIPT_START script_Goron2Kinstone2
	BeginBlock
	SetAnimationState 0x0000
	SetAnimation 0x0000
	DoPostScriptAction 0x0008
	SetEntitySpeed 0x0080
	Call SetPriorityMessage
	EndBlock
	WaitForSyncFlagAndClear 0x00000002
	DoPostScriptAction 0x0007
	CallWithArg sub_0807F4F8, 0x00000270
	Wait 0x001e
	MessageNoOverlap TEXT_KINSTONE, 0x0b
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	SetEntitySpeed 0x0100
	_0807EDD4 0x0088, 0x0228
	Wait 0x000f
	SetSyncFlag 0x00000004
	DoPostScriptAction 0x000f
	SetAnimation 0x0008
	Wait 0x00b4
	CallWithArg sub_0804BF38, 0x00000000
	Wait 0x00b4
	CallWithArg sub_0804BF38, 0x00000003
	SetAnimationState 0x0004
	SetAnimation 0x0000
	Wait 0x003c
	SetAnimationState 0x0006
	SetSyncFlag 0x00000004
	SetEntitySpeed 0x0080
	_0807EEF4 0x0000, -32
	Call sub_08054968
SCRIPT_END
