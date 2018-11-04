// Room: 草地
// Date:

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
你来到了一个草地边。地里的什么草都有,你放眼四望，地
面是绿色。旁边好几个人正在割草，你不敢打扰，站在一旁静
静地看。      
LONG );
        set("exits", ([
                "east" : __DIR__"churoom", 
                ]));
        setup();
}
void init()
{
        object me;
        me=this_player();
        if(me->query_temp("do_job1"))
        {
        remove_call_out("greeting");
        call_out("greeting",0,me);
        }
        add_action("do_chop","chu");
}
void greeting(object me)
{
        if(me->query_temp("do_job1"))
        message_vision("这里还有很多青草,快割些青草去厨房，正等着用呢！"+HIY+"（chu cao）\n"NOR,me);
}
int do_chop(string arg)
{
        object weapon;
        int i;
        i=(int)this_player()->query_temp("do_num");
        if(!this_player()->query_temp("do_job1"))
        return 0;
        if (!arg)
        return 0;
        if(arg!="cao")
        return notify_fail("你要除什么？\n");
        if(!objectp(weapon=this_player()->query_temp("weapon"))
        ||(string)weapon->query("id")!="liandao")
        return notify_fail("你手上没有镰刀，怎么除草?\n");
        if(this_player()->is_busy())
        return notify_fail("你上个动作还没有完成，歇歇在做吧!\n");
        if(this_player()->query("jingli")<30)
        return notify_fail("你太累了，歇歇在做吧!\n");
        if(arg=="cao")
        {
                if(i<1)
                {
                message_vision(RED"$N拿起镰刀用力的除着草，一会已经累得满头大汗了。\n"NOR,this_player());
                message_vision(HIY"只听见旁边的老人说到可以了，$N满意的吁了一口气。\n"NOR,this_player());
                tell_object(this_player(),HIR"快去厨房发草料(fang cao)。\n"NOR);
                destruct(weapon);
                this_player()->delete_temp("do_num");
                this_player()->delete_temp("do_job1");
                this_player()->set_temp("do_over_job1",1);
                return 1;
                }
                else
                {
                message_vision(RED"$N拿起镰刀用力的除着草，一会已经累得满头大汗了。\n"NOR,this_player());
                this_player()->start_busy(random(2));
                this_player()->add("jingli",-random(15));
                this_player()->add_temp("do_num",-1);
                return 1;
                }
         }      
}                       

