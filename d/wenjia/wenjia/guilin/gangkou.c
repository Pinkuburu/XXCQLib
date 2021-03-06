// Room: dukou.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

#include <ansi.h>

inherit ROOM;
void init();
int do_shang(string arg);
int arrived(object me,int stage);

string *around_msg = ({
        HIY "一座象鼻一样的山出现在你的视野里，越来越大，那就是著名的象鼻山。\n\n" NOR,
        WHT "江面越来越宽阔，游船顺着漓江向下航行，慢慢的汇入了西江。\n\n" NOR,
        CYN "江水的流动变得非常缓慢，渐渐的前面出现了另一条大江，那是北江。\n\n" NOR,
        HIG "船在两江的汇流处停了下来，慢慢的调转方向，船头竟然转向了北江的上游。\n\n" NOR,
        HIC "江水渐渐的变急了，船向上航行得越来越慢，慢慢的在右手边出现了一排山脉。\n\n" NOR,
        BLU "在连绵的山脉山脚处出现了一个小小的渡口。\n\n" NOR,
});

void create ()
{
        set ("short", "港口");
        set ("long", @LONG
漓江岸上唯一的港口，从这里坐船，经过漓江，来到西江，逆行可以
去到北江。北江上游是著名的南岭山脉，那里是老字号温家的总部。岸边
立着一块木牌(mupai)。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
        set("valid_startroom", 1);

	set("item_desc", ([
		"mupai" : "有客船到南岭山脉，可以上(shang)船。\n",
	]));

        set("exits", ([
                "northeast" : __DIR__"jiangdi1",
        ]));
        setup();
}

void init()
{
	add_action("do_shang", "shang");
}

int do_shang(string arg)
{
        object room,me;
        me=this_player();

        if(!arg || arg!="chuan")
               return notify_fail("你要上什么?\n");
         
        message_vision("$N朝江上的船夫叫道：“喂，雇船呀!”\n", me);

        if( !(room = find_object("/d/guilin/fengfan")) )
		room = load_object("/d/guilin/fengfan");

        message_vision("船夫慢慢的将船靠岸，将一个木板架到岸上。$N走了上船。\n", me);
        me->move("/d/guilin/fengfan");

        call_out("arrived", 5, me,0);

        return 1;
}

int arrived(object me,int stage)
{
        object room;

        tell_object(me, around_msg[stage]);
        if( ++stage < sizeof(around_msg) ) {
                call_out( "arrived", 5, me, stage );
                return 1;
        } else
                me->reincarnate();

        if( room = find_object("/d/guilin/fengfan") )
        {
                me->move("/d/wenjia/gangkou");
                message_vision("大船慢慢的驶进岸边，船夫架了一块木板到岸上，$N走了下来。\n", me);
                return 1;
        }

}
