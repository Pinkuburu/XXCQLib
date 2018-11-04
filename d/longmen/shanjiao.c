inherit ROOM;

void create()
{
      set("short","山脚");
      set("long",@LONG
你已经来到了龙门石窟的山脚下，往上望去，只见山峰被包在一片云雾
之中，煞是好看。这里已经属于血河派的势力范围了，到处可见血河派的弟
子在巡逻，快上山吧。
LONG);
            set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"shanlu1",
           "west"  : __DIR__"guanka1",
      ]));
      set("outdoors", "龙门");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

