
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("������", ({ "xie wenlong","xie"}) );
       set("gender", "����" );
       set("age", 40);
        set("long",
               "�����Ƕ��𱤵��ٱ�����\n");
       set("combat_exp", 300500);
       set("attitude", "peaceful");
	   set("gin",800);
	   set("max_gin",800);
	   set("kee",800);
	   set("max_kee",800);
	   set("sen",800);
	   set("max_sen",800);
	   set("max_force",800);
	   set("force",800);
	   set_skill("unarmed",100);
	   set_skill("dodge",100);
	   set_skill("parry",100);
       set_skill("force",100);
       set("shili",([
         "name":"duzun_b",
         ]));
       setup();
 carry_object(__DIR__"obj/cloth")->wear();


}
