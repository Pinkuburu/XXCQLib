inherit ROOM;

#include <room.h>
int do_drink();
void create()
{
        set("short", "储藏室");
        set("long", @LONG
由于你暂时还出不去，卫前辈特地在这里收集了一些鱼虾之类的东西
还特意凿开岩石，把潭里的水引进来，供你饮用。好让你心无杂念的钻研
他的独门内功。
LONG );
        set("resource/water", 1);
            set("sleep_room",1);

           set("objects",([
                   "/d/bianliang/npc/obj/niurou" : 4,
           ]));
        set("exits", ([
                "east" : __DIR__"mishi",
        ]));
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink()
{
        int max_water;
        object me;

        me = this_player();
        max_water = me->query("str")*10 + 100;
        if (me->query("water")<max_water) {
			me->add("water",30);
            message_vision("$N喝了一口水。\n",me);
        }
        else write("你已经喝饱了。\n");

        return 1;
}

