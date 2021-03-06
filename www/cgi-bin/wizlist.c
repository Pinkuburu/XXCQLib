#include <mudlib.h>
inherit F_CLEAN_UP;

int level(mixed, mixed);
string wiz_rank(string hood);

string gateway(string pattern)
{
        string *list, hood = "", str;
        int j;
        string  ret = "<HEAD><TITLE>"+MUD_NAME+"目前在线的玩家</TITLE></HEAD>";
        ret += sprintf("<h3 align=center><font face='幼圆' color=#ff0000>%s"
                                "<font face='幼圆'color=#000000>在线玩家列表</font>"
                                "</h3><hr>",CHINESE_MUD_NAME);
        j=0;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
        str = ret;
        str += "<blockquote><blockquote>———————————————————<br>";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood!= wiz_rank(wizhood(list[i]))) {
                        hood = wiz_rank(wizhood(list[i]));
                        if (j%7) str += "<br>";
                        str += hood;
                        str = replace_string(str,"(","<font color=#ff0000>");
                        str = replace_string(str,")",": </font>");
                        j = 0;
                }

                str += sprintf(" %s%s", list[i],
                        ( j%7==6 ) ? "<br>" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
        str += "<br>———————————————————<br>";
        str += sprintf("目前一共有: %d个巫师</blockquote></blockquote>",sizeof(list) );
        return str;
}
string wiz_rank(string hood)
{	switch(hood) {
		case "(admin)":			
			return "【 天  神 】";
		case "(arch)":			
			return "【 大巫师 】";
		case "(hufa)":			
			return "【 护  法 】";
		case "(wizard)":		
			return "【 巫  师 】";
		case "(angel)":			
			return "【 天  使 】";
		case "(apprentice)":		
			return "【 小  巫 】";
		case "(immortal)":		
			return "【 精  灵 】";
	}
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}
