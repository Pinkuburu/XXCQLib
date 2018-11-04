// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"欢迎光临小雪初晴"NOR);
    set("long",
"这里是最后的大门，踏出你将进入神雪山，进一步学习江湖规矩\n"
"和生存技能，请你记得多保存你的资料"+HIC"(save)"NOR+",如果累了想离开请"+HIC"(quit)\n"NOR
",不懂的地方可以看帮助文件"HIC+"(help)"NOR+"，你还可以随时用"HIC"(map here)"NOR"查看地图\n"
"祝你玩的愉快。\n"
    );
        

        set("exits", ([
		"south": __DIR__"dating",
        ]));
        set("objects",([
                __DIR__"npc/jieyinshix":1,
                ]));

        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{       
         if ( dir=="south") {
		me->set("newbie",1);
	}
        return ::valid_leave(me, dir);
}