// /clone/board/dali_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("药王谷留言板", ({ "board" }) );
     set("location", "/d/yaowang/dating");
         set("board_id", "yaowang_b");
	set("long", "这是一个供药王谷门下交流的留言板。\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
