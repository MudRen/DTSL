
#include <ansi.h>
#include <job_money.h>
inherit NPC;
void create()
{
   set_name("�Ϲ���",({ "shangguan long","shangguan","long" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "����������Ժ�������Ϲ���,������Ҳ�Ƿǳ������������\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",150);
   set_skill("sword",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jianfa",130);
   set_skill("tianmo-huanzong",130);
   set_skill("tianmo-dai",120);
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"tianmo-dafa"}));
   set("sword",({"tianmo-jianfa"}));
   set("hand",({"tianmo-dai"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
//   create_family("������",5,"����");
   set("s_flag",1);
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
