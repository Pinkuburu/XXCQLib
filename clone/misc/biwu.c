//  比武厅
// by netkill@cctx
//Modify congw@CCTX

#include <ansi.h>
inherit ROOM;
string look_bei();

void create()
{
        set("short", HBMAG HIY "华山绝顶"NOR );
        set("long", 
"\n              "+HBWHT HIW"这里是华山的绝顶，山高不可测，四面云海茫茫。\n\n"NOR+
"   一边是陡峭的悬崖，一边是险峻的山路。唯有此处有一约两三丈宽的平地，多少年\n"+
"来，数不清的英雄豪杰在此殊死相博，为求天下第一的称号。西面立的有一块"+BMAG HIY "碑"NOR+"(bei),\n"+
"东边有一小凉亭，供人休息之用。\n"

        );
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("exits", ([ 
                "down" : "/d/huashan/bshanlu",
                ]));
        set("no_clean_up", 0);
        set("item_desc", ([
                "bei" : (: look_bei :),
        ]));
	set("objects", ([
        "/adm/zi" : 1,
        ]));
        
        setup();
}

int init()
{               
        object me=this_player();
        if ( !me->query_temp("biwu")) 
                me->set_temp("biwu",1); 
                
}

int valid_leave(object me, string dir)
{              
        if ( dir=="down") me->delete_temp("biwu");
        return ::valid_leave(me, dir);

}



string look_bei()
{       
        string use,str;
        int i,j;
        use= HIW"\n★★★"NOR+HIY"「小雪初晴英雄谱」"+HIW"★★★\n\n"NOR+WHT"_______________________\n"NOR;
        for ( i=2; i<=20; i=i+2)
        {
        	
              str=read_file("/data/ladder.txt",i,1);
	      
               if(str && !(str==""))
                {
                use+=sprintf(HBGRN HIR"【 第 %s 名 】\n"NOR HIG,chinese_number(i/2));
                use+=str;
               } 
              str=read_file("/data/ladder.txt",i+1,1);
		 if( str && !(str==""))
		 {use+=str;use+=WHT"_______________________\n"NOR;}
	
        }
        return (use);
        
}
