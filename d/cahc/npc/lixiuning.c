//Edit By Subzero
inherit NPC;

void create()
{
   set_name("������",({ "li xiuning","li","xiuning" }) );
   set("gender", "Ů��" );
   set("age", 20);
   set("long", "��һ������Ӻ�ݸ��ŵ��о���̬��������վ������·�һ
����Ůͼ���ֺ��ƴ��������������һ�㣬�������˲�����
�����Ĵ��ڡ�\n");
   set("shili","li");
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 30);
   set("int", 30);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
