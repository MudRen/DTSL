
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("�Ϸ溮",({ "ba fenghan","ba","fenghan"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������ͻ�ʵ���ʿ�Ϸ溮��Ҳ�ǵ����������ս���ˡ�\n");
       
   set("combat_exp",1200000);
   set("per", 24);
   set("cor",30);
   set("str",30);
   set("jiali",200);
   set_temp("apply/armor",50);
   set_temp("apply/dodge",50);
   set_temp("apply/damage",50);
   set("attitude", "peaceful");
   set_skill("blade",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("bafeng-jian",200);
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   
   setup();
  
   carry_object(__DIR__"obj/changjian")->wield();
  
}


   
#include "job_npc.c"