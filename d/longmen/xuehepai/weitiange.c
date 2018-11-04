//weitiange。c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	seteuid(getuid());
	set("short", "危天阁");
	set("long", @LONG
这里是危天阁，是华危楼之居所。其人性格孤僻，乖戾，所以此处很
少有人前来光顾，危天阁地处绝崖边，更显得格外居傲不群，另外此处风
光独好，绚丽多彩，云遮雾绕，清尘脱俗。引得不少弟子在此伫足远眺，
尤其是夕阳落时，大伙在此欣赏山中美境。
LONG);	
	set("objects",([
		"/kungfu/class/xuehepai/hua" : 1,
	]));
	set("valid_startroom",1);
	set("exits",([
		"west" : __DIR__"xuezhutang",
		"south" : __DIR__"zoulang4",
	]));

	setup();
	replace_program(ROOM);
}
