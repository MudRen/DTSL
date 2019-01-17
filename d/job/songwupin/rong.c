//job.
// ����Ʒ����
#include <job_money.h>
#include <ansi.h>
inherit NPC;
string give_job();
mapping target=(["��������":"/d/yangzhou/npc/old","���ݶ�ͽ":"/d/yangzhou/npc/dutu",
"��������":"/d/yangzhou/npc/tiejiang","���ݰ��Ϸ���":"/d/yangzhou/npc/bai",
"���ݵĹ���":"/d/hangzhou/npc/gongzi",
"��������":"/d/baling/npc/tiejiang","������Τ��٢":"/d/changan/npc/weihua-tuo",
"�����ĵ����ϰ�������":"/d/changan/npc/tie","�����ξֵĹٲ�":"/d/changan/npc/guanchai",
"�Ϸʵ�����":"/d/hefei/npc/tiejiang","�Ž�Ǯׯ��Ǯ�ϰ�":"/d/jiujiang/npc/qian",
"�����Ĳ�ͷ":"/d/xiangyang/npc/butou","����������":"/d/xiangyang/npc/tiejiang",
]);
void create()
{
   set_name("�ٷ���",({ "rong fengxiang","rong","fengxiang" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����ǽ����������ٷ��飬�������Ѿ�˵�ܶࡣ\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
 /*  set("inquiry",([
     "��Ʒ":(:give_job:),
     ]));*/
   setup();
   carry_object(__DIR__"cloth")->wear();
  
}

string give_job()
{
  object me,ob;object thing;
  int i;string *jobs,str;
  me=this_player();
  ob=this_object();
  if(me->query_temp("job/rong_job"))
  return "�ҿɲ�ϲ�����������ˣ�\n";
  if(time()-me->query("busy_time")<90)
  return "�ҵ�������Ȼ�࣬��Ҳ�������Ǹ���������\n";
  if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   if(!valid_do_job(me,"rong"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
   me->set_temp("dtsl_job","�ٷ�������Ʒ����");
  me->set_temp("job/rong_job",1);
  jobs=keys(target);
  i=random(sizeof(jobs));
  thing=new(__DIR__"thing");
  thing->set("owner",target[jobs[i]]);
  thing->move(me);
  str= "�鷳"+RANK_D->query_respect(me)+"��ȥ��"+thing->name()+"\n"+
         "����(song)"+jobs[i]+"�ɣ�лл�ˣ�\n";
  if(me->query("combat_exp")>=150000)
  { call_out("killer_come",20+random(5),me);
    str+="·�ϻ������ҵĳ�ң���ҪС�ģ�\n";
  }
  return str;
}

void killer_come(object ob)
{
  object killer,letter;
  string kill_msg;
  if(!objectp(ob)){
  remove_call_out("killer_come");return;}
  if(!ob->query_temp("job/rong_job"))
  kill_msg="$N��$n�ȵ�������ֽŵ�ͦ�����ģ��������ɣ�\n";
  else kill_msg="$N��$n�ȵ����Һ��ٷ����ǳ�У����Ϊ�����£���������\n";
  killer=new(__DIR__"killer");
  ob->start_busy(1);
  message_vision(HIB"$NͻȻ����һ����紵����\n"NOR,ob);
  
        killer->set("kee",ob->query("max_kee"));
	killer->set("eff_kee",ob->query("max_kee"));
	killer->set("max_kee",ob->query("max_kee"));
	
	killer->set("gin",ob->query("max_gin"));
	killer->set("eff_gin",ob->query("max_gin"));
	killer->set("max_gin",ob->query("max_gin"));
	
	killer->set("sen",ob->query("max_sen"));
	killer->set("eff_sen",ob->query("max_sen"));
	killer->set("max_sen",ob->query("max_sen"));
	
	killer->set("combat_exp",ob->query("combat_exp"));
	killer->set("max_pot",ob->query("max_pot"));
	if(ob->query("combat_exp")<500000)
	set_all_skill(killer,ob->query("max_pot")-130);
	else
	if(ob->query("combat_exp")<1000000)
	set_all_skill(killer,ob->query("max_pot")-110);
	else
	if(ob->query("combat_exp")<2000000)
	set_all_skill(killer,ob->query("max_pot")-90);
	else
	set_all_skill(killer,ob->query("max_pot")-80);
  killer->set_temp("apply/armor",50+random(50));	 
  killer->move(environment(ob));
  message_vision(kill_msg,killer,ob);
  killer->set_leader(ob);
  killer->kill_ob(ob);
  return;
}