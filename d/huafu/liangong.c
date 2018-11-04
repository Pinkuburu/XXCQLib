// liangong.c 练功房
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","练功房");
        set("long",
"这里是花府的练功房，地面铺者厚实的青砖，墙上（wall）隐约有一
些图案，发梦二党的弟子多在这里练功。这里是发梦二党传授弟子武功的
场所。东边是弟子休息室。\n"
	);
	set("valid_startroom",1);
	set("item_desc",([
		"wall" : "好象画着一些挥拳舞腿的小人。\n",
	]));
	set("exits",([
		"west" : __DIR__"zoulang4",
		"south" : __DIR__"liangong2",
		"east" : __DIR__"xiuxishi",
	]));
	setup();
}

void init()
{
	add_action("do_think","think");
}

int do_think(string arg)
{
     object me=this_player();
	int c_skill1,c_skill;
	
	if (arg!="wall") return 0;
        c_skill=(int)me->query_skill("cuff", 1);
        c_skill1=(int)me->query_skill("literate", 1);
	if (c_skill1<10)
		return notify_fail("你的知识太少了,还看不懂上面的东西。\n");
        if (me->query("jingli")<20)
        {
         tell_object(me,"你太累了，现在无法领悟石壁内容。\n");
                return 1; 
        }
        if (c_skill>30)
        {
         tell_object(me,"你觉得石壁内容太肤浅了。\n");
                return 1; 
        }
        
         tell_object(me,"你面对着石壁静思良久，对基本拳术似有所悟。\n");
        me->improve_skill("cuff", random(10*me->query("int")));
         if (me->query("id")!="love")
       me->receive_damage("qi", 10);
        return 1;
}
