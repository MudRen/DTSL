
inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("卜天志",({ "bu tianzhi","bu"}) );
        set("gender", "男性" );
        set("age",25);

   set("long", "他模样丑陋左颊还有一道长约两寸的刀疤，\n"+
               "予人狰狞的感觉。\n");

   set("combat_exp", 30000);
   set("str", 20);
   set("per", 10);

   set_skill("strike",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("cuff",100);

   set_skill("jiutian-huanzhang",100);
   set_skill("linglong-yuquan",100);
   set_skill("tianmo-huanzong",100);
   // set_skill("pojun-quan",100);

   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   setup();

}



#include "job_npc.c"
