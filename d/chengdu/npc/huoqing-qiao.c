
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("������", ({ "huo qingqiao","huo","qingqiao"}) );
       set("gender", "����" );
	   set("title",HIY"������"NOR);
       set("age", 42);
       set("long",
               "����[���϶ķ�]���ƹ�����š�\n");
       set("combat_exp", 300000);
       set("attitude", "peaceful");
	   set("str",27);
	   set("per",21);
	   set("max_gin",500);
	   set("max_kee",500);
	   set("max_sen",800);
	   set("max_force",800);
	   set("force",800);
	   set_skill("force",100);
	   set_skill("unarmed",100);
	   set_skill("parry",100);
	   set_skill("dodge",100);
       set_skill("staff",100);
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/suanpan")->wield();


}
