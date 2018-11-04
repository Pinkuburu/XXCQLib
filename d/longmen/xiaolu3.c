inherit ROOM;

void create()
{
      set("short","山间小路");
      set("long",@LONG
这里已经到了山区，由于山区潮湿的空气使得路面非常湿滑，行人都放
慢脚步，以免跌到。你向远处眺望，隐隐约约可以看到一座大山耸立在云雾
之中，真是太美了。突然你发现前面有一道关口。原来血河派正在戒严，禁
止江湖人士上山。
LONG);
           set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"guanka",
          "north"  : __DIR__"xiaolu2",
      ]));
           set("objects",([
                    "/kungfu/class/xuehepai/guanshi" : 1,
           ]));
      set("outdoors", "龙门");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

