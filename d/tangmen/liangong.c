//liangong.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "练功场");
	set("long", @LONG
这是唐门的练功场。平常总有一些弟子在这里苦练工夫，因为他们
不甘心在江湖中默默无闻，他们梦想着有一天能够亲手击败大侠萧秋水
成为武林中的第一人。
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([	"north" : __DIR__"wzlang1",]));
	setup();
	replace_program(ROOM);
}