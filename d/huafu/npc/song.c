// song.c 宋展眉
// mlf设计,lks编程

#include <ansi.h>
#include "/d/huafu/npc/cam.h"

#include "/d/huafu/npc/song.h"
int ask_counts();
int ask_rank();
inherit NPC;
#include "/kungfu/class/fameng/erdai.h"
inherit F_MASTER;
void create()
{
	set_name("宋展眉", ({ "song zhanmei", "song" }));
        set("nickname",HIM"扫眉才子"NOR);
	set("gender", "男性");
	set("age", 33);

	set("combat_exp", 100000);
        set_skill("tao",80);
        set_skill("cuff",100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("bairen-shengong", 100);
        
        map_skill("force","bairen-shengong");
        
           create_family("发梦二党",2,"弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
     set("inquiry",([
            "counts" : (: ask_counts :),
            "功勋" : (: ask_counts :),
            "rank" : (: ask_rank :),
            "职位" : (: ask_rank :),
     ]));
}
	
