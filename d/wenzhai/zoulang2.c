// zoulang2.c
inherit ROOM;

void create()
{
  set("short","走廊");
  set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面
雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料制做成
的，走在上面毫无声息，你只感到脚下软软的，非常舒服。走廊东面就是
议事厅了。
LONG );
  set("exits",([
      "east" : __DIR__"neitang",
      "west" : __DIR__"zoulang1",
  ]));
  set("valid_startroom",1);
  set("outdoors","wenzhai");
  setup();
  replace_program(ROOM);
}
