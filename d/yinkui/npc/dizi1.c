
inherit NPC;

void create()
{
   set_name("����",({ "di zi","di","zi" }) );
        set("gender", "����" );
		
        set("age", 22);
   set("long", "���������ɵĵ��ӡ�\n");
       
   set("combat_exp",50000);
   set_skill("unarmed",60);
   set_skill("dodge",60);
   set_skill("parry",60);
   set_skill("force",60);
   set_skill("sword",60);
   set_skill("tianmo-dafa",60);
   set_skill("tianmo-jianfa",60);
   set_skill("tianmo-huanzong",60);
   set("gin",300);
   set("max_gin",300);
   set("kee",300);
   set("max_kee",300);
   set("sen",300);
   set("max_sen",300);
   set("force",300);
   set("max_force",300);
   create_family("������",7,"����");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
