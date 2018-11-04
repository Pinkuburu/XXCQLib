//changan city

inherit ROOM;

void create ()
{
        set ("short", "南厢院");
        set ("long", @LONG
南厢院和北厢院比起来显得比较的杂乱，不但地上堆着一些杂物、散
乱的兵器，空中也晾着许多的衣物，厢院的东面是一间朴素的厢房，剑庐
的虎组就驻在那里。而更为简陋的南厢房则是犬吠堂所在，西面飘香之处
却是剑庐的饭堂。
LONG);
	set("valid_startroom", 1);

        set("objects", ([
	]));

        set("exits", 
        ([
		"north" : __DIR__"southlang",
		"east" : __DIR__"huzu",
		"west" : __DIR__"eatroom",
		"south" : __DIR__"quanzu",
	]));

        set("outdoors", "xiao");

        set("objects", ([
		__DIR__"npc/guanjia" : 1,
	]));

        setup();

	replace_program(ROOM);
}