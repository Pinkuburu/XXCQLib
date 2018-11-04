// hb1.c 

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"湖边"NOR);
         set("long", 
"俗话说："+BLINK HIC+"上有天堂, 下有苏杭"+NOR+"。这里正是大大有名的"+BLINK HIM+"太湖"+NOR+"。湖面绿波上\n"
"漂着一叶叶的"+BLINK HIW+"小舟"+NOR+", 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的耳中。\n"
);
       set("outdoors","姑苏慕容");
       set("exits", ([
           "west" : __DIR__"hb",
           "east" : __DIR__"hb2",
]));
       setup();
}
void init()
{
	object me = this_player();
	int luck = (int)me->query_temp("mrb_meet");
	me->add("jingli", -10);
	if( (int)me->query("mrb_fail", 1) < 5 ) {
        if( me->query("combat_exp") > 300000
         && me->query("family/generation") == 3
         && me->query("family/family_name") == "姑苏慕容" 
         && me->query("jifen")
         && me->query("ketou")
         && !me->query("marry")
         && luck < 1
         && !me->query("meet_mrb")
         && random(5) < 2)
         {
         	write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n");
         	me->set_temp("mrb_meet", 1);
         }   
         
        if (luck >= 1) 
        {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n"); 
          me->add_temp("mrb_meet", 1); 
        }
    }
}