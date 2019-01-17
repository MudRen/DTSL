

inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("ɱ��",({ "killer" }) );
   set("gender", "����" );		
   set("age",38);
   set("long", "����һ��ְҵɱ�֡�\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("spear",150);
   set_skill("literate",150);
  
   set_skill("yanyang-dafa",150);
   set_skill("canglang-jue",150);
   set_skill("youlong-shenfa",150);  
   set_skill("fuying-spear",150);
  
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
 
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/spear")->wield();
  
}

int set_status(object ob)
{
   
   set("combat_exp",ob->query("combat_exp"));
   set("target_id",ob->query("id"));
   
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   
   set("max_force",ob->query("max_force"));
   set("force",ob->query("max_force"));
   
   set_all_skill(this_object(),ob->query("max_pot")-130);
   
   return 1;
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob||
   query("target_id")!=ob->query("id"))
   return ::die();
   ob->set_temp("husong_badai_killer",1);
   return ::die();
}