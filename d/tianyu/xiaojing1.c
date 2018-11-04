// Room: 小径
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径，路两旁绿柳成阴，一处处山
石花木点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，小
径往西北面沿伸。
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "southeast" : __DIR__"xiaojing", 
		"north"  : __DIR__"neitang",
                "south"  : __DIR__"tianxinb1",
                "west"  : __DIR__"xiaojing10",
	]));
	setup();
	replace_program(ROOM);
}
