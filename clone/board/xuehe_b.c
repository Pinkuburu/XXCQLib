// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("血河派弟子留言簿",({"board"}));
           set("location","/d/longmen/xuehepai/qixuetang");
          set("board_id", "xuehe_b");
         set("long", "这是一簿供血河派弟子留言的本子.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

