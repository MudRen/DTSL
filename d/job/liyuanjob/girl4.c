
inherit NPC;
#include <ansi.h>
void create()
{
   set_name(HIY"������Ů"NOR,({ "girl" }) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "��������е�һ����Ů��\n");
       
   set("combat_exp",100);
   set("str",10);
   set("per",23);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/yel_cloth")->wear();
  
}

