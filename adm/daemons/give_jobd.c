//create by zanlin
//1999.8.22
#include <ansi.h>
int time_period(int timep, object me);
mapping query_quest();
string sysmsg;
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	mapping quest;
	if(!(quest =  who->query("quest")))
	{
       tell_object(who,this_object()->name()+"˵������ʲôʱ�������æ�ˣ�\n");
	return 0; 
	}
        if( (string)ob->query("name") != quest["quest"] || 
            (string)who->query("questnpc")!=this_object()->name())
        {
            tell_object(who,this_object()->name()+"˵�����ⶫ��������˵ûʲô�ô���\n");
            return 0;
        }
	if ((int) who->query("task_time") < time() )
        {
        return notify_fail(this_object()->name()+"˵�������ϧ���������Ѿ����Ǻܼ�����Ҫ���ˣ�\n");
        return 1;
        }
        else
        {
        tell_object(who,
              this_object()->name()+ "˵������������ô��Ͱ����ҵ��ˣ��ǳ���л�������������ء�\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
// put a cap
	if(exp > 150) exp = 150;
       if(who->query("quest_num"))
          exp = exp * (int) who->query("quest_num");
	pot = exp / 5 + 1;
//	score = quest["score"]/2 + random(quest["score"]/2);
//	score = -1;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("score",score);
       tell_object(who,HIW"������䣬�㷢���Լ������ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n" NOR);
	who->set("quest", 0 );
       call_out("destroy",1,ob);
       return 1;
        }
                return 1;
}

int give_job(string arg)
{
	mapping quest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
        string questmsg;
	me = this_player();
	//if((int) me->is_ghost())
//{
//		write("˵������\n");
//		return 1;
//	}


        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return notify_fail(this_object()->name()+"Ц��Ц��˵�����㻹�б����Ҫ���������������ˡ�\n");
       else
        if(me->query("quest_num"))me->delete("quest_num");
	}
    
 if(random(10)>1)
  {
     quest = query_quest();

      //	timep = quest["time"];	
	timep = 600;  
       tell_object(me,HIW+this_object()->name()+"˵����\n"NOR);
        if(questmsg=quest["msg"])
            tell_object(me,HIW+questmsg+NOR);
       tell_object(me,HIW+"���æ,"NOR);
	timep = random(timep/2)+timep/2;
	time_period(timep, me);

	if (quest["quest_type"] == "Ѱ")
	{
        tell_object(me,"�һء�"+quest["quest"]+"����"+"�ҡ�\n" NOR);
	sysmsg +="�һء�"+quest["quest"]+"����";
	}
	        if (quest["quest_type"] == "ɱ")
        {
        tell_object(me,"����ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
	sysmsg +="ɱ�ˡ�"+quest["quest"]+"����";
        }
 	me->set("quest", quest);
	me->set("task_time", (int) time()+(int) timep);
       me->set("questnpc",this_object()->name());
	 
       if(me->query("quest_num")<3)me->add("quest_num",1);
	
	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)��%s", 
	me->query("name"),me->query("id"),sysmsg));
       return 1;
}
 else 
 return notify_fail(this_object()->name()+"ҡ��ҡͷ��˵����������ûʲô�ż�����Ҫ���æ��\n");

}

int time_period(int timep, object me)
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

        tell_object(me,HIW + sprintf("%s","����" + time + "��"));
	 sysmsg = "��" + time + "��";
        return 1;
}
void destroy(object item)
{
 destruct(item);
}

