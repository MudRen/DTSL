
inherit NPC;
#include <ansi.h>
void create()
{
   set_name(HIR"������Ů"NOR,({ "girl" }) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "��������е�һ����Ů��\n");
       
   set("combat_exp",100);
   set("str",10);
   set("per",23);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/red_cloth")->wear();
  
}

