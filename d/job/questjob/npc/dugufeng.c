
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("���·�",({ "dugu feng","dugu","feng" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ƕ��·��ķ������·壬���������ĸ���֮һ��\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("cuff",180);
   set_skill("dugu-jianfa",180);
   set_skill("youming-zhang",180);
   set_skill("niaozong-shu",180);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
  
}


#include "job_npc.c"