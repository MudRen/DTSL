
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("方益民", ({ "fang yimin","fang"}) );
       set("gender", "男性" );
       set("age", 30);
       set("long",
               "这是独尊堡的大管家。\n");
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
