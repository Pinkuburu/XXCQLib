// muqiao.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",YEL"木桥"NOR);   
         set("long",@long
这是通往湖中小亭的木桥，从这望去湖面碧波荡漾，景色宜人。木桥的
扶手上雕刻着一尊尊小木头狮子，让人爱不释手。木桥往南走能够看到一座
湖中小亭。在木桥下栓着一艘小木船(boat)，显然船的主人不在。
long);   
         set("outdoors","姑苏慕容");  
         set("item_desc", ([
         "boat" : "小船上没有人，你可以(jump)到小船上。\n",
]));     
         set("exits",([
             "west" : __DIR__"houyuan1",            
             "south" : __DIR__"bst",
]));
	 set("objects", ([
	 __DIR__"npc/gongye" : 1,
]));
         setup();
}
void init()
{                                    
	 object boat;
	 boat = find_object(__DIR__"boat1");
	 if(!(boat = find_object(__DIR__"boat1")))
              boat = load_object(__DIR__"boat1");
         if( boat->query("busy")) {
         set("long",@long
这是通往湖中小亭的木桥，从这望去湖面碧波荡漾，景色宜人。木桥的
扶手上雕刻着一尊尊小木头狮子，让人爱不释手。木桥往南走能够看到一座
湖中小亭。
long);                                   
	 }
       	 add_action("do_jump","jump");
}
int do_jump(string arg)
{       
	object boat;
	boat = find_object(__DIR__"boat1");
	if(!living(this_player())) return 0;
	if( this_player()->is_busy()) 
		return notify_fail("你正忙着呢！\n");
	if( this_player()->is_fighting())                       
		return notify_fail("你正忙着呢！\n");	
	if(!(boat = find_object(__DIR__"boat1")))
             boat = load_object(__DIR__"boat1");		
	if( boat->query("busy"))
		return notify_fail("你要往哪里跳？\n");
	if(!arg||arg!="boat")
		return notify_fail("别瞎跳，小心掉进水里了。\n");
	message_vision("$N轻轻的解开绳子，一纵身往船头跳去。\n", this_player());

	this_player()->move(__DIR__"boat1");
	tell_object(this_player(), BLU"你费了好大劲才稳住身子，你吓得赶紧蹲了下来。\n"NOR);
	return 1;
}       

