// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("客人留言簿", ({ "board" }) );
        set("location", "/d/welcome/wel1");
        set("long", "这是一个让前来胖胖工作室的客人留言的本子。\n" );
        setup();
        set("capacity",200);
        replace_program(BULLETIN_BOARD);
}
