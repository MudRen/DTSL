// ����˫����

//�����


inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
  set_name("����׿", ({"fu junzhuo", "fu", "junzhuo"}));
  set("gender", "Ů��");
 
  set("per",26);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",4000);
  set("combat_exp",600000);
  set_skill("unarmed", 182);
  set_skill("strike",182);
  set_skill("leg",182);
  set_skill("literate", 182);
  set_skill("sword", 182);
  set_skill("force", 182);
  set_skill("dodge", 182);
  set_skill("parry", 182);
  
  set_skill("jiuxuan-dafa",182);
  set_skill("fengxue-leg",182);
  set_skill("jiuzhuan-jianjue",182);
  set_skill("xingyun-dodge",182);
  
  set("inquiry",([
   "����":(:do_action1:),
  ]));
 
  setup();
  
  create_family("�Ľ���",4, "����");

}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_csj_action2")){
    command("heng");
    return 1;
  }
  if(ob->query("age")>20){
    command("say ��ô�����ˣ����Լ������ܱ������ߣ���");
    return 1;
  }
  if(ob->query("age")<15){
    command("say С���ѣ��������ôС�����ǿ�ؼҰɣ�");
    return 1;
  }
 
  command("say ԭ���㱻���Ļ����ǹ���׷ɱ����������߲����˰ɣ�");
  ob->delete_temp("dtsl_quest_csj_action2");
  ob->set_temp("dtsl_quest_csj_action3",1);
  
  command("guard "+ob->query("id"));
  return 1;
}

void kill_ob(object ob)
{
  if(userp(ob)){
     command("say heng");
     ob->unconcious();
     remove_killer(ob);
     ob->remove_killer(this_object());
     return;
  }
  remove_call_out("check_fight");
  call_out("check_fight",1,ob,1);
  ::kill_ob(ob);
}

void check_fight(object ob,int i)
{
  object target;
  
  if(!ob){
    command("say ���գ����գ�");
    return;
  }
  if(!is_fighting(ob)) return;
  
  i++;
  
  if(i>=10){
    message_vision(HIR"$N�˵���Щ�����ˣ�\n"NOR,this_object());
    command("say �ߣ��ȱ�������Ҫ�������Ը��㣡");
    target=query_temp("guardfor");
    if(!target){
      command("say �ã����������ͬ���ھ�����");
      ob->die();
      die();
      return;
    }
    message_vision("\n$N����$n�����������ˣ�\n\n",this_object(),target);
    ob->do_command("say �������ٿ������ǣ�����\n");
    target->move("/d/quest/csj/shangu");
    move("/d/quest/csj/shangu");
    set("eff_kee",1);
    set("kee",1);
    set("force",0);
    destruct(ob);
    call_out("do_quest",3,target);
    return;
  }
  call_out("check_fight",1,ob,i);
}

void do_quest(object target)
{
  if(!target) return;
  if(environment(target)!=environment(this_object()))
  return;
  
  command("say ��֧�ֲ��˶೤ʱ���ˣ����������Ҳ��Ե��һ����\n"+
          "�Ҿʹ��ڸ������ѧ�����Ĺ���ϣ�����ܸ��ұ���\n");
  target->set("dtsl_quest_csj_ok",1);
  
  die();
  return;
}
