//Edit By Subzero
inherit NPC;

void create()
{
   set_name("韦公公",({ "wei gonggong","wei","gonggong" }) );
   set("gender", "男性" );
   set("age", 54);
   set("long", "这太监中等身材，年纪在五十许间，容貌并不出众，但衣着极为讲究，予人整
齐洁净的感觉，浑身似不着一尘。此人在旧隋时曾侍候杨坚，后则追随杨广，
是隋宫内武功最高强的太监头子。炀帝被杀时他正在江都，凭武功突围逃走，
自此投靠李渊，并得李渊起用为内宫监，宫内所有大小太监均归他管辖。
\n");
   set("shili","li");
   set("combat_exp", 1000000);
   set("str", 30);
   set("per", 18);
   set("dex", 30);
   set("int", 30);
   set("attitude", "peaceful");
   set_skill("unarmed",200);
   set_skill("parry",200);
   set_skill("dodge",200);
   set_skill("force",200);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2500);
   set("max_force",2500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
