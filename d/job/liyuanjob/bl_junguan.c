
inherit NPC;
#include <ansi.h>

int do_task(string arg);

void create()
{
   set_name("����",({ "jun guan","jun","guan" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�����ܹ����˵ľ��١�\n");

   set("combat_exp", 200000);
   set("str", 28);
   set_skill("finger",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set_skill("tiangang-sanjue",150);
   set_skill("bencao-shuli",150);

   set_skill("dujie-zhi",150);
   // set_skill("sanhua-zhi",150);
   set_skill("xiuluo-zhi",150);
   // set_skill("pojun-quan",150);
   set_skill("linglong-yuquan",150);
   // set_skill("xukong-zhang",150);
   set("max_force",2000);
   set("force",2000);
   set("chat_chance_combat",70);
   set("chat_msg_combat",({
    (:apply_action,"dujie-zhi",3,8:),
    (:apply_action,"sanhua-zhi",3,8:),
    (:apply_action,"xiuluo-zhi",3,8:),
    (:apply_action,"pojun-quan",3,8:),
    (:apply_action,"linglong-yuquan",3,8:),
    (:apply_action,"xukong-zhang",3,8:),
   }));
   set("task_ok",3);
   setup();

}

#include "taskok.c"
