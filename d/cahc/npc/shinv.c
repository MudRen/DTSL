//Edit By Subzero
inherit NPC;

void create()
{
   set_name("侍女",({ "shi nv","nv" }) );
   set("gender", "女性" );
   set("age", 19);
   set("long", "她看起来十多岁，脸上带着幼稚的微笑。\n");
   set("shili","li");
   set("per", 20);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
