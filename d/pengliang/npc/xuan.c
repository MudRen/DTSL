
inherit NPC;

void create()
{
   set_name("����",({ "xuan yong" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "��������˧�����������ܹܡ�\n");
       
   set("combat_exp",600000);
   set("str", 46);
   set("per", 42);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

