
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��׿", ({ "fan zhuo","fan","zhuo"}) );
       set("gender", "����" );
	   set("title","ǹ��");
       set("age", 30);
       set("long",
               "�������Ĵ���һ���İ�����\n");
       set("combat_exp", 300000);
       set("attitude", "peaceful");
	   set("gin",500);
	   set("max_gin",500);
	   set("kee",800);
	   set("max_kee",800);
	   set("sen",800);
	   set("max_sen",800);
	   set("force",900);
	   set("max_force",900);
	   set_skill("force",120);
	   set_skill("fork",130);

       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/fork")->wield();

}










