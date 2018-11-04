// Room: 小径
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径，路两旁绿柳成阴，一处处山
石花木点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，一
旁的草丛似乎有什么东西，一个仆人正忙碌的找什么，小径向西北面
沿伸。
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "east" : __DIR__"qixuant", 
		"northwest"  : __DIR__"xiaojing1",
	]));
	set("objects",([
	        __DIR__"npc/puren1" : 1,
	        ]));
	setup();
	
}
void init()
{
	add_action("do_search","search");
	add_action("do_search","zhao");
}
int do_search(string arg)
{
	object ob,me;
	me=this_player();
	if(!arg||arg=="")
	return notify_fail("找什么？\n");;
	if(arg=="花名册")
	{
		if(me->query_temp("do_find_ce"))
		{
			message_vision("$N开始细细的搜索草丛周围，良久.....你终于在一个不大起眼的地方找到了一个册子。\n",me);
                        ob=new(__DIR__"obj/huamingce");
                        ob->move(me);
                        me->delete_temp("do_find_ce");
                        return 1;
                }
                message_vision("$N的跟着仆人东找西找，半天也不知道自己到底要找什么。\n",me);	
                return 1;
                 
        }               
                
}                 
	
        
