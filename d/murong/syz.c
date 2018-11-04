// syz.c
#include <ansi.h>
inherit ROOM;
string look_view();
void create()
{
         set("short",HIY"赏荷斋"NOR);
         set("long",@long
这里是赏荷斋，两面是墙，一面冲向湖面，在这里你可以欣赏到湖面的
景色(view)。
long);
         set("exits",([
		"west" : __DIR__"cl2",
	]));
	set("item_desc", ([
	"view" : (: look_view :),
]));
	set("objects", ([
	__DIR__"obj/fruit" : 2,
//	__DIR__"npc/ghost" : 1,
]));
        setup();                
}  
string look_view()
{                                              
	string str;
	object room;
	mixed *local;
	local = localtime(time() * 60);	
	room = find_object(__DIR__"boat1");                                              
	if(!(room=find_object(__DIR__"boat1")))
	     room=load_object(__DIR__"boat1");
	if( room->query("busy"))
	str = "湖面上一条小舟在荷花荡里往来穿梭。\n";	                                                  
	else str = "";
        if( local[2] > 6 && local[2] <= 20 )  
        {
        	switch(random(3))
        	{
        		case 0 :
		return HIG"一片一望无际的荷花荡。一眼望去, 满湖荷叶, 菱叶, 芦苇, 茭白, \n"
		"都是一模一样, 兼之荷叶, 菱叶在水面漂浮, 随时一阵风来, 便即\n"
		"变化百端, 就算此刻记得清清楚楚, 霎时间局面便全然不同。\n\n"+str+"\n"NOR;
		break;
                        case 1 :
		return HIG"远远看见水边小居的一角屋檐。两只飞燕从头顶掠过。\n\n"+str+"\n"NOR;
		break;
		
		        case 2 :
		return HIW"湖中偶尔传来几丝歌声，那是湖中的小船上的姑娘在采莲嬉戏。\n\n"+str+"\n"NOR;
		break;
		}
	}
	else
	{	
		return BLU"此刻湖面上漆黑一片，你什么也看不见。\n"NOR;
	}	
}
/* 
void init()
{
	add_action("do_attack", "attack");
	add_action("do_fly", "yue");
}

int do_attack()
{
	int temp_qi;
	int qi;
	object ob;
	object ob1=this_player();

	if (!ob1->query_temp("buster_temp")) return 0;
	if (ob1->query_temp("buster_temp") != 1) 
	return 0; 
	if(ob = present("ghost shadow", this_object()));
	{
	qi = ob1->query("max_qi");
	ob->set("eff_qi",qi);
	ob->set("qi",qi);
	ob1->set("eff_qi",qi);
	ob1->set("qi",qi);
	COMBAT_D->do_attack(ob1, ob, ob1->query_temp("weapon"), 0);
	temp_qi = ob->query_temp("blood") - (qi - ob->query("qi"));
	ob->set_temp("blood",temp_qi);
	ob1->set_temp("buster_temp", 2);
	}
	if (temp_qi < 1) {
		message_vision("$N被击倒了。\n",ob);
		ob1->delete_temp("buster_temp");
	}
	return 1;
}                                   

int do_fly(string arg)
{
	object me;
	me = this_player();
	if( me->is_busy())
		return 0;
	if( me->is_fighting())
		return 0;
	if( !living(me))
		return 0;
	if(!arg)
	{
		message("vision", "$N纵身一越，跳上了房顶。\n", environment(me), ({me}));
		write("你纵身一越，跳上了房顶。\n");
		me->move(__DIR__"roof");
		message("vision", "$N从下面跳上了房顶。\n", environment(me), ({me}));
		return 1;
	}
}*/