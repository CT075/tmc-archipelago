@ Player after turning Zelda when stones fall
SCRIPT_START script_PlayerStonesFall
	EndBlock
	SetAnimationState 0x0004
	DoPostScriptAction 0x0000
	CallWithArg SetPlayerAnimation2, 0x000003c5
	Call WaitForPlayerAnim
	SetSyncFlag 0x00000004
	Call SetPlayerActionNormal
SCRIPT_END
