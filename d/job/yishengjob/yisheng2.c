
inherit NPC;

#include <ansi.h>
#include <job_money.h>

int item_player();
int cancel_me();
mapping yaoname=([
RED"�컨"NOR:"honghua",
YEL"��Ƥ"NOR:"chenpi",
HIY"�˲�"NOR:"renshen",
GRN"����"NOR:"danggui",
HIC"ѩ��"NOR:"xuelian",
BLU"����"NOR:"shengdi",
MAG"������"NOR:"heshouwu",
]);

mapping itemname=([
"��Ѫ��":"��Ѫ",
"������":"����",
"������":"��Ѫ",
]);
void create()
{
  set_name("ҩʦ", ({ "yao shi", "shi" }));
  set("age", 60);
  set("gender", "����");
  set("long", "һ��ҩʦ��\n");
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
        "job":   (: item_player:),
        "����":   (: cancel_me:),
      ]));
  setup();

}

int item_player()
{
  string *strs = ({
    "$N��$n˵����  ��ļ��������ˣ�Ӧ�ÿ�������",
    "$N����˵���ҿ����ڵļ��������������",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *itemn,*itemid1;int itemz;
  string *n,*id1;int z;

 if(who->query("combat_exp")<100000){
	   	
		command("hehe");
		command(
 		  "say �㻹����ȥ��һ���ҩ���Ҳ�ҩ�ɣ�\n");
		return 1;
	    }

 if (who->query_temp("quest/yaoitem"))
  {
    message_vision ("$N��$n˵�����㲻�Ǵ�Ӧ��������"+who->query_temp("quest/yaoitem/name")+"����ô��û����\n",me,who);
    return 1;
 } 
if(time()-who->query("busy_time")<30){
	   	
		command("hehe");
		command(
 		  "say ����������ʱ��ȱ�������Ȼ�ɣ�\n");
		return 1;
	    }

 
   n=keys(yaoname);
  z=random(sizeof(n));  
//  if(z%2!=0) z++;
//   if(z==sizeof(yaoname)-1)
//    z=z-2;  
   id1=yaoname[n[z]];
   itemn=keys(itemname);
  itemz=random(sizeof(itemn));  
//  if(itemz%2!=0) itemz++;
//   if(itemz==sizeof(itemname))
//    itemz=itemz-2;  
   itemid1=itemname[itemn[itemz]];
  who->set_temp("quest/yaoitem/name", itemn[itemz]);
  who->set_temp("quest/yaoitem/id", itemid1);
  who->set_temp("quest/yaoitem/med", n[z]);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+itemn[itemz]+
        "�ˣ�\n��λ"+RANK_D->query_respect(who)+
        "����ȥ������һ������ס��Ҫ��"+n[z]+"����\n";

  message_vision (str,me,who);
  return 1;
}


int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/yaoitem"))
	   
	{
	   command("bite");
	   command("say ����û����������ƶ��������ʲô��������\n");
	   return 1;
       }
	
	JOBSYS_D->do_cancel_job("yishengjob2",me,this_object());
	command("say û�õĶ�������\n");
        return 1;
}

string no_color(string arg)
{
        arg = replace_string(arg,BLK, "");
	arg = replace_string(arg,RED, "");
	arg = replace_string(arg,GRN, "");
	arg = replace_string(arg,YEL, "");
	arg = replace_string(arg,BLU, "");
	arg = replace_string(arg,MAG, "");
	arg = replace_string(arg,CYN, "");
	arg = replace_string(arg,WHT, "");
	arg = replace_string(arg,HIR, "");
	arg = replace_string(arg,HIG, "");
	arg = replace_string(arg,HIY, "");
	arg = replace_string(arg,HIB, "");
	arg = replace_string(arg,HIM, "");
	arg = replace_string(arg,HIC, "");
	arg = replace_string(arg,HIW, "");
	arg = replace_string(arg,NOR, "");
	arg = replace_string(arg,BLINK, "");
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
  string name,jname,*mname,jmname,*heal_types,heal_type;
  int t,heal_num;
  string reason;
  
  if (who->query_temp("yaojobkiller_come"))
  {
    return notify_fail(query("name")+"��"+who->name()+"˵���������������˾�����һ�����棬̫�Ǹ����ɣ���\n");
   
  }

  if (! who->query_temp("quest/yaoitem")||ob->query("id")!="medicine")
  {
    return notify_fail(query("name")+"��"+who->name()+"˵���������ڲ�ȱ����������Ҳû�á�\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  /*
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/yaoitem/name"));
  jmname=no_color(who->query_temp("quest/yaoitem/med"));
  mname=no_color(ob->query("makeby"));
  */
  name=(ob->query("name"));
  jname=(who->query_temp("quest/yaoitem/name"));
  jmname=(who->query_temp("quest/yaoitem/med"));
  mname=(ob->query("makeby"));
  
  if (jname !=name)
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҽ��������"+
		    who->query_temp("quest/yaoitem/name")+
                    "����ȴ����������"+ob->query("name")+"������ʲô��˼��\n");
   
  }

  if (member_array(jmname,mname)==-1)
  {
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҽ���������ĵ�ҩ����"+
		    who->query_temp("quest/yaoitem/med")+
                    "���Ƶģ���ȴ���ҵ�ҩ��ȴû�����ԭ�ϣ�����ʲô��˼��\n");   
  }

  if (member_array(who->query_temp("quest/yaoitem/id"),keys(ob->query("heal_up")))==-1)
  {
    
    heal_types=keys(ob->query("heal_up"));
    heal_type="";
    for(heal_num=0;heal_num<sizeof(heal_types);heal_num++)
     heal_type+=heal_types[heal_num]+" ";
    
    return notify_fail(query("name")+"��"+who->name()+"˵�����ҵ�������"+who->query_temp("quest/yaoitem/name")+
                    "��������ͦ�󣬵�����ͬһ������\n��Ҫ����������("+who->query_temp("quest/yaoitem/id")+")�ģ�������������("+
                    heal_type+")����ģ�\n");
  }

  if (who->query("combat_exp") >=800000)
  {
  if (!who->query_temp("yaojobkiller"))
  {
        cob=new("/obj/medicine/medicine");	
	cob->set("name",ob->query("name"));
	cob->set("type",ob->query("type"));
	cob->set("makeby",ob->query("makeby"));
	cob->set("value",ob->query("value"));
	cob->set("long",ob->query("long"));
	cob->set("heal_up",ob->query("heal_up"));
	cob->set("medicine_type/type",ob->query("medicine_type/type"));
	cob->set("medicine_type/heals",ob->query("medicine_type/heals"));
     killer = new("/d/job/yishengjob/killer");    
     lvl=who->query_temp("yaojob/level");     
     where=killer->invocation(who,lvl);
     message_vision ("��Ȼ�䣬һ�������˳��˳�����һ������$n���е�"+ob->query("name")+"��Ȼ����Ŷ�����\n",me,who);
     message_vision ("$nƴ����׷�˳�ȥ����\n",me,who);
     who->set_temp("yaojobkiller_come",1);
     who->add_temp_array("job_temp_killer",killer);
     who->move(environment(killer));     
     cob->move(killer);
     
   return 1;
  }
}
  
  reason = "��������"+ob->query("name")+"��";
  message_vision ("$N��$n˵������"+reason+"�����Ҫ�úý����㣡\n",me,who);    
  JOBSYS_D->give_reward_yishengjob2(who);
  who->delete_temp("quest/yaoitem");
  who->delete_temp("yaojobkiller");
  who->set("busy_time",time());  
  return 1;
}


