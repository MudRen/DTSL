
inherit NPC;
void create()
{
   set_name("房玄龄",({ "fang xuanling","fang","xuanling" }) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "这就是李世民得力的手下房玄龄，他为李世民招募人才。\n");
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set_skill("literate",100);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

