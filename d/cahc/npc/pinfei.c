//Edit By Subzero
inherit NPC;

void create()
{
   set_name("���",({ "pin fei","fei" }) );
   set("gender", "Ů��" );
   set("age", 25);
   set("long", "����������ʮ���꣬һ����Թ��ɫ���ƺ���˼���ż��������ĳ���˰ɣ�\n");
   set("shili","li");
   set("combat_exp", 100000);
   set("per", 28);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
