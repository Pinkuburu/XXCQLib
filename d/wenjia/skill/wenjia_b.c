inherit BULLETIN_BOARD;

void create()
{
        set_name("老字号温家公告牌",({"board"}));
        set("location","/d/wenjia/square");
        set("board_id", "wenjia_b");
        set("long", "这是一块供老字号温家弟子留言的木牌。\n");
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}
