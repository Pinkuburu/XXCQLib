//changan city

inherit ROOM;

void create ()
{
        set ("short", "影壁");
        set ("long", @LONG
走进剑庐，迎面就是这面高高的影壁，丹青色的影壁上用行书题有一
首文天祥的正气歌，那开始斑驳的墙面显出它的古老。绕过它就真正进入
剑庐了，站在这里则完全看不到影壁里面的情景。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"out" : __DIR__"gate",
		"west" : __DIR__"qianroad2",
	]));

        setup();
	replace_program(ROOM);
}