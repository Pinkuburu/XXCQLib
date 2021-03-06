// Room: /city/kedian.c
// LOAD 

inherit ROOM;

void create()
{
	set("short", "大光明栈");
	set("long", @LONG
这是北京城几家客店中价格最低廉的一家，一些没钱的学子和赴京告
状的穷人多选择这里落脚，但由于这里便宜，所以设施也简陋，不但没有
饭食供应，而且也只有大通铺可以住，小二忙碌招呼着进进出出的客人，
墙上还挂着一个牌子(paizi)。往西就是小雪社区啦！！
LONG
	);

          set("no_fight",1);
	set("valid_startroom", 1);
         set("resource/water", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "客房通铺，每夜十两白银。\n",
	]));

	set("objects", ([
        __DIR__"npc/xiaoer" : 1,
        "/topten/topbook" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"nandajie1",
		"enter" : __DIR__"kefang",
		"up" : "/d/wizard/guest_room",
 //        "west": "/d/shequ/jiaowai1",
		"注册":"/adm/wel1",
	]));
	set("area", "汴梁");
	setup();
	call_other("/clone/board/guangming_b", "???");
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "enter" )
	return notify_fail("店小二一下挡在里屋门前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
