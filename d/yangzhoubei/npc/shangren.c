
inherit NPC;

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����һ�����ϴ��������ˡ�\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

