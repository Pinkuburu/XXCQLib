// chufang.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"厨房"NOR);
         set("long",@long
这是一间小厨房, 虽然不大, 但是锅碗瓢盆, 油盐酱醋, 到很奇全。灶台
上堆满了新鲜瓜果蔬菜, 活鱼活虾, 不仅不脏不乱, 还十分干净整齐。在
厨房一角有一张饭桌(fanzhuo)。
long);
         set("item_desc", ([ 
"fanzhuo" : "饭桌上放着各种美味的江南小菜：
                    冬笋汤  (dongsun tang)   
                    翡翠鱼圆(feicui yuyuan)
                    菱白虾仁(lingbai xiaren)
                    梅花糟鸭(meihua zaoya)
                    樱桃火腿(tingtao huotui)
                    龙井菜叶鸡(longjing caiyeji)               
你看着这么多的美味，不禁想拿(na)起来就吃。
\n"
]));         
         set("exits",([
             "south" : __DIR__"xt",
]));
         setup();
	 
}
void init()
{
	add_action("do_na", "na");
}

int do_na(string arg)
{
	object me,ob;
  	string arg1,arg2;
  	me=this_player();
  	if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   		return notify_fail("命令格式: na <食物名称> from fanzhuo。\n");
  	if(arg2!="fanzhuo")
     		return notify_fail("命令格式: na <食物名称> from fanzhuo。\n");
     	if((int)me->query("food", 1) >= 200)
     		return notify_fail("吃了那么多，还想吃，真是馋猫。\n");
    	switch (arg1){
          case "dongsun tang": 
          	ob=new(__DIR__"obj/dongsun-tang");
                ob->move(me);          
                break;
          case "feicui yuyuan":
                ob=new(__DIR__"obj/feicui-yuyuan");
                ob->move(me);
                break;   
          case "lingbai xiaren":                   
                ob=new(__DIR__"obj/lingbai-xiaren");
                ob->move(me);          
                break;
          case "meihua-zaoya":
                ob=new(__DIR__"obj/meihua-zaoya");
                ob->move(me);
                break;   
          case "yingtao-huotui":                
                ob=new(__DIR__"obj/yingtao-huotui");
                ob->move(me);          
                break;
          case "longjing-caiyeji":
                ob=new(__DIR__"obj/longjing-caiyeji");
                ob->move(me);
                break;         

          default :
                 return notify_fail("没有这种食物。\n");
                    }

       message_vision("$N从饭桌上拿起一盘$n。\n",me, ob);  
       return 1;
}