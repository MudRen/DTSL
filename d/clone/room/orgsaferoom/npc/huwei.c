

inherit NPC;

#include <ansi.h>

void create()
{
   set_name("����",({ "hu wei","hu","wei","orgsafe_guard" }) );
   set("gender", "����" );
   set("age",35);
   set("long", "����һ��������\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("finger",150);
   set_skill("dujie-zhi",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jue",150);
   set_skill("tianmo-huanzong",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   set("perform_quest/liudao",1);
   set_temp("apply/damage",100+random(100));
   set_temp("apply/armor",100+random(100));
   set_temp("apply/dodge",100+random(100));
   
   setup();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   if(stringp(environment(this_object())->query("shili/name")))
    set("shili/name",environment(this_object())->query("shili/name"));
   
   command("banghui �ұ�"+HIR+ob->name()+"ɱ���ˣ���λ�ֵ�С���ˣ�");
   command("chat* die "+query("id"));
   
   return ::die();
   
}