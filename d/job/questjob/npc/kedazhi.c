

inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("�ɴ�־",({ "ke dazhi","ke" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("combat_exp",1000000);
   set("str", 25);
   set("per", 22);
   set_skill("unarmed",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("blade",200);
   set_skill("literate",200);
   set_skill("cuff",200);
   set_skill("yanyang-dafa",200);
      set_skill("youlong-shenfa",250);
   set_skill("tianlang-dao",250);
   set_skill("pojun-quan",200);
   set("gin",4000);
   set("max_gin",4000);
   set("kee",4000);
   set("max_kee",4000);
   set("sen",4000);
   set("max_sen",4000);
   set("force",4000);
   set("max_force",4000);
   create_family("ͻ��",2,"��ʿ");
   setup();
   carry_object(__DIR__"obj/blade")->wield();  
}


#include "job_npc.c"