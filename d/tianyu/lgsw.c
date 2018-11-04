// Room: 练功房
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "练功房外");
	set("long", @LONG
天羽派的剑法最重要是个悟字，一般师父都无法言传，需要弟子
门在这里闭观靠自己探索剑法当中的奥秘，因此天羽长辈门特意修建
练功房，为弟子门闭观所用。
LONG );
	set("exits", ([
	        "west" : __DIR__"neitang",
		]));
	set("objects",([
	        __DIR__"npc/dizi" : 1,
	        ]));
	setup();
	replace_program(ROOM);

}
