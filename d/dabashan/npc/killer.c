
inherit JOBNPC;
#include <job_money.h>


void create()
{
   set_name("������",({ "man" }) );
        set("gender", "����" );
        set("long", "����һ�����������������ˡ�\n");
       
   set("combat_exp", 50);
  
   set("attitude", "aggressive");
   setup();
   carry_object(__DIR__"obj/armor")->wear();
  
}

int set_status(object ob)
{
    set("combat_exp",ob->query("combat_exp")/3);   
	set_this_skills("high");
    set_all_skill(this_object(),ob->query("max_pot")/3);   
	copy_hp_item(ob,this_object(),"gin",2);
	copy_hp_item(ob,this_object(),"kee",2);
	copy_hp_item(ob,this_object(),"sen",2);
    set("max_force",ob->query("max_force")/2);
    set("force",ob->query("max_force")/2);
    set_temp("apply/armor",10+random(5));

	
}

