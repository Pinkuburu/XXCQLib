// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("天羽派留言簿",({"board"}));
        set("location","/d/tianyu/qianyuan");
        set("board_id", "tianyu_b");
       set("long", "这是一簿供天羽派弟子留言的本子.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
