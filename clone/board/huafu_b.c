// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("花府留言簿",({"board"}));
         set("location","/d/huafu/dating");
        set("board_id", "huafu_b");
       set("long", "这是一簿供花府弟子留言的本子.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

