
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("������",({ "pi shouxuan","pi"}) );
        set("gender", "����" );
        set("age", 42);
        set("str",30);
        set("title",HIY"����˫��"NOR);
        set("long","����а�̵�һ����֣�ƽʱ��������ٷ��衣\n");
        set("combat_exp",600000);
        
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_gin",3000);
        set("max_force",3000);
        set("force",3000);
        set("attitude","aggressive");
        set_skill("parry",170);
        set_skill("dodge",170);
        set_skill("force",170);
        
        set_skill("whip",170);
        set_skill("fengyu-fuchen",170);
        set_skill("babu-ganchan",170);
    setup();
   carry_object(__DIR__"obj/fuchen")->wield();
  
}

void noway(object ob)
{
   ob->delete_temp("kill_man1");
   ob->delete_temp("kill_man2");
   ob->delete_temp("kill_man3");
   ob->delete_temp("kill_man4");
   return;
}
void clear(object ob)
{
  ob->delete_temp("kill_man1");
   ob->delete_temp("kill_man2");
   ob->delete_temp("kill_man3");
   ob->delete_temp("kill_man4");
   return;
}
   
void die()
{
  object ob;
  object book;
  ob=query_temp("last_damage_from");
  if(!ob||!ob->query_temp("dtsl_quest_bsy/step2")) return ::die();
  if(!ob->query_temp("kill_man1"))
   ob->set_temp("kill_man1","������");
  else if(!ob->query_temp("kill_man2"))
   ob->set_temp("kill_man2","������");
  else if(!ob->query_temp("kill_man3"))
   ob->set_temp("kill_man3","������");
  else if(!ob->query_temp("kill_man4")){
   
   ob->set_temp("kill_man4","������");
   if(ob->query("kar")<=15){
   	if(ob->query_temp("kill_man1")!="��¡"||
           ob->query_temp("kill_man2")!="�����"||
           ob->query_temp("kill_man3")!="������"||
           ob->query_temp("kill_man4")!="������"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=20){
   	if(ob->query_temp("kill_man1")!="�����"||
           ob->query_temp("kill_man2")!="������"||
           ob->query_temp("kill_man3")!="������"||
           ob->query_temp("kill_man4")!="��¡"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=25){
   	if(ob->query_temp("kill_man1")!="������"||
           ob->query_temp("kill_man2")!="��¡"||
           ob->query_temp("kill_man3")!="������"||
           ob->query_temp("kill_man4")!="�����"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=30){
   	if(ob->query_temp("kill_man1")!="������"||
           ob->query_temp("kill_man2")!="�����"||
           ob->query_temp("kill_man3")!="��¡"||
           ob->query_temp("kill_man4")!="������"){
            noway(ob);return ::die();}}
   clear(ob);
   book=new(__DIR__"obj/busi-yin");
   book->move(this_object());
   ob->delete_temp("dtsl_quest_bsy/step2");
   ob->set("dtsl_quest_bsy_ok",1);
  return ::die();}
  return ::die();
}
