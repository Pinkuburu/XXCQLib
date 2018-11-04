// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *toplist;
        string str;
        int i,j;
        
        if(arg=="-p")
        {
                str="你目前排名第"+me->query_tops()+"名\n";
                me->start_more(str);
                return 1;
        }
        
                toplist=COMPETE_D->get_tops();
                str=HIC "【天下英雄排行榜】\n" NOR;
                str+="——————————————————————————————————\n";
                for(i=0,j=sizeof(toplist);i<j;i++)
                {       str+="第"+chinese_number(i+1)+"名：";
                        str+=COMPETE_D->user_fight_info(toplist[i]);
                                        
                }
                str+="——————————————————————————————————\n";
    me->start_more(str);
        return 1;
}

int help()
{
        write( @HELP
TOP指令用法：
top 显示目前总排行榜
top -p显示你的名次及参加比武的信息。
HELP
        );
        return 1;
}
