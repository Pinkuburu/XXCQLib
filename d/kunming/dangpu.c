// Room:/d/kunming/dangpu.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17
inherit SR_DANGPU;
void create()
{
	set("short", "当铺");//这个应该可以由玩家改变
	set("long", @LONG
这是一个为江湖人士开办的当铺，你可以跟官府投标买下来经营它，走江
湖也得考虑考虑赚钱的问题啊！
LONG
	);
	set("exits", ([
		"west" : __DIR__"nanjie1",
	]));
	setup();
	replace_program(SR_DANGPU);
}
