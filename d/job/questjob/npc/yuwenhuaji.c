
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   object *ob;
   set_name("宇文化及",({ "yuwen huajia","yuwen"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long","他是宇文阀的高手之一，据说正在寻找长生诀\n");
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("combat_exp",600000);
   set_skill("parry",160);
   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("strike",160);
   set_skill("hanbing-zhang",160);
   set("jiali",100);
   
    setup();
   ob=children("/d/quest/csj/npc/obj/baojia");
   if(sizeof(ob)<=5)
   carry_object("/d/quest/csj/npc/obj/baojia")->wear();
  
}

#include "job_npc.c"