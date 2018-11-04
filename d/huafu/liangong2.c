// liangong2.c 练功房
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","练功房");
        set("long",
"这里是花府的练功房，地面铺者厚实的青砖，墙上（wall）隐约有一
些图案，发梦二党的弟子多在这里练功。这里也是发梦二党传授弟子武功
的场所。南面飘来一阵阵饭菜的香味。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"chanting",
		"north" : __DIR__"liangong",
	]));
	set("item_desc",([
		"wall" : "墙上画着一些对打的小人。\n",
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
	c_skill=(int)me->query_skill("parry", 1);
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
        
         tell_object(me,"你面对着石壁静思良久，对拆招泄力似有所悟。\n");
        me->improve_skill("parry", random(10*me->query("int")));
         if (me->query("id")!="love")
       me->receive_damage("qi", 10);
        return 1;
}
