
#include <ansi.h>
#include <armor.h>
#include <mudlib.h>

#include <command.h>
#include <net/dns.h>

inherit FINGER;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
string inputstr,verb;
mapping valid_types = ([
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
        "iron-cloth":   "硬功",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
        "spells":       "咒文",
        "move":         "行动",
        "array":        "阵法",
        "whip":         "鞭法",
]);
void create()
{
	set_name(HIG"七"+HIM"宝"+HIR"指"+HIY"环"NOR,
		({ "qibao zhihuan", "huan", "zhihuan" }));
	set("long", @LONG

	wave	 <数量> <钱币类型>    <取出哪种钱币的多少数目>
	rem      <装备> from <对象>   <让某一对象解除装备>
        fsteal   <物品> from <对象>   <从某玩家或对象身上拿某样东东>
        mobpk    <生物1> with <生物2> <让生物1 与生物2 互 k>
        fwhere   <玩家>               <显示一玩家的所在地>
        full     <玩家>               <全医, 玩家若无输入则内定为自己>
        wakeup   <玩家>               <把昏迷不醒的玩家叫醒>
        fsnoop   <玩家>               <监听玩家的信息>
        checkout <生物>               <检查该生物enable了的技能情况>
        fwho     <-i|-w>              <同who命令，但是没有人可以隐身的>
        ftell    <玩家>               <可以tell隐身人!>

LONG );
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "finger");
		set("value", 100);
		set("unit", "个");
		set("wear_msg", HIB"$N拿出一个$n"+HIB"戴在无名指上。\n"NOR);
		set("remove_msg", HIB"$N将$n"+HIB"褪了下来，放进口袋。\n"NOR);
		set("armor_prop/armor", 10000);
	}
	set("no_get",1);
	set("no_drop",1);
	setup();
}

void init()
{
        object me;
        seteuid(geteuid());
        me = this_player(1);
        if(wiz_level(me)<wiz_level("(hufa)")&&this_object()->query("clone")!=1)
        {
                destruct(this_object());
                        return 
                notify_fail("请不要乱复制！使用这个东西必须得到护法以上级别巫师的同意！\n");
        }
	if(me->query("id")!="adx")
	{
	write("这是山猫专用物品，怎么落入你手。现在自动摧毁。\n");
		me->unconcious();
		destruct(this_object());
	}
        add_action("full","full");
        add_action("rem","rem");
        add_action("wave","wave");
        add_action("steal","fsteal");
        add_action("whereis", "fwhere");
        add_action("pk_mob", "mobpk");
        add_action("test", "wtest");
        add_action("do_who","fwho");
        add_action("do_checkout","checkout");
        add_action("do_snoop","fsnoop");
        add_action("do_tell","ftell");
        add_action("do_wakeup", "wakeup");
	add_action ("do_fyun", "fyun");
        add_action("do_renming","ren");
        this_player()->set_temp("heat",1);
}

int do_tell(string arg)
{
        string target, msg;
        object obj,me;
        me=this_player();
        if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) 
                return notify_fail("要告诉谁什么？\n");
        obj = find_player(target);
        if(!obj ) 
                return notify_fail("没有这个人....。\n");
        if (!wizardp(me) && obj->query_temp("pigging_seat"))
                return notify_fail("正在拱猪的人听不到悄悄话……。\n");
        write( HIG "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
        tell_object(obj, sprintf( HIG "%s告诉你：%s\n" NOR,
                me->name(1)+"("+me->query("id")+")", msg));
        obj->set_temp("reply", me->query("id"));
        return 1;
}

mixed do_who(string arg, int remote)
{
        string str, name,*option;
        object *list,me;
        int i, j, ppl_cnt;
        int opt_long,  opt_wiz;
        me=this_player();
        if( arg ) 
        {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) 
                        {
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
                                default:
                                        if( wizardp(me)&&option[i][0]=='@' ) 
                                        {
				RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
                                                write("网路讯息已送出，请稍候。\n");
                                                return 1;
                                        }
                                return notify_fail("指令格式：who [-l|-w]\n");
                        }
        }
        str = "★ 小雪初晴 ★" + "[Adx]\n";
        str += "——————————————————————————————————\n";
        list = users();
        if( opt_long || opt_wiz ) 
        {
                j = sizeof(list);
                while( j-- ) 
                        {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( !me->visible(list[j]) ) continue;
                        if( wizardp(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        str = sprintf("%s%12s %s\n",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                        }
                j = sizeof(list);
                while( j-- ) 
                        {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( !me->visible(list[j]) ) continue;
                        if( !wizardp(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        str = sprintf("%s%12s %s\n",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                        }
        } 
        else {
                ppl_cnt = 0;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( me && !me->visible(list[j]) ) continue;
                        if( wizardp(list[j]) ) continue;
                                name = sprintf("%s(%s)", list[ j ]->name( 1 ),
                                capitalize( list[ j ]->query( "id" ) ),
                                );
                        str = sprintf("%s%-25s%s", str, name,
                                                (ppl_cnt % 3 == 2? "\n" : "") );
                                ppl_cnt++;        
                }
                if ( ppl_cnt % 3 ) str += "\n";
        
                str+=NOR"——————————————————————————————————\n";
                ppl_cnt = 0;
                j = sizeof(list);
                while(j--) {
                if( !environment(list[j]) ) continue;
                        //if( me && !me->visible(list[j]) ) continue;
                        if( !wizardp(list[j]) ) continue;
                                name = sprintf("%s(%s)", list[ j ]->name( 1 ),
                                capitalize( list[ j ]->query( "id" ) ),
                                );
                        str = sprintf("%s%-25s%s", str, name,
                                (ppl_cnt % 3 == 2? "\n" : "") );
                                ppl_cnt++;        
                }
                if ( ppl_cnt % 3 ) str += "\n";
        }
        str += "——————————————————————————————————\n";
        str = sprintf("%s共有 %d 位使用者连线中，系统负担：%s\n", str, sizeof(list),
                query_load_average() + "\n");
        if( remote ) return str;
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) 
                return -1;
        if( wizardp(ob2) && !wizardp(ob1) ) 
                return 1;
        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);
        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int do_checkout(string arg)
{
        object player,me;
        mapping map;
        string  *skill;
        int i, modify;
        me=this_player();
        if ( arg )
        {
                player = present( arg, environment( me ) );
                if ( !player )
                        player = find_player( arg );
                if ( !player )
                        player = find_living( arg );
                if ( !player )
                        return notify_fail( "你想查看谁的状态? \n" );
                map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("[Cloak]: 他现在没有使用任何特殊技能。\n");
                skill = keys(valid_types);
                write("以下是"+player->query("name")+"目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) 
                {
                        if( undefinedp(valid_types[skill[i]]) ) 
                        {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) 
                                continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR,
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" :to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }
        else
                return notify_fail( "你想看谁的状态啊? \n" );
}

int rem(string str)
{
        string ob,player;
        object obj,me,npc;
        seteuid(geteuid());
        me=this_player();
        if (!str||sscanf(str,"%s from %s",ob,player)!=2)
                return notify_fail("rem <装备> from <object>\n");
        if (!(npc = find_player(player)))
                if (!(npc = find_living(player)))
                        if (!(npc = present(player, environment (this_player()))))
                                return notify_fail("没这个人\n");
        obj=present(ob, npc);
        if(!obj)
                return notify_fail ("这里没有那种东东\n");
        else 
        {
                message_vision ("$N让"+npc->query("name")+"脱下$n("+ob+")\n", this_player(),
                        obj);
                obj->move(this_player());
                obj->move(npc);
                return 1;
        }
}

int steal(string str)
{
        string ob,player;
        object obj, npc, me;
        me=this_player();
        if(!str)
                return notify_fail("steal <物品> from <object>\n");
        seteuid(geteuid());
        if (sscanf(str,"%s from %s",ob,player) != 2)
                return notify_fail("steal <物品> from <object>\n");
        if (!(npc = find_player(player)))
                if (!(npc = find_living(player)))
                        if ( !(npc = present(player, environment (me))) )
                                return notify_fail ("没这个"+str+"\n");
        if (!(obj=present(ob, npc)))
                return notify_fail ("没这个东西"+str+"。\n");
        obj->move(me);
        tell_object(me,"你偷了"+npc->query("name")+"的"+ob+"。\n");
        return 1;
}

int whereis(string arg)
{
        object where, me;
        object *ob;
        string msg;
        int i;
        me=this_player();
        if(arg&&!find_player(arg))
                return notify_fail ("他在虚无飘藐间。\n");
        if (arg) 
        {
                where = environment(find_player(arg));
                if (!where) 
                        return notify_fail ("[Cloak]: 他在虚无飘藐间。\n");
                msg = where->query ("short")+"  -- "+file_name(where)+"\n";
                msg += where->query("long");
        }
        else 
        {
                ob = users();
                msg = "";
                for(i=0; i<sizeof(ob); i++) 
                {
                        where = environment(ob[i]);
                        if (!where)
                        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
                        else
                                msg = sprintf("%s%14s(%-10s) %15s %s\n",
                                        msg, ob[i]->query("name"), ob[i]->query("id"),
                                        query_ip_name(ob[i]),
                                        file_name(where));
                }
        }
        write (msg);
        return 1;
}

int full(string str)
{
        int max;
        object me;
        me=this_player();
        if (!geteuid()) seteuid (getuid());
        if(!str)
                me=this_player();
        else
                me=find_player(lower_case(str));
        if (!me) 
                return notify_fail ("full 错误: 找不到"+str+"\n");
        max = me->query("max_jingli");
        me->set("eff_jingli",max);
        me->set("jingli",max);
        max = me->query("max_jing");
        me->set("eff_jing",max);
        me->set("jing",max);
        max = me->query("max_neili");
        me->set("eff_neili",max);
        me->set("neili",max);
        max = me->query("max_qi");
        me->set("eff_qi",max);
        me->set("qi",max);
        max = me->max_food_capacity();
        me->set("food",max);
        max = me->max_water_capacity();
        me->set("water",max);
        me->clear_condition();
        message_vision( sprintf("$N双手合十，向天念起了咒文！\n"),this_player());
        return 1;
}

int wave(string arg)
{
        string kind;
        int amount;
        object n_money,me;
        me=this_player();
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
                return notify_fail("wave <数量> <钱币种类>\n");
        if(kind=="cash")
                kind="thousand-cash";
        n_money = present(kind + "_money", this_player());
        if( amount < 1 )
                return notify_fail("你摇了半天却什么也没有出来。\n");
        if( !n_money ) 
        {
                n_money = new("/clone/money/" + kind+".c");
                if(!n_money)
                        return notify_fail("你摇了半天却什么也没有出来。\n");
                n_money->move(this_player());
                n_money->set_amount(amount);
        } 
        else
                n_money->add_amount(amount);
        message_vision( sprintf("$N使劲的掏口袋，突然从袋子里掏出%s%s%s。\n",
                chinese_number(amount),
                n_money->query("base_unit"),
                n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2,me;
        string st1,st2;
        me=this_player();
        if (!str || str=="") 
                return notify_fail ("你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
                return notify_fail ("mobpk <ob1> with <ob2>\n");
        if (!ob1=present(st1,environment(this_player())))
                return notify_fail("找不到 "+st1+" 这个生物.\n");
        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");
        message_vision("$N用巫师的特权, 让"+
                ob1->name()+"跟"+ob2->name()+"开始互相瓯斗。",
                this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_wakeup (string str)
{
        object who,me;
        me=this_player();
        if (!str) 
                return notify_fail ("wakeup 命令错误\nwakeup <某人id>\n");
        if (!(who=present (lower_case(str), environment(this_player()))) )
                if(!objectp(who=find_player(lower_case(str))))
                        return notify_fail ("wakeup 错误, 没有"+str+"\n");
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        return 1;
}
int do_snoop(string arg)
{
        object ob,me;
        me=this_player();
        if( !arg ) 
        {
                if( objectp(ob = query_snooping(me)) )
		write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
                else
                        write("你没有监听任何人。\n");
                return 1;
        }
        else 
        if( arg=="none" ) 
        {
                if(objectp(ob=query_snooping(me))&&me->query("env/snoop")==1)
                snoop(me);
                write("Ok.\n");
                return 1;
        }
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");
        if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
        snoop(me, ob);
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");

        return 1;
}

int do_fyun(string arg)
{
	object who;

	if (!arg) return notify_fail ("[提示]: fyun error, fyun <someone>\n");

	if (!(who=present (lower_case(arg), environment(this_player()))) )
		return notify_fail ("[提示]: 没这个人("+arg+")\n");
	who->unconcious();
	return 1;
}

int do_renming(string arg)
{
	object me, ob;
	string id, level, level1, level2, level3;
	int i;
	mapping party;
	me = this_player();

	if( !arg ) return notify_fail("指令格式：ren <ID> <帮派> <等级>\n");

	if( (sscanf(arg, "%s %s %s %s", id, level, level2, level3)==4)
		||(sscanf(arg, "%s %s %s", id, level, level2)==3) );
	else return notify_fail("指令格式：ren <ID> <帮派> <等级>\n");

	if( !ob ) ob = find_living(id);

	if (!ob) return notify_fail("现在没这个人。\n");

	if((level=="药王庄"))
	{
		if(level=="药王庄")
		{
		level1=HIB"药王庄"NOR;
		if(level2=="庄主") {level3=HIB"庄主"NOR;i=8;}
		if(level2=="总管") {level3=HIW"总管"NOR;i=7;}
		if(level2=="管事") {level3=WHT"管事"NOR;i=6;}
		if(level2=="医师") {level3=HIC"医师"NOR;i=5;}
		if(level2=="药师") {level3=CYN"药师"NOR;i=4;}
		if(level2=="药匠") {level3=HIM"药匠"NOR;i=3;}
		if(level2=="庄丁") {level3=MAG"庄丁"NOR;i=2;}
		if(level2=="跑堂") {level3=YEL"跑堂"NOR;i=1;}
		}
	}
	else return notify_fail("操作失败！\n");

	party = allocate_mapping(5);
	party["party_name"] =level1;
	party["rank"] = level3;
	party["level"] = i;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	message_vision(YEL"$N任命$n为"+level1+level3+"。\n"NOR, me, ob);
	return 1;
}
