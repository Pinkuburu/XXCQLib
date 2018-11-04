//xueku。c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "血窟");
	set("long", @LONG
此处为血河派的血窟。其结构别具一格，类似龟壳，四通八达。四面
墙上留有不少历代祖师传下来的武学精要，细细揣摩，似乎可以体会出心
得。在这里隐隐约约仿佛可以听到，镇帮至宝血河车的八匹神骏低低的嘶
鸣声，想到这，不由心跳加快，真想目睹一下血河车的恢弘气势。
LONG);	
	set("valid_startroom",1);
	set("objects",([
		"/kungfu/class/xuehepai/cao" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"xueheting",
		"north" : __DIR__"shandao1",
		"west" :  __DIR__"xueyu",
		"south" :  __DIR__"qixuetang",
		"east" :  __DIR__"xuezhutang",
	]));
        set("area", "龙门");
        setup();
            replace_program(ROOM);
}
