inherit ROOM;

void create()
{
      set("short","山间小路");
      set("long",@LONG
这里已经到了山区，由于山区潮湿的空气使得路面非常湿滑，行人都放
慢脚步，以免跌到。你向远处眺望，隐隐约约可以看到一座大山耸立在云雾
之中，真是太美了。你恨不得立刻能看到它的庐山真面目。
LONG);
           set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"sexit",
          "east"  : __DIR__"xiaolu2",
      ]));
      set("outdoors", "龙门");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

