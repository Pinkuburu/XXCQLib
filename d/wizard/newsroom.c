#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIY "小雪初晴新闻发布中心" NOR);
	set("long", @LONG
这里是小雪初晴的新闻发布中心，有什么新闻都可以在这里发布(post)，
然后系统自动随机通知所有在线玩家。
LONG );
	set("exits", ([
		"north" : __DIR__"wizard_room",
	]));
	set("objects",([
		__DIR__"newer":1,
	]));
	set("no_clean_up", 1);
	setup();
	call_other("/clone/board/news_b", "???");
	replace_program(ROOM);
}
