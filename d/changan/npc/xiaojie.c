
inherit NPC;

void create()
{
   set_name("С��",({ "xiao jie","xiao","jie" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "����һλ�ڳ������й��С�㡣\n");
       
   set("combat_exp", 2000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

