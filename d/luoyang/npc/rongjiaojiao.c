
#include <ansi.h>
#include <job_money.h>
inherit NPC;
void create()
{
   set_name("����",({ "rong jiaojiao","rong","jiao"}) );
        set("gender", "Ů��" );
	  set("age", 22);
   set("long", "�������ٷ����Ů����\n");
       
   set("combat_exp",600000);
   set("str", 25);
   set("per", 27);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("sword",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-huanzong",130);
   set_skill("jiutian-huanzhang",130);
   set("hand",({"jiutian-huanzhang"}));
   set("dodge",({"tianmo-huanzong"}));
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   set("chat_chance",70);
   set("chat_msg",({
	   (:random_move:),
   }));
   set("s_flag",4);
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
 
}

