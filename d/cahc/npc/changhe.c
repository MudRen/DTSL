//Edit By Subzero
inherit NPC;

void create()
{
   set_name("常何",({ "chang he","chang","he" }) );
   set("gender", "男性" );
   set("age", 30);
   set("long", "年纪在三十多岁，国字脸，表情严肃，身形威猛高大，
为京城守备四大将领之一，镇守皇城要地玄武门。\n");
   set("shili","li");
   set("combat_exp", 400000);
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
