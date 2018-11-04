// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "达摩院二楼");
	set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不少白须白
眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。南北山墙是高及屋
顶的大书架，走近细看，它们是各门各派的武功秘笈，屋正中摆着几张矮
几诃和几个团，几位老僧正在入定中。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));
	set("objects",([
		"/kungfu/class/shaolin/muye" : 1,
	]));
	setup();
}
