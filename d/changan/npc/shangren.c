
inherit NPC;

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ�ڳ����������������\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

