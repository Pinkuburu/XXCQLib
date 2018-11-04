// Room: 厨房
// Date: 
#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
         set("short","厨房");
         set("long",@long
这是浣花剑派的厨房，浓浓的油烟呛得你没法呼吸，只看到一
位厨子在忙个不停，一会炒，一会切。房间的另一边，有个放
草料的地方。北面是用餐的地方。   
long);
         set("exits",([
         "west" : __DIR__"caoroom",
         "north" : __DIR__"eatroom",
         ]));
         set("no_fight",1);
           set("objects", ([
           __DIR__"npc/chushi" :1,
         ]));
         setup();
}
void init()
{
         add_action("do_add","fang");
}       
int do_add(string arg)
{
         object me;
         me=this_player();
         if(!arg||arg=="")
         return 0;
         if(!me->query_temp("do_over_job1"))
         return 0;
         if(arg=="chai")
         message_vision(HIW"$N赶忙把除好的草料，放到角落里。\n"NOR,me);
         message_vision(HIW"厨师满意的对$N点了点头,说道“干得不错，休息一会吧！”\n"NOR,me);
         me->add("combat_exp",100+random(30));
         me->add("potential",50+random(30));
         me->delete_temp("do_over_job1");
         return 1;
}        

