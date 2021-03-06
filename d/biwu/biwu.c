#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "比武广场" NOR);
        set("long", @LONG
这里是老英雄公平子先生的比武广场。平整的青石地板，四面旌旗飘扬。
四周的墙上挂着十八般武器，供比武的人任意取用。天下的英雄们若要一争
高低，都来此比试。有公平子老先生为证，谁也无法投机取巧，所以这里的
英雄排名，为天下人士所公认。
LONG
        );
        set ("exits",([
        "down" : "/d/bianliang/guangchang",
                ]));
        setup();
}

void init()
{
        this_player()->set_temp("biwu",1);
	add_action("do_pick","pick");
}

int valid_leave(object me, string dir)
{
        if( dir=="down" )
		me->delete_temp("biwu");
        return ::valid_leave(me, dir);
}

int do_pick(string arg)
{
        object me, ob, obj;
	me = this_player();
	obj = present("drum", (environment(me)));
	if(!arg)
		return notify_fail ("你要拿什么呢？\n");

	if( arg=="zhujian"
	|| arg=="mudao"
	|| arg=="zhubang"
	|| arg=="baozi"
	|| arg=="cha" ) {

	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( !obj||!obj->query("drum_knocked") )
		return notify_fail("现在不是比武期间，架子上的东西不能拿！\n");

	if (  present(arg, me) )
		return notify_fail("你身上不是有吗？\n");

	ob = new(__DIR__"obj/" + arg);
	ob->move(me);
	message_vision(YEL ""+me->query("name")+"从架子上拿了一"
		+ob->query("unit")+ob->query("name")+"。\n"NOR, me);
	} else {
		return notify_fail ("你要拿什么呢？\n");
	}
	return 1;
}
