
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��ʿ",({ "guard" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ��Ч���������ʿ��\n");

   set("combat_exp", 200000);
   set("str", 28);
   set_skill("finger",70);
   set_skill("strike",70);
   set_skill("cuff",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set_skill("tiangang-sanjue",70);
   set_skill("bencao-shuli",70);
   set_skill("huanmo-shenfa",70);
   set_skill("dujie-zhi",70);
   // set_skill("sanhua-zhi",70);
   set_skill("xiuluo-zhi",70);
   // set_skill("pojun-quan",70);
   set_skill("linglong-yuquan",70);
   // set_skill("xukong-zhang",70);
   set("max_force",200);
   set("force",200);
   set("chat_chance_combat",70);
   set("chat_msg_combat",({
    (:apply_action,"dujie-zhi",3,8:),
    (:apply_action,"sanhua-zhi",3,8:),
    (:apply_action,"xiuluo-zhi",3,8:),
    (:apply_action,"pojun-quan",3,8:),
    (:apply_action,"linglong-yuquan",3,8:),
    (:apply_action,"xukong-zhang",3,8:),
    }));
   setup();

}

void init()
{
   if(!query("last_time"))
    set("last_time",time());

}

int clean_up()
{
  if(time()-query("last_time")<300)
   return 0;
  return 1;
}
