
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("����",({ "hai gui","gui"}) );
   set("race", "Ұ��" );
   set("long", "����һֻ�󺣹ꡣ\n");
   set("chat_chance",30);
   set("limbs",({"ͷ","β��"}));
   set("verbs",({"bite"}));
   set("chat_msg",({
   "�󺣹��������������� .... ....\n",
   }));
       
   
   setup();
  
}

int accept_fight(object ob)
{
  return notify_fail("������æ�����˿��\n");
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  tell_object(ob,"������æ�����˿��\n");
  return;
}
