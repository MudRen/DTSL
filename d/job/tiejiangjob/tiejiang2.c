
inherit NPC;

#include <job_money.h>
#include <ansi.h>

int item_player();
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

mapping itemname=([
"����":"blade",
"����":"sword",
"��ǹ":"spear",
"����":"fork",
"����":"whip",
"����":"staff",
"��ذ��":"dagger",
]);
void create()
{
  set_name("������", ({ "datie gong", "gong" }));
  set("age", 60);
  set("gender", "����");
  set("long", "һ����������\n");
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
        "����":   (: item_player:),
        "����":   (: cancel_me:),
      ]));
  setup();

}

int item_player()
{
  string *strs = ({
    "$N��$n˵����  ��ļ��������ˣ�Ӧ�ÿ��Դ���",
    "$N����˵���ҿ����ڵļ���������Դ���",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *itemn,*itemid1;int itemz;
  string *n,*id1;int z;

 if(who->query("combat_exp")<100000){
	   	
		command("hehe");
		command(
 		  "say �㻹����ȥ��һ������������ɣ�\n");
		return 1;
	    }

 if (who->query_temp("quest/item"))
  {
    message_vision ("$N��$n˵�����㲻�Ǵ�Ӧ���Ҵ���"+who->query_temp("quest/item/name")+"����ô��û����\n",me,who);
    return 1;
 } 
if(time()-who->query("busy_time")<5){
	   	
		command("hehe");
		command(
 		  "say ����������ʱ��ȱ�������Ȼ�ɣ�\n");
		return 1;
	    }

 
   n=keys(tiename);
  z=random(sizeof(n));  

   id1=tiename[n[z]];
   itemn=keys(itemname);
  itemz=random(sizeof(itemn));  

   itemid1=itemname[itemn[itemz]];
  who->set_temp("quest/item/name", itemn[itemz]);
  who->set_temp("quest/item/id", itemid1);
  who->set_temp("quest/item/med", n[z]);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+itemn[itemz]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "�ˣ���ȥ���Ҵ���һ�ѣ���ס��Ҫ��"+n[z]+"����\n";

  message_vision (str,me,who);
  return 1;
}


int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/item"))
	   
	{
	   command("bite");
	   command("say ����û������Ҵ��춫�������ʲô��������\n");
	   return 1;
       }
        JOBSYS_D->do_cancel_job("tiejiangjob2",me,this_object());
	
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
	string where;
	string type;
	int lvl;
	object killer;
	object cob;
  object me = this_object();
  string name,jname,mname,jmname;
  int t;
  string reason;
  
  if (who->query_temp("tiejobkiller_come"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵���������������˾�����һ�����棬̫�Ǹ����ɣ���\n");
   
  }

  if (! who->query_temp("quest/item")||!ob->query("metirial"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵���������ڲ�ȱ����������Ҳû�á�\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/item/name"));
  jmname=no_color(who->query_temp("quest/item/med"));
  mname=no_color(ob->query("metirial"));
  
  if (jname !=name)
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҽ�����Ҵ�"+
		    who->query_temp("quest/item/name")+
                    "����ȴ���Ҵ��"+ob->query("name")+"������ʲô��˼��\n");
   
  }

  if (mname !=jmname)
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҽ�����Ҵ�Ķ�������"+
		    who->query_temp("quest/item/med")+
                    "����ģ���ȴ������"+ob->query("metirial")+"��������ʲô��˼��\n");   
  }

  if (who->query_temp("quest/item/id") != ob->query("id"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҵ�������"+who->query_temp("quest/item/name")+
                    "��������ͦ�󣬵�����ͬһ��������Ҫ����("+who->query_temp("quest/item/id")+")����������("+
                    ob->query("id")+")��\n");
  }
  if (who->query("combat_exp") >=800000)
  {
  if (!who->query_temp("tiejobkiller"))
  {
      type=ob->query("skill_type");
      cob=new("/obj/weaponclass/"+type);	
      cob->set("name",ob->query("name"));
	cob->set("long",ob->query("long"));
      cob->set("weapon_prop/damage",ob->query("weapon_prop/damage"));
      cob->set("max_strong",ob->query("max_strong"));
	cob->set("metirial",ob->query("metirial"));
	cob->set("strong",ob->query("strong"));
	cob->set("flag",0);     
     killer = new("/d/job/tiejiangjob/killer");    
     lvl=who->query_temp("tiejob/level");     
     where=killer->invocation(who,lvl);
     message_vision ("��Ȼ�䣬һ�������˳��˳�����һ������$n���е�"+ob->query("name")+"��Ȼ����Ŷ�����\n",me,who);
     message_vision ("$nƴ����׷�˳�ȥ����\n",me,who);
     who->set_temp("tiejobkiller_come",1);
     who->add_temp_array("job_temp_killer",killer);
     who->move(environment(killer));     
     cob->move(killer);
     
   return 1;
  }
}
  
  reason = "���Ҵ���"+ob->query("name")+"��";
  message_vision ("$N��$n˵������"+reason+"�����Ҫ�úý����㣡\n",me,who); 
  
  JOBSYS_D->give_reward_tiejiangjob2(who);
  who->delete_temp("quest");
  who->delete_temp("tiejobkiller");
  who->set("busy_time",time());  
  return 1;
}

