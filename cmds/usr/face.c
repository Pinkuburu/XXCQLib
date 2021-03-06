//face.c /cmds/usr/face.c 查看emote,星君千圣，1999.12.2.
#include <ansi.h>
inherit F_CLEAN_UP;
int help();

void input_number(string arg);
void print_emote(mapping emote);
void show_emote(string * s,string st);

int main(object ob,string arg)
{
    //还要加上直接list emote的。。
    mapping emote;
    if(arg)
    {
        emote = EMOTE_D->query_emote(arg);
        if(sizeof(emote)>0)
            print_emote(emote);
        else{
            input_number(arg[0..0]);
            return 1;
        }
    }
    write("输入第一个字母：");
    input_to( (: input_number :));
    return 1;
}

void input_number(string arg)
{
    string * emotes, * selected;

    int i;
    if(arg=="") return;
    selected=({});
    emotes=EMOTE_D->query_all_emote();
    for(i=0;i<sizeof(emotes);i++)
    {
        if(emotes[i][0..0]==arg)
            selected += ({emotes[i]});
    }
    if(sizeof(selected)==0)
    {
        printf("没有以%s开头的emote.\n输入第一个字母：",arg);
        input_to((: input_number :));
        return ;
    }
    for(i=0;i<sizeof(selected);i++)
    {
        printf("%2d.%-15s",i+1,selected[i]);
        if(i%4==3)
            printf("\n");
    }
    write("\n");
    printf("看哪一个呢：");
    input_to( (: show_emote,selected :) );
}

void show_emote(string * selected,string arg)
{
    mapping emote;
    string x;
    int i,index;
    if(arg=="")
    {
        write("\n输入第一个字母：");
        input_to( (: input_number :));
        return;
    }
    if(sscanf(arg,"%d",index)==1){
        if(index <= sizeof(selected) && index > 0)
        arg = selected [index-1];}
    else if(member_array(arg,selected)==-1)
    {
        write("没有这个emote啊，是哪个呢：");
        input_to((: show_emote,selected :));
        return;
    }
    emote = EMOTE_D->query_emote(arg);
    if(sizeof(emote)>0)
        print_emote(emote);
         write ("\n输入第一个字母：（退出直接敲回车)");
    input_to( (: input_number :));
}

void print_emote(mapping emote)
{    
    int i;
    string x;
    string * key = ({ "myself","others","myself_self","others_self",
        "myself_target","target","others_target", });
    write(RED"结果：（其中可能有些不对。。）\n\n"NOR);
    for(i=0;i<sizeof(key);i++)
    {
        x=emote[key[i]];
        if(!x)
        {
            write("---\n");
            continue;
        }
        x = replace_string(x,"$N",HIR"星君千圣"NOR);
        x = replace_string(x, "$P", "你");
        x = replace_string(x, "$z", "妹子");
        x = replace_string(x, "$F", "姑娘");
        x = replace_string(x, "$f", "贱人");
        x = replace_string(x, "$n", HIY"山猫"NOR);
        x = replace_string(x, "$p", "她");
        write(x);
    }
}

int help()
{
        write(HIY @TEXT

指令格式：face 这个指令方便你查看emote。
               退出时直接敲回车即可。

TEXT NOR
        );
        return 1;
}

