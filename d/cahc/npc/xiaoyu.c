//Edit By Subzero
inherit NPC;

void create()
{
   set_name("���r",({ "xiao yu","xiao","yu" }) );
   set("gender", "����" );
   set("age", 40);
   set("long", "����òƽƽ�������ģ�ƫ�����Ʊ��ˣ�һ��ٷ�����ŭ��
�������˲���ֱ�ӡ����������Ƕ賩�۵��޾ˣ�������Ԩ��
�������ڴ��е¸����أ���λ���⡣\n");
   set("shili","li");
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 16);
   set("int", 27);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
