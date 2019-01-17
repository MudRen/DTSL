
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("ÓÈÄñ¾ë",({ "you niaojuan","you"}) );
        set("gender", "ÄÐÐÔ" );
        set("age", 42);
        set("str",30);
        set("long","Õâ¾ÍÊÇÐ°ÃÅ¸ßÊÖÖ®Ò»¡£\n");
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
        
        set_skill("staff",170);
        set_skill("dujiao-tongren",170);
        set_skill("babu-ganchan",170);
    setup();
   carry_object(__DIR__"obj/tongren")->wield();
  
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
   ob->set_temp("kill_man1","ÓÈÄñ¾ë");
  else if(!ob->query_temp("kill_man2"))
   ob->set_temp("kill_man2","ÓÈÄñ¾ë");
  else if(!ob->query_temp("kill_man3"))
   ob->set_temp("kill_man3","ÓÈÄñ¾ë");
  else if(!ob->query_temp("kill_man4")){
   
   ob->set_temp("kill_man4","ÓÈÄñ¾ë");
   if(ob->query("kar")<=15){
   	if(ob->query_temp("kill_man1")!="°²Â¡"||
           ob->query_temp("kill_man2")!="ÓÈÄñ¾ë"||
           ob->query_temp("kill_man3")!="×óÓÎÏÉ"||
           ob->query_temp("kill_man4")!="±ÙÊØÐþ"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=20){
   	if(ob->query_temp("kill_man1")!="ÓÈÄñ¾ë"||
           ob->query_temp("kill_man2")!="×óÓÎÏÉ"||
           ob->query_temp("kill_man3")!="±ÙÊØÐþ"||
           ob->query_temp("kill_man4")!="°²Â¡"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=25){
   	if(ob->query_temp("kill_man1")!="±ÙÊØÐþ"||
           ob->query_temp("kill_man2")!="°²Â¡"||
           ob->query_temp("kill_man3")!="×óÓÎÏÉ"||
           ob->query_temp("kill_man4")!="ÓÈÄñ¾ë"){
            noway(ob);return ::die();}}
   else
   if(ob->query("kar")<=30){
   	if(ob->query_temp("kill_man1")!="×óÓÎÏÉ"||
           ob->query_temp("kill_man2")!="ÓÈÄñ¾ë"||
           ob->query_temp("kill_man3")!="°²Â¡"||
           ob->query_temp("kill_man4")!="±ÙÊØÐþ"){
            noway(ob);return ::die();}}
   clear(ob);
   book=new(__DIR__"obj/busi-yin");
   book->move(this_object());
   ob->delete_temp("dtsl_quest_bsy/step2");
   ob->set("dtsl_quest_bsy_ok",1);
  return ::die();}
  return ::die();
}


