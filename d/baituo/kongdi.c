#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
这是一片堂屋前的空地，旁边放了些兵器架、沙袋以及几个木桩。地
上铺满了飘落的树叶和干草。旁边有一口水井、一把水瓢，井水清澈，散
发着阵阵凉气。西面是几大间储藏室。
LONG);
        set("resource/water", 1);
        set("exits", ([
              "southdown" : __DIR__"shanmen",
              "west" : __DIR__"chucang",
              "northup" : __DIR__"tangwu",
        ]));
        set("outdoors", "白陀山");
        setup(); 
}

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"用水瓢舀了一口井水喝。\n"
            , environment(me), ({me}) );
            me->improve_skill("force", me->query("int"));
            write("你喝了一口清清的井水，虽身处炎热的大漠，也感到一丝凉意。\n");
        }
        else write("你已经喝不下了。\n");

        return 1;
}