// fotang.c 佛堂
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","佛堂");
	set("long",
	"府内有多位女眷，因为丈夫是江湖中人，不免每日祈求能平安相聚，
温梦成便在这里建了个小佛堂，终日香烟缭绕。一尊观音佛像端坐在莲花
台上，天天接受着信徒的虔诚膜拜。你也可以在这里跪拜（kneel）消除
自己的杀气。\n"NOR
     	);
     	set("valid_startroom",1);
	set("no_fight",1);
	set("exits",([
     		"west" : __DIR__"huayuan",
     	]));
     	setup();
}

void init()
{
        add_action("do_kneel","kneel");
}

int do_kneel(string arg)
{
        object me;
        me=this_player();
        if (arg)
         return notify_fail(CYN"你只要跪地膜拜（kneel）就行了。\n"NOR);
       if ( (me->query("kill"))==0 ) 
            return notify_fail(YEL"你毫无杀气，何须吃斋念佛？\n"NOR);
	me->clean_up_enemy();
	me->set("kill",0);
   me->remove_all_killer();
	message("channel:chat",
		HIY"【重新做人】"+me->query("name")+"决定改过自新，大家都决定与他尽释前嫌。\n"NOR,users());
        return 1;
}

