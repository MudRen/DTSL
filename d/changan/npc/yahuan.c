
inherit NPC;

void create()
{
   set_name("Ѿ��",({ "ya huan","ya","huan" }) );
        set("gender", "Ů��" );
        set("age", 12);
   set("long", "����һλѾ�ߡ�\n");
       
   set("combat_exp", 2000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

