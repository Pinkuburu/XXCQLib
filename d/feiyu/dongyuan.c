//Room:dongyuan.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create ()
{
        set ("short", "东院");
        set ("long", @LONG
这里是飞鱼山庄的东院，一条青石小路铺在脚下，路的南面是一个圆
形的拱门，从拱门可以看到总管房，路在这里拐了一个小弯，转向北方，
再向北,走过小径，就是女弟子的休息室了。西面隐约传来了练武的吆喝
声。
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"xiaojing",
		"south" : __DIR__"zongguanfang",
	       "west" :__DIR__"eroad",
         ]));

       setup();
	replace_program(ROOM);
}