//Edit By Subzero
inherit NPC;

void create()
{
   set_name("�Ž��",({ "zhang jieyu","zhang","jieyu" }) );
   set("gender", "Ů��" );
   set("age", 22);
   set("long", "��һ������Ӻ�ݸ��ŵ��о���̬��������վ������·�һ
����Ůͼ���ֺ��ƴ��������������һ�㣬�������˲�����
�����Ĵ��ڡ�\n");
   set("shili","li");
   set("combat_exp", 300);
   set("str", 20);
   set("per", 20);
   set("int", 20);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
