
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("伏骞",({ "fu jian","fu"}) );
        set("gender", "男性" );
        set("age",35);

   set("long", "这是吐谷浑的伏骞，枪法很是不俗。\n");

   set("combat_exp", 800000);
   set("str", 30);
   set("per", 24);

   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("spear",200);

//    set_skill("level3-qiang",200);
   set_skill("niaozong-shu",200);

   set("max_kee",2500);
   set("max_gin",2500);
   set("max_sen",2500);
   set("force",2500);
   set("max_force",2500);

   set("inquiry",([
        "曲傲":"他可是我的仇敌，有机会一定杀了他！\n",
        "寇仲":"我很久没看到他了，你有他的消息吗？\n",
        "徐子陵":"这个人不同凡响，可惜很久没有他的消息了。\n",
        ]));

   setup();
   carry_object(__DIR__"obj/spear")->wield();

}
