
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("���°�",({ "dugu ba","dugu","ba" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ƕ��·��ĸ��ֶ��°ԣ�������Ҳ�Ǻ���һ����\n");
   set("combat_exp",600000);
   set("str", 28);
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("strike",180);
   set_skill("dugu-jianfa",180);
   set_skill("youming-zhang",180);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}


#include "job_npc.c"