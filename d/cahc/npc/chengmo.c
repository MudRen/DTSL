//Edit By Subzero
inherit NPC;

void create()
{
   set_name("��Ī",({ "cheng mo","cheng","mo" }) );
   set("gender", "����" );
   set("age", 40);
   set("long", "������Ϊ�ʹ��������ﳤ��ר������ϲ���
����ӵĿ�����ʮ���꣬һ����ɫ���ȵ����ӡ�\n");
   set("shili","li");
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 18);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
