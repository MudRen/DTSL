
inherit NPC;
#include <ansi.h>
void create()
{
   set_name(HIB"����"NOR,({ "horse"}) );
        set("race", "Ұ��" );
     set("long", "����һƥľ�Ƶ�����\n");
     set("verbs",({"hoof"}));
	 set("limbs",({"ͷ","��","����"}));
  setup();

}
void clear(object ob)
{
  ob->delete_temp("kill_horse1");
  ob->delete_temp("kill_horse2");
  ob->delete_temp("kill_horse3");
  return;
}
void noway(object ob)
{
  message_vision(HIR"ֻ��ľ���ڲ��������˼�����ľ��ͻȻѸ�ݵس�$N��ȥ������$N�ĸ�����"NOR,ob);
  clear(ob);
  ob->unconcious();
  return;
}
void die()
{
  object ob;
  ob=query_temp("last_damage_from");
  if(!ob) return ::die();
  if(!ob->query_temp("kill_horse1"))
   ob->set_temp("kill_horse1","����");
  else if(!ob->query_temp("kill_horse2"))
   ob->set_temp("kill_horse2","����");
  else if(!ob->query_temp("kill_horse3")){
   
   ob->set_temp("kill_horse3","����");
   if(ob->query("kar")<=15){
   	if(ob->query_temp("kill_horse1")!="����"||
           ob->query_temp("kill_horse2")!="����"||
           ob->query_temp("kill_horse3")!="����"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=20){
   	if(ob->query_temp("kill_horse1")!="����"||
           ob->query_temp("kill_horse2")!="����"||
           ob->query_temp("kill_horse3")!="����"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=25){
   	if(ob->query_temp("kill_horse1")!="����"||
           ob->query_temp("kill_horse2")!="����"||
           ob->query_temp("kill_horse3")!="����"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=30){
   	if(ob->query_temp("kill_horse1")!="����"||
           ob->query_temp("kill_horse2")!="����"||
           ob->query_temp("kill_horse3")!="����"){
            noway(ob);return ::die();}}
   clear(ob);
   tell_object(ob,HIG"ֻ��ǽ�Ͽ��꼸��������ֳ�һ���ڶ�����\n"NOR);
   ob->set("super_force_tujue_no_horse",1);
  environment(ob)->set("exits/enter",__DIR__"tujue");
  call_out("del_enter",5,environment(ob));
  return ::die();}
  return ::die();
}

void del_enter(object ob)
{
  ob->delete("exits/enter");
  remove_call_out("del_enter");
}