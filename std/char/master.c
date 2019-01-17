// master.c last update from lanxin@jianghu 99-2-9

#include <dbase.h>
#include <login.h>
#include <ansi.h>


string time_period(int timep);

int prevent_learn(object me, string skill)
{
        mapping my_family, family;
        int betrayer, mylvl, lvl;

        lvl = this_object()->query_skill(skill, 1);
        mylvl = me->query_skill(skill, 1);
        if(betrayer = me->query("betrayer")) 
        {
                if(mylvl >= lvl - betrayer * 20) 
                {
                        message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�\n"
                                + "Ҳ��������$p��ǰ����ʦ�ŵ�����\n"
                                + "...��\n", this_object(), me );
                        command("say �� .... \n"
                                + "ʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
                        return 1;
                }
        }

        if(!me->is_apprentice_of(this_object())) 
        {
                if(!mapp(my_family = me->query("family"))) 
                        return 0;
                if(!mapp(family = this_object()->query("family"))) 
                        return 0;
                if((my_family["family_name"] == family["family_name"]))
                //&& (lvl <=  mylvl * 3 )) 
                {
                        command("hmm");
                        command("pat " + me->query("id"));
                        command("say ��Ȼ���������µĵ��ӣ����ǲ����ҵĵմ�����....");
                //      command("say ��ֻ�ܽ�����Щ��ǳ�ı��Ź���"
                //      + "�����Ļ���ȥ����ʦ��ѧ�ɡ�");
                        command("say ����ȥ����ʦ��ѧ�ɡ�");
                        return 1;
                }
        }

        return 0;
}

int give_quest()
{
        int age, t, timep;
        mapping quest ;
        mixed *local;
        object me;
        string time_limit;

        me = this_player();

        // Let's see if this player is a ghost
        local = localtime(time() * 60);
        t = local[2] * 60 + local[1];       

        if((int)me->is_ghost())
        {
                write("��겻������Ҫ����\n");
                return 1;
        }

        if((string)me->query("family/master_name") != this_object()->name(1))
        {
                command("shake " + me->query("id"));
                command("say ����ȥ�����Լ���ʦ��Ҫ����ȥ�ɡ�\n");
                return 1;
        }

        if((age = me->query("age")) > 16)
        {
                command("pat " + me->query("id"));
                command("say " + me->name(1) + "��������ʮ����ͱ�����"
                        + "ʦ���������ˣ����Լ�ȥ���������ˡ�\n");
                return 1;
        }

        // Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if(((int) me->query("task_time")) > time())
                {
                        command("say �����Ȱ���������������˵�ɡ�\n");
                        return 1;
                } else
                        me->set("kee", me->query("kee") / 2 + 1);
                me->delete_temp("quest_number");
        }

        quest = QUEST_D("quest" + age)->query_quest();

        // each quest give 10 mins.
        timep = 600; 

        // A factor here to make time random
        timep = random(timep / 2) + timep / 2;

        //time_period(timep, me);
        time_limit = time_period(timep);

        if(quest["quest_type"] == "Ѱ")
                command("say ����" + time_limit + "ȥ������" + quest["quest"]
                        + "����");

        if(quest["quest_type"] == "ɱ")
                command("say ����" + time_limit + "ȥɱ�ˡ�" 
                        + quest["quest"] + "����");

        me->set("quest", quest);
        me->set("task_time", (int)time() + (int)timep);

        if((int)me->query_temp("quest_number") < 5)
        me->add_temp("quest_number", 1);

        return 1;
}

string time_period(int timep)
{
        int t, d, h, m, s;
        string time;

        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        return time;
}

int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
        string test;
        mapping quest;

        if(!(quest =  who->query("quest")))
                return 0;

        if((string)who->query("family/master_name") != this_object()->name(1))
        {
                command("say ����ȥ�������Լ���ʦ���ɡ�");
                return 0;
        }

        if((string)ob->query("name") != quest["quest"] || ob->is_character())
        {
                command("shake " + who->query("id"));
                command("say �ҿɲ���Ҫ�����⡣\n");
                return 0;
        }

        if((int)who->query("task_time") < time() )
        {
                command("sigh " + who->query("id"));
                command("say ��ϧ����" + who->name() + "����û��"
                        + "�ڸ�����ʱ�����������\n");
                return 1;
        } else {
                command("smile " + who->query("id"));
                command("say �����ģ�" + who->name()
                        + "����������úܺá�\n");
                exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;

                // put a limit here
                if(exp > 150) exp = 150;
                exp = exp * (int) who->query_temp("quest_number");
                pot = exp / 5 + 1;

                //score = quest["score"]/2 + random(quest["score"]/2);
                who->add("combat_exp",exp);
                who->add("potential",pot);
                //who->add("score",score);

                tell_object(who,HIW"�㱻�����ˣ�\n" +
                chinese_number(exp) + "��ʵս����\n"+
                chinese_number(pot) + "��Ǳ��\n"NOR);
                //chinese_number(score)+"���ۺ�����\n"NOR);
                who->set("quest", 0);
                return 1;
        }
        return 1;
}

void give_rank(object ob) {}
