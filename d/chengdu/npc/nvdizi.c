
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����", ({ "dizi","di","zi"}) );
       set("gender", "Ů��" );
	   set("title","���𱤵���");
       set("age", 18);
       set("long",
               "���Ƕ��𱤵ĵ��ӡ�\n");
       set("combat_exp",40000);
       set("attitude", "peaceful");
	   
	   set("force",300);
	   set("max_force",300);
	   set_skill("unarmed",40);
	   set_skill("dodge",40);
	   set_skill("parry",40);
	   setup();
 carry_object(__DIR__"obj/cloth")->wear();
 
}










