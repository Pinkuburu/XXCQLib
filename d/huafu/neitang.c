// neitang.c 内堂
// mlf 设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","内堂");
        set("long",
"这里是花府内堂，这里只有主人的密友和亲信弟子才能入内。房间的
摆设比别的地方更讲究，座位上铺着绣有金丝花朵的靠垫，宽大的书桌上
摆者一盆名贵的"HIB"兰花，"NOR"玉石镇纸以及文房四宝。。。。东边是花枯发的卧
室。那门是锁着的。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"zoulang1",
	]));
	set("objects",([
		__DIR__"npc/huakufa" : 1,
	]));
	set("item_desc",([
		"door" : "门是关着的，上面有一个钥匙孔。\n",
	]));
	set("pen_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_unlock","unlock");
}

int do_move(string arg)
{
	object ob,me=this_player();
	object where=environment(me);
	if (arg!="pen") return 0;
	if (!where->query("pen_moved"))
		return notify_fail("花盆已经被移动了。\n");
          if (ob = present("bedroomkey", this_player()))
		return notify_fail("你想干啥？\n");
	ob=new(__DIR__"obj/key");
	ob->move(me);
	message_vision(HIG"$N移开花盆,看到一把钥匙。\n"NOR,me);
	me->set_temp("doorisok",1);
	set("pen_moved",0);
	return 1;
}

int do_unlock(string arg)
{
	object ob,room;
	if (query("exits/east"))
		return notify_fail("门已经是打开的。\n");
	if (!arg || (arg != "door"))
		return notify_fail("你要打开什么？\n");
     if (!(ob = present("bedroomkey", this_player())))
		return notify_fail("你不会撬锁。\n");
	message_vision(
	"$N用一把钥匙打开了卧室门，可是钥匙却断了.\n", this_player());
	destruct(ob);
	if (this_player()->query_temp("doorisok"))        
        {
	set("exits/east", __DIR__"woshi");
	if(!( room = find_object(__DIR__"woshi")) )
        room = load_object(__DIR__"woshi");
	if(objectp(room))
    	{
        set("exits/east", __DIR__"woshi");
        message_vision("$N轻轻地推门，只听吱地一声，门开了。\n",this_player());
        room->set("exits/west", __FILE__);
        message("vision","只听吱地一声，卧室门从外面打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    	}
        this_player()->set_temp("doorisok",0);
        } 
	return 1;
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"woshi")) )
        room = load_object(__DIR__"woshi");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision","只听乒地一声，卧室门自动关上了。\n",
            this_object());
        message("vision","哎哟！又进不去了！\n" ,
			this_object());
        room->delete("exits/west");
        message("vision","只听乒地一声，卧室门自动关了起来。\n", room);
        message("vision","坏了！出不去了！\n" ,
			room );
     }
	return 1;
}
