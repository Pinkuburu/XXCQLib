// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("唐门留言簿",({"board"}));
	set("location","/d/tangmen/chashi");
	set("board_id", "tangmen_b");
	set("long", "这是一簿供四川唐门弟子留言的本子.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

