
inherit NPC;

void create()
{
   set_name("һȺ�ٱ�",({ "fighter" }) );
      //  set("gender", "����" );
       // set("age", 32);
   set("long", "����һȺ��������ս��ʿ������������һ��������\n");
       
   set("combat_exp",200);
   set("str", 20);
   set("per", 20);
   set("kee",800);
   set("max_kee",800);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

