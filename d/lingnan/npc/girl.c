
inherit NPC;

void create()
{
   set_name("Ů����",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 20);
   set("long", "�����μұ��ĵ��ӣ��书Ҳ�ǲ��ס�\n");
       
   set("combat_exp", 50000);
   set_skill("blade",30);
   set_skill("tiandao-bajue",30);
   set_skill("dodge",30);
   set_skill("force",30);
   set("force",200);
   create_family("�μұ�",7,"����");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

