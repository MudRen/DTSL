
inherit NPC;

#include <ansi.h>
#include <job_money.h>

int test_player();
int cancel_me();
mapping tiename=([
RED"������"NOR:"hongtie",
YEL"������"NOR:"chengtie",
HIY"������"NOR:"huangtie",
GRN"������"NOR:"lvtie",
HIC"������"NOR:"qingtie",
BLU"������"NOR:"lantie",
MAG"������"NOR:"zitie",
//"������":"hongtie",
//"������":"chengtie",
//"������":"huangtie",
//"������":"lvtie",
//"������":"qingtie",
//"������":"lantie",
//"������":"zitie",
]);
void create()
{
  set_name("����", ({ "tie jiang", "tie" }));
  set("age", 60);
  set("gender", "����");
  set("long", "һ��������\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 80);
  set("target_id","###");
  set("inquiry", ([
        "job":   (: test_player:),
        "����":   (: cancel_me:),
      ]));
  setup();

}

int test_player()
{
  string *strs = ({
    "$N��$n˵����  ����������װ������Ҫ",
    "$N����˵�������������ڼ���",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *n,*id1;int z;

if(who->query("combat_exp")>100000){
	   	
		command("hehe");
		command(
 		  "say ��ľ����Ѿ����ߵ��ˣ�ȥ���������æ�ɣ�\n");
		return 1;
	    }

 

  if (who->query_temp("quest/tie"))
  {
    message_vision ("$N��$n˵�����㲻�Ǵ�Ӧ������"+who->query_temp("quest/tie/name")+"����ô��û����\n",me,who);
    return 1;
  }

if(time()-who->query("busy_time")<30){
	   	
		command("hehe");
		command(
 		  "say ����������ʱ��ȱ�������Ȼ�ɣ�\n");
		return 1;
	    } 
  n=keys(tiename);
  z=random(sizeof(n));  
/*
  if(z%2!=0) z++;
   if(z==sizeof(tiename)-1)
    z=z-2;  
*/
   id1=tiename[n[z]];
  who->set_temp("quest/tie/name", n[z]);
  who->set_temp("quest/tie/id", id1);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+n[z]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "��ȥ���ɽ�ϰ��Ҳɵ�����ɣ�\n";

  message_vision (str,me,who);
  return 1;
}

int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/tie"))
	   
	{
	   command("bite");
	   command("say ����û������Ҳɿ����ʲô��������\n");
	   return 1;
       }
        JOBSYS_D->do_cancel_job("tiejiangjob1",me,this_object());
	
	command("say û�õĶ�������\n");
        return 1;
}

string no_color(string arg)
{
      arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}


int accept_object(object who, object ob)
{
  object me = this_object();
  string name,jname,reason;
  int t;


  if (! who->query_temp("quest/tie"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵���������ڲ�ȱ����������Ҳû�á�\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/tie/name"));
  if (jname !=name)
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҽ�����Ҳ�"+
		    who->query_temp("quest/tie/name")+
                    "����ȴ���Ҹ�"+ob->query("name")+"������ʲô��˼��\n");
   
  }

  if (who->query_temp("quest/tie/id") != ob->query("id"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҵ�������"+who->query_temp("quest/tie/name")+
                    "��������ͦ�󣬵�����ͬһ��������Ҫ����("+who->query_temp("quest/tie/id")+")����������("+
                    ob->query("id")+")��\n");
  }
  
  reason = "���Ҳɵ�"+ob->query("name")+"��";
  message_vision ("$N��$n˵������"+reason+"�����Ҫ�úý����㣡\n",me,who);
  
  JOBSYS_D->give_reward_tiejiangjob1(who);
  who->delete_temp("quest/tie");
  who->set("busy_time",time());  
 
  return 1;
}
