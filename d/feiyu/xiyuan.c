//Room:xiyuan.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create ()
{
        set ("short", "西院");
        set ("long", @LONG
这里是飞鱼山庄的西院，看上去和东院是一样的，路的南面是一条窄
路，远远可以看到一扇紧闭的木门，路在这里拐了一个弯，转向北方，再
向北就是男弟子的休息室了。东面的练武场隐约传来了练武的吆喝声。
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"wxiaojing",
		"south" : __DIR__"zhailu",
	       "east" :__DIR__"xiwuchang",
         ]));

       setup();
	replace_program(ROOM);
}