//chufang

#include <ansi.h>
#include <room.h>
inherit ROOM;
int delete_busy();

void create()
{
        set("short","厨房");
        set("long", @LONG
LONG);
        set("valid_startroom",1);
        set("exits", ([
                "west" : __DIR__"qingyunge",
                  "north" : __DIR__"wuqifang",
        ]));
        set("no_fight", 1);
        set("area", "恒山");
        setup();
}

void init()
{
        add_action("do_yao","yao");
}

int do_yao()
{
        object ob, food, water;
        if(query("busy"))
                return notify_fail("对不起，我这里很忙啊！稍微等一下吧！\n");
        set("busy",1);
        call_out("delete_busy",5);
        ob = this_player();
        food=new(__DIR__"obj/gao");
        water=new(__DIR__"obj/hulu");

        if( (present("meihua gao", ob)) && (present("da hulu", ob)) )
        {
               message_vision(HIW "厨师冲着$N说着：“先吃完了再要。”\n" NOR, ob);
                delete_busy();
                return 1;
        }
        else
        {
                if ( (present("meihua gao", ob)) )
                {
                        message_vision(HIW "厨师将一个大葫芦放在$N面前：“慢慢喝！”。\n" NOR, ob);
                        water->move(ob);
                        return 1;
                };
                if ( (present("da hulu", ob)) )
                {
                        message_vision(HIW "厨师将一盘梅花糕放在$N面前：“慢慢吃！”。\n" NOR, ob);
                        food->move(ob);
                        return 1;
                }
                else
                {
                        message_vision(HIW "厨师将一盘梅花糕、一个大葫芦放在$N面前。\n" NOR, ob);
                        food->move(ob);
                        water->move(ob);
                        return 1;
                }

        }
}

int delete_busy()
{
        delete("busy");
}

