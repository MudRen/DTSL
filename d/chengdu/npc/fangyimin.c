
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("������", ({ "fang yimin","fang"}) );
       set("gender", "����" );
       set("age", 30);
       set("long",
               "���Ƕ��𱤵Ĵ�ܼҡ�\n");
       set("combat_exp", 100500);
       set("attitude", "peaceful");
	   set("force",200);
	   set_skill("unarmed",80);
	   set_skill("dodge",80);
	   set_skill("parry",80);
       set_skill("force",80);
       set("shili",([
         "name":"duzun_b",
         ]));
       setup();
 carry_object(__DIR__"obj/cloth")->wear();


}
