
inherit NPC;

#include <job_money.h>

void create()
{
     set_name("����",({ "sha yu","sha","yu","shark"}) );
     set("race", "Ұ��" );
     set("long", "����һֻ���͵����㡣\n");
     set("verbs",({"bite"}));
     set("limbs",({"ͷ","β��","����"}));
     set("attitude","aggressive");
     setup();

}

void set_status(object ob)
{
  set("target_id",ob->query("id"));
  set("combat_exp",ob->query("combat_exp"));
  copy_hp_item(ob,this_object(),"kee");
}
  