
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   
   set_name("������",({ "yuwen shi","yuwen"}) );
        set("gender", "����" );
        set("age", 38);
   set("long","�������ķ��ĵ��������");
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
   set_skill("niaozong-shu",160);
   set("jiali",100);
    setup();
   
}


#include "job_npc.c"