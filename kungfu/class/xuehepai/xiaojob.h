
int accept_object(object who, object ob)
{
        object sil;

        int i;
        if ((string)ob->query("id") == "shi tou")
        {
                if (!(who->query_temp("job_start")))
                {
                        command("say 我没教你去做，你却去帮忙。现在象你这样的好人不多啊。");
                        who->add("potential", 1+random(10));
                        who->add("combat_exp", 3+random(10));
                        who->delete_temp("find");
                        return 1;
                }
                else
                {
                        command("say 多谢，多谢，辛苦了，你去休息休息吧。");
                        who->delete_temp("job_start");
                        who->delete_temp("find");
                        who->add("potential", 50+random(50));
                        who->add("combat_exp", 75+random(75));
                        for (i=1;i<11;i++)
                        {
                        sil = new("/clone/money/silver");
                        sil->move(who);
                        }
                        if (!(who->query("xiaojob")))
                        who->set("xiaojob",1);
                        else who->add("xiaojob",1);
                        return 1;
                }
        }
       else
        {
                command("say 你给我这个干什么?");
                return 0;
        }
        
}


