// NPC: wenwen.c 温家第三代弟子、高级师父  温文
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.7.31
// 
// 原著人物!  特殊武功--声毒

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string* medrooms = ({
        "/d/wenjia/caodi",
        "/d/wenjia/dayuan",
        "/d/wenjia/houyuan",
        "/d/wenjia/huoroad1",
        "/d/wenjia/huoroad2",
        "/d/wenjia/huoroad3",
        "/d/wenjia/huoroad4",
        "/d/wenjia/huoroad5",
        "/d/wenjia/huoroad6",
        "/d/wenjia/huoroad7",
        "/d/wenjia/huoroad8",
        "/d/wenjia/shulin1",
        "/d/wenjia/shulin2",
        "/d/wenjia/shanlu1",
        "/d/wenjia/shanlu2",
        "/d/wenjia/shanlu3",
        "/d/wenjia/shanlu4",
        "/d/wenjia/siroad1",
        "/d/wenjia/siroad2",
        "/d/wenjia/siroad3",
        "/d/wenjia/siroad4",
        "/d/wenjia/siroad5",
        "/d/wenjia/siroad6",
        "/d/wenjia/yaotian1",
        "/d/wenjia/yaotian2",
        "/d/wenjia/yaotian3",
        "/d/wenjia/yaotian4",
        "/d/wenjia/yaotian5",
        "/d/wenjia/yaotian6",
        "/d/wenjia/yaotian7",
});

string* medsources = ({
        "chihuohe",
        "mushugen",
        "fanmubie",
        "chiaisu", 
        "duanchangcao", 
        "hedinghong", 
        "kongquedan", 
});

string* chinesemedsources = ({
        "赤火蝎",
        "木薯根",
        "番木鳖",
        "赤矮栗",
        "断肠草",
        "鹤顶红",
        "孔雀胆",
});

int give_yaofang();
void recover_ob();

void create()
{
        set_name("温文", ({ "wen wen","wen"}) );
        set("nickname", RED"一毒即杀，一笑祝好"NOR );
        set("gender", "男性" );
        set("age", 50);
        set("per", 25);
        set("long",
                "温文又叫温文人，是小字号的高手，温晚的爱将和师弟。\n个子不高，发微秃、人很斯文，很文质彬彬。");
        set("attitude", "friendly");

        set("qi", 2500);
        set("max_qi", 2500);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

        set("combat_exp", 8500000);

        set_skill("lphand", 150);    //施毒手法
        set_skill("force", 150);     //基本内功
        set_skill("dodge", 150);     //基本轻功
        set_skill("parry", 150);     //基本招架
        set_skill("zhixin", 150);    //温故知新
        set_skill("poisonk", 150);   //毒药知识
        set_skill("qianli", 150);    //毒行千里
        set_skill("shengdu", 200);   //声毒
        set_skill("literate", 150);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "shengdu");
        map_skill("parry", "shengdu");

        prepare_skill("lphand", "shengdu");

        create_family("老字号温家", 3, "弟子");

        set("inquiry", ([
                "药方" : (: give_yaofang :),
                "yaofang" : (: give_yaofang :),
        ]) );

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.wusheng" :),
                (: recover_ob :)
        }) );

        add_money("gold", 5);

        carry_object("/d/wenjia/obj/gubo");
        carry_object("/d/wenjia/obj/chouduan")->wear();
}

void attempt_apprentice(object me)
{
        mapping myfam;
        me = this_player();

        myfam = (mapping)me->query("family");

        if ( me->query("combat_exp")<500000 ) {
                command("say 去江湖上多磨练磨练吧。");
                return;
        }
        if ( me->query("shen") < 0) {
                command("say 我们温家虽然在武林中算不上名门正派，温家弟子都是不能为祸江湖的。");
                command("say 在德行方面，" + RANK_D->query_respect(me) +
                        "是否还做得不够？");
                return;
        }
        if ( me->query_skill("lphand", 1) < 110) {
                command("say 我们老字号温家是使毒的，施毒手法对我们来说就如生命一样重要。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在施毒手法上多下点功夫？");
                return;
        }
        if ( me->query_skill("zhixin", 1) < 110) {
                command("say 我们老字号温家虽然是使毒的，但使毒时需要内功把毒药放出去。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在内功心法上多下点功夫？");
                return;
        }

        command("say 好吧，我就收下你了。");
        command("say 好好的学吧!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}

int give_yaofang()
{
        object me,obj;
        string *obj1;
        int i,med1,med2,med3,medroom1,medroom2,medroom3 ;

        me=this_player();

        if ( me->query_temp("taskxiao/given") )
	{
                command("nod " + me->query("id"));
                message_vision("温文对$N说：“你拿着这张药方，按照上面去采那几种药材吧!”\n",me);
                obj=new("/d/wenjia/task_xiao/obj/yaofang");
                med1=random(sizeof(chinesemedsources));
                med2=random(sizeof(chinesemedsources));
                med3=random(sizeof(chinesemedsources));
                medroom1=random(sizeof(medrooms));
                medroom2=random(sizeof(medrooms));
                medroom3=random(sizeof(medrooms));
                obj->set("long","这味毒药主要由这几种药材组成："YEL+chinesemedsources[med1]
                         +"、"+chinesemedsources[med2]+
                          "、"+chinesemedsources[med3]+
                          NOR"。\n");
                obj->move(me);
                obj=new("/d/wenjia/task_xiao/obj/yaochu");
                obj->move(me);
                obj=new("/d/wenjia/task_xiao/obj/yaolou");
                obj->move(me);
                message_vision("温文又说道：“这把药锄是专门用来采药的!拿着。”\n",me);
                me->set_temp("taskxiao/med1",med1);
                me->set_temp("taskxiao/med2",med2);
                me->set_temp("taskxiao/med3",med3);
                me->set_temp("taskxiao/medroom1",medroom1);
                me->set_temp("taskxiao/medroom2",medroom2);
                me->set_temp("taskxiao/medroom3",medroom3);
                return 1;
        }        

        message_vision("温文对$N说：“你向我拿药方干什么?”\n",me);
        return 1;

}

int accept_object(object who, object ob)
{
        if ( ob->query("name")=="药锄")
		{
		         who->set_temp("taskxiao/yaochugiven",1);
                 message_vision("温文对$N说：“这个药锄我已经收到了！”\n",who);
				 return 1;
        }
        if ( ob->query("name")=="药方")
		{
		         who->set_temp("taskxiao/yaofanggiven",1);
                 message_vision("温文对$N说：“这张药方我已经收到了！”\n",who);
				 return 1;
        }
}