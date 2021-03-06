// deng.c 邓百川

inherit NPC;
inherit F_MASTER;                        
#include <ansi.h>
#include <localtime.h>
#include "app.h"
int ask_fenmu();
int ask_jifen();
void create()
{
	set_name("邓百川",({"deng baichuan","deng","baichuan"}));
        set("title","青云庄庄主");
  	set("long", 
              "他就是姑苏慕容青云庄的庄主。\n");
        set("age", 25);
	set("attitude", "friendly");
        set("unique", 1);
	set("shen_type", 1);
	set("per", 30);
	set("str", 36);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 85000);

        set_skill("finger",130);
        set_skill("dodge",130);
        set_skill("force", 120);
	set_skill("shenyuan-gong", 120);
	set_skill("yanling-shenfa", 150);
        set_skill("parry", 130);
	set_skill("canhe-zhi", 130);
        set_skill("literate", 130);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");	

	prepare_skill("finger","canhe-zhi");
	setup();
        carry_object("/clone/misc/cloth")->wear();        
        create_family("姑苏慕容",3,"弟子");
        set("inquiry", ([
            "name" : "我就是姑苏慕容青云庄庄主邓百川。\n",
            "here" : (: ask_fenmu :),                             
            "rumors" : "最近少林寺一位大师被少林名技韦驮杵所害，天下人竟以为是慕容的以彼之道，还施彼身所为。\n",            
            "阿珠" : "阿珠住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
            "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
            "王语嫣" : "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。\n",
            "公孙乾" : "公孙乾是我二弟，是燕子坞赤霞庄的庄主。\n",
            "包不同" : "包不同是我三弟，是燕子坞金凤庄的庄主，他总是喜欢说“非也，非也”。\n",
            "风波恶" : "风波恶是我四弟，是燕子坞玄霜庄的庄主，他就是喜欢跟别人打架。\n",
            "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
            "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
            "曼佗罗山庄" : "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。\n",
            "还施水阁" : "这是燕子坞的秘密之所在，我可不便对你说。\n",       
            "祭坟" : (: ask_jifen :),
            "扫墓" : (: ask_jifen :),
]));                 

}
int ask_jifen()
{
	mapping fam;                         
	mixed *ltime;
	int i, current_month, current_day, current_hour;	
	object me, ob, *obj;
	me = this_player();
	ob = this_object();
	obj = all_inventory(environment(ob));	
	ltime = localtime(time());
	current_month = ltime[LT_MON]+1;
	current_day = ltime[LT_MDAY];                     
	current_hour = ltime[LT_HOUR];	
        if( sizeof(obj) > 2)
        {
		for(i=0; i<sizeof(obj); i++)
		{
			if( obj[i]->is_character() && obj[i]->query("family/family_name") != "姑苏慕容")
			{
				command("say 有外人在这里还是不说也罢。");
				return 1;
			}
			else if(current_month == 4 && current_day == 4 )
			{                                            
				command("say 明天是清明节，你赶在子时前来祭坟，扫墓吧。");
				return 1;
			}
			else                                                                                 
			{                         
				command("say 等到了清明，你再来祭坟，扫墓吧。");
		                return 1;
			}
		}
	}

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
        {
                command("say "+ RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？");
                return 1;
	}
	if(current_month == 4 && current_day == 4 )
	{                                            
		command("say 明天是清明节，你赶在子时前来祭坟，扫墓吧。");
		return 1;
	}
	command("say 等到了清明，你再来祭坟，扫墓吧。");
	return 1;
}                
	
int ask_fenmu()
{
	mapping fam; 
	int i;
	object me, ob, *obj;
	me = this_player();
	ob = this_object();
	obj = all_inventory(environment(ob));

        
        if( sizeof(obj) > 2)
        {
		for(i=0; i<sizeof(obj); i++)
		{
			if( obj[i]->is_character() && obj[i]->query("family/family_name") != "姑苏慕容")
			{
				command("say 有外人在这里还是不说也罢。");
				return 1;
			}

			else                                                                                 
			{
				command("say 自从老爷子去了之后，公子每年清明都到这里来给老爷子扫墓。");
		                return 1;
			}
		}
	}

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
        {
                command("say "+ RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？");
                return 1;
	}

	command("say 自从老爷子去了之后，公子每年清明都到这里来给老爷子扫墓。");
	return 1;
}                