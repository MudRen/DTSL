
//Edit By Subzero

inherit NPC;
#include <ansi.h>

string do_quest();
string move_room();
int do_action1();

void create()
{
   int i;
   object *ob;
   set_name("����",({ "bi xuan","bi" }) );
   set("gender", "����" );		
   set("age", 42);
   set("long", "���������������������������ʦ֮һ\n");
       
   set("combat_exp",8000000);
   set("str", 35);
   set("per", 22);
   set_skill("unarmed",400);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",500);
   set_skill("blade",400);
   set_skill("literate",400);
   set_skill("cuff",500);
   set_skill("spear",400);
   set_skill("youlong-shenfa",400);
   set_skill("yanyang-dafa",500);
   set_skill("tianlang-zhi",400);
   set_skill("tianlang-dao",400);
   set_skill("canglang-jue",400);
   set_skill("fuying-spear",400);
   
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",15000);
   set("max_force",15000);
   set("jiali",150);
   create_family("ͻ��",2,"����");
   set("perform_quest/fengsha",1);
   set("perform_quest/fengyu",1);
   set("perform_quest/kuangsha",1);
   set("chat_chance_combat",100);
   set("chat_msg_combat",({
                (: command("perform fengyu") :),
                (: command("perform fengsha") :),
                (: command("exert riyue") :),
                (: command("perform lengyue") :),
                (: command("execute xiao") :),
        }));
   set("apply_points",2000);
   set("inquiry",([
	   "ͻ������":(:do_quest:),
	   "����":(:move_room:),
	   "��ս":(:do_action1:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
ob=children(__DIR__"obj/yinlong-spear");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/yinlong-spear")->wield(); 
}

string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("yanyang-dafa",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷���Ϊͻ������\n";
  if(ob->query("family_lingwu")=="tujue")
  return "���Ѿ��õ�����ĳƺţ�ȥ������߰ɡ�\n";
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_bi",1);
  
  obj=new(__DIR__"q_bi");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "�����Ϸ��֣����ľ�˱��֪�����ʵ����\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_bi"))
   return 1;
   message("vision",HIG"��ͻ  �ʡ�������������"+killer->name()+",������Ц����ͻ�ʴӴ��ֶ���һλ����\n"NOR,users());
   message_vision(HIR"$N���쳤Ц������ͻ�����ں�������ˣ�\n"NOR,victim);
   message_vision(HIR"$N΢΢һЦ����Ȼ�ܴ�ù��ң����ȥ�ҵ�����ѧϰ�ɣ�\n"NOR,victim); 
   killer->set("family_lingwu","tujue");
   killer->set("title","ͻ������");
   killer->move("/d/clone/room/lingwu/tujue/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_bi"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "ͨ����������ʵ��ɣ�\n";
  if(ob->query("family_lingwu")!="tujue")
  return "�㻹û�����ˮƽ��������Ҳû���õģ�\n";
  if(ob->query("super_force_tujue_no_horse"))
  	ob->move("/d/clone/room/lingwu/tujue/tujue");
  else
  	ob->move("/d/clone/room/lingwu/tujue/mishi");
  return "��Ը����������ͻ��һͳ��ԭ��\n";
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query_skill("huanri-dafa",1)||
     present("huanri book",ob)){
    command("say �ҿ����ǿ���֮�ţ����Զ�㣬�㻹�����ҵĶ��֣�");
    return 1;
  }
  
  if(ob->query_temp("dtsl_quest_huanri_action1")||
  	 ob->query("force_quest/hrdf_fail")){
    command("say �����ҵ����°ܽ���û���ʸ�������ս��");
    return 1;
  }
  
  if(ob->is_fighting()){
    command("say ���Ҵ��������������ʣ�\n");
    return 1;
  }
  if(ob->query("eff_kee")*100/ob->query("max_kee")<90){
    command("say ���Ѿ������ˣ��ҿɲ������\n");
    return 1;
  }
  
  command("say �ߣ�������·�㲻�ߣ�������������������������\n");
  kill_ob(ob);
  remove_call_out("check_fight");
  call_out("check_fight",1,ob);
  return 1;
}

void check_fight(object ob)
{
   if(!ob) return;
   if(!is_fighting(ob)) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!living(ob)) return;
   
   if(ob->query("eff_kee")*100/ob->query("max_kee")<=20){
     command("say �ߣ���˵�㲻���ҵĶ��֣���ξ�����С����\n");
     message_vision("\n$N�͵�ʹ�����춯��һ�У����û���$n��Ҫ����\n",
          this_object(),ob);
     ob->set_temp("dtsl_quest_huanri_action1",1);
     remove_killer(ob);
     ob->remove_killer(this_object());
     ob->unconcious();
     return;
   }
   call_out("check_fight",1,ob);
}
