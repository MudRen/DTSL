
inherit NPC;

#include <job_money.h>

void create()
{
     set_name("öèÓã",({ "sha yu","sha","yu","shark"}) );
     set("race", "Ò°ÊÞ" );
     set("long", "ÕâÊÇÒ»Ö»Ð×ÃÍµÄöèÓã¡£\n");
     set("verbs",({"bite"}));
     set("limbs",({"Í·","Î²°Í","¸¹²¿"}));
     set("attitude","aggressive");
     setup();

}

void set_status(object ob)
{
  set("target_id",ob->query("id"));
  set("combat_exp",ob->query("combat_exp"));
  copy_hp_item(ob,this_object(),"kee");
}
  