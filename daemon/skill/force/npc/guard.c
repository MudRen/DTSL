

inherit NPC;

#include <ansi.h>
#include <job_money.h>

int do_action1();

void create()
{
   set_name("����",({ "guard" }) );
   set("gender", "����" );		
   set("age",30);
      
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
  
   setup();
  
}

int set_status(object ob)
{
   set("combat_exp",ob->query("combat_exp"));
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   set_all_skill(this_object(),ob->query("max_pot")-90);
   set("name",ob->name()+"�Ļ�Ӱ");
   command("guard "+ob->query("id"));
   return 1;
}

void die()
{
   destruct(this_object());
}