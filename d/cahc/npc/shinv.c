//Edit By Subzero
inherit NPC;

void create()
{
   set_name("��Ů",({ "shi nv","nv" }) );
   set("gender", "Ů��" );
   set("age", 19);
   set("long", "��������ʮ���꣬���ϴ������ɵ�΢Ц��\n");
   set("shili","li");
   set("per", 20);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
