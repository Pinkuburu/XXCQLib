// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("大光明栈留言板", ({ "board" }) );
	set("location", "/d/bianliang/guangming");
	set("board_id", "guangming_b");
	set("long", "这块留言板主要是用来让玩家互相留言用的，严禁灌水。\n" );
	setup();
     set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

