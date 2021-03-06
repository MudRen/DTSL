
inherit NPC;

void create()
{
   set_name("刀客",({ "dao ke","ke" }) );
   set("gender", "男性" );
   set("age", 30+random(5));
   set("long", "这是一名刀客，看起来风尘仆仆。\n");
       
   set("combat_exp",500000);
   set("str", 26);
   set_skill("blade",150);
   set_skill("leveltwo-blade",150);
   set_skill("dodge",150);
   set_skill("babu-ganchan",150);
   set_skill("force",150);
   set_skill("parry",150);
   
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("max_force",2000);
   set("force",2000);
   set("chat_chance",20);
   set("chat_msg",({
     "刀客一挥刀：漫天风沙算了什么，我的勇气无人能比！\n",
     "刀客挥了挥刀，立刻豪气顿生！\n",
   }));
   
   set("inquiry",([
     "青海湖":"这里是个好地方，我在沙漠中流浪很久，才来到这里。\n",
     "沙漠":"那里太可怕了，不过我还可以再去一次！\n",
    ]));
    setup();
   carry_object(__DIR__"obj/blade")->wield();
   add_money("silver",30);
}

