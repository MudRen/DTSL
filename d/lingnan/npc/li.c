
inherit NPC;

#include <ansi.h>
void create()
{
   set_name("���ܹ�",({ "li"}) );
        set("gender", "����" );
		set("title","�����ܹ�");
       set("age", 42);
   set("long", "�������μұ��Ļ����ܹܣ��ܹ��μұ��Ļ��\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",1000);
   set("eff_gin",1000);
   set("kee",1000);
   set("eff_kee",1000);
   set("sen",1000);
   set("eff_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
 
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
 
}

