
inherit NPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("��¡",({ "an long","an","long"}) );
        set("gender", "����" );
        set("age", 52);
        set("str",30);
        set("title",HIY"��������"NOR);
        set("long","����а�̵�һ����֡�\n");
        set("combat_exp",600000);
        
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_gin",3000);
        set("max_force",3000);
        set("force",3000);
        set_skill("parry",170);
        set_skill("dodge",170);
        set_skill("force",170);
        
        set_skill("strike",170);
        set_skill("tianxin-lianhuan",170);
        set_skill("babu-ganchan",170);
    setup();
   carry_object(__DIR__"obj/tiewan")->wear();
  
}
   
#include "job_npc.c"