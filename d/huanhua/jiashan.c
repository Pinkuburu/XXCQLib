//changan city

inherit ROOM;

void create ()
{
        set ("short", "假山");
        set ("long", @LONG
这里是七曲廊和九曲廊交汇的地方，你的西面立着一座一人多高的假
山，假山上长满了绿色的爬山虎，路向假山石中延伸，一直通向浣花剑庐
重地——见天洞。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiantian",
		"north" : __DIR__"qqlang_3",
		"south" : __DIR__"jqlang_3",
	]));

        set("outdoors", "xiao");
        setup();
}