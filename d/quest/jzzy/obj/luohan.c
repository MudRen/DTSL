
inherit ITEM;
#include <ansi.h>


void create()
{
   set_name("�޺�����", ({ "luo han"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "ͭ");
     set("unit", "��");
     set("value",10000);
   }
   setup();
}

void init()
{
 // add_action("do_search","search");
 // add_action("do_mofang","mofang");
  add_action("do_jieyin","jieyin");
}

int is_get_of(object ob,object me)
{
  return notify_fail("��ô���Ķ�����Ҳ�ܰ�������\n");
}

string long()
{
  object ob;
  ob=this_player();
  /*
  if(ob->query_temp("dtsl_quest_jzzy/step8")){
    ob->set_temp("dtsl_quest_jzzy/step9",1);
    ob->delete_temp("dtsl_quest_jzzy/step8");
    return "�޺����������ӡ���ƺ�����͸����ͬ����ӡ��\n"+
           "��ͨü���֡����ֺͶ��ֵ�������\n";}
  */
  //if(!ob->query_temp("dtsl_quest_jzzy/step1"))
  return "����һ���޺�������\n";
  /*
  ob->set_temp("dtsl_quest_jzzy/step2",1);
  ob->delete_temp("dtsl_quest_jzzy/step1");
  return "�������޺���ǰ�����������������µ������У�\n"+
         "�Ǹо�ʵ���κ��������������һ��\n";
  */
}
/*
int do_search()
{
  object ob;
  object killer;
  
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_jzzy/step2"))
  return 0;
  message_vision("$N�����Ѳ���һ�ᣬʲôҲû�ҵ���\n",ob);
  if(random(ob->query("kar"))<5)
  return 1;
  ob->set_temp("dtsl_quest_jzzy/step3",1);
  ob->delete_temp("dtsl_quest_jzzy/step2");
  killer=new(__DIR__"killer");
  set_all_skill(killer,ob->query("max_pot")-90);
  copy_hp_item(ob,killer,"gin");
  copy_hp_item(ob,killer,"kee");
  copy_hp_item(ob,killer,"sen");
  killer->set("max_force",ob->query("max_force"));
  killer->set("force",ob->query("max_force"));
  tell_object(ob,BLU"���Ȼ����һ��������������\n"NOR);
  tell_object(environment(ob),"\nͻȻ����һ��������������\n\n");
  killer->move(environment(ob));
  killer->kill_ob(ob);
  return 1;
}

int do_mofang(string arg)
{
 object ob;
 
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_jzzy/step4"))
  return 0;
  if(!arg||(arg!="left"&&arg!="right"))
  return 0;
  if(arg=="left"){
  message_vision("$N׿����������֮�䣬���Ȱڳ��ұ�������������ƣ�\n"+
                 "�����ֱ任���ұ�ŭĿ��յ���̬����άФά���\n"+
                 "�����Ƶ���ɫ��ӳ�£���������΢���ĵƻ𣬼���\n"+
                 "��$N��Ȼ����Ϊ������޺�������������һ���޺���\n"+
                 "�˹��������ָо�ȷ�ǹ������ס�\n",ob);
  ob->set_temp("mofang_left_ok",1);}
  if(arg=="right"){
  message_vision("$N����ͷ�ϵ�ȭͷٿ���ƺ󣬹ո���󣬹���������\n"+
                 "ǡ��ŭĿ���������������̬����һ��ȴ����ǰ��\n"+
                 "�����Ǻ��������Ȧ�ӡ�\n",ob);
  ob->set_temp("mofang_right_ok",1);}
  if(ob->query_temp("mofang_right_ok")&&
     ob->query_temp("mofang_left_ok")){
     ob->set_temp("dtsl_quest_jzzy/step5",1);
     ob->delete_temp("dtsl_quest_jzzy/step4");
     ob->delete_temp("mofang_right_ok");
     ob->delete_temp("mofang_left_ok");}
  return 1;
}
*/

int do_jieyin(string arg)
{
   object ob;
   int flag2;
   int flag;
   
   ob=this_player();
   
   if(ob->query("gender")=="Ů��")
   return notify_fail("��ʲôҲ���򲻳�����\n");
   
   if(ob->query("dtsl_quest_jzzy_ok")){
    /*
    if(ob->query("gin")<100)
    return notify_fail("�����ͷ�Ի�����޷����������Եľ��ϡ�\n");
    if(ob->query("force")<20)
    return notify_fail("�������΢�����޷��������������ԡ�\n");
    if(ob->is_busy()||ob->is_fighting())
    return notify_fail("����æ���أ�\n");
    ob->receive_damage("gin",100);
    ob->add("force",-20);
    ob->improve_skill("jiuzi-zhenyan",ob->query_int()+random(ob->query_int()/3));
    ob->start_busy(random(2));
    message_vision("$N���Ծ��������������ϣ�����΢�飬������֮���ţ�\n"+
                  "�������������ྮ��״����ˮ�����ֻ�Ϊ���ַ���ʮָ\n"+
                  "��ʣ��仯�����ֲ�ͬ����ӡ��\n",ob);
   */
   return notify_fail("$N���Ծ��������������ϣ�����΢�飬������֮���ţ�\n"+
                      "�������������ྮ��״����ˮ�����ֻ�Ϊ���ַ���ʮָ\n"+
                      "��ʣ��仯�����ֲ�ͬ����ӡ��\n");
   return 1;}
   if(ob->query("perform_quest/jzzy_fail"))
   return notify_fail("��ʲôҲ���򲻳�����\n");
   
   if(!ob->query_temp("dtsl_quest_jzzy_action2"))
   return 0;
   if(ob->query("bellicosity")>100)
   return notify_fail("������������ң��޷�����������\n");
   
   ob->delete_temp("dtsl_quest_jzzy_action2");
   message_vision("$N���Ծ��������������ϣ�����΢�飬������֮���ţ�\n"+
                  "�������������ྮ��״����ˮ�����ֻ�Ϊ���ַ���ʮָ\n"+
                  "��ʣ��仯�����ֲ�ͬ����ӡ��\n",ob);
   
   flag=ob->query_quest_kar();
   flag2=ob->query_kar();
   if(random(flag2)>29){
     tell_object(ob,"\n����������ˡ��������ԡ���\n");
     ob->set("dtsl_quest_jzzy_ok",1);
     ob->set_skill("jiuzi-zhenyan",10);
   }
   else{
     tell_object(ob,"����Բ��㣬�����޷����򡸾������ԡ��ˡ�\n");
     ob->add("perform_quest/jzzy_fail_times",1);
     if(ob->query("perform_quest/jzzy_fail_times")>=2){
     	ob->set("perform_quest/jzzy_fail",1);
     	tell_object(ob,"\n��������ԶҲ����������������ˡ�\n");
     }
  }
  // call_out("man_come",ob->query("kar"),ob);
   return 1;
}

/*
void man_come(object ob)
{
   object man,*inv;
   
   if(random(100)<90)
    return;
   
   inv=all_inventory(environment(ob));
   if(sizeof(inv)>1)
    return;
   
   if(!ob) return;
   if(base_name(environment(ob))!="/d/quest/jzzy/baodian")
   return;
   man=new(__DIR__"zhenyan-dashi");
   man->move(environment(ob));
   tell_object(environment(ob),"һ����ɮ�����˹�����\n");
   call_out("man_go",120,man);
   return;
}

void man_go(object ob)
{
  if(!ob) return;
  message_vision("$N�����߿��ˡ�\n",ob);
  destruct(ob);
  return;
}
*/ 
