//Edit By Subzero
inherit NPC;

void create()
{
   set_name("����",({ "yan li","yan","li" }) );
   set("gender", "����" );
   set("age", 30);
   set("long", "һ����������׳����ͦ����״ֺ��󺺣������ǵ��ꡰì������ƽ��
֮�ӵ������������˵á��ó�ʹ��һ֧����ì������丸�洫������
������ƻʵ���Ԩ������񣬹˳�������һֱ������Ԩ���ҡ�\n");
   set("shili","li");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 18);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set_skill("spear",150);
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
   carry_object(__DIR__"obj/potianmao")->wield();
}
