
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke" }) );
        set("gender", "����" );
           set("long", "����һ����ͨ���ο͡�\n");
          set("combat_exp", 5000);
   set("str", 10);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

