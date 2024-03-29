// zhang tianen
#include <ansi.h>;
inherit NPC;
inherit JOB;
mapping *quest = ({
                   ([      "quest"      :    "海盗",
                           "quest_type" :    "杀",
                           "msg"        :    "最近海盗猖狂。\n",
                           "exp_bonus"  :    100,
                   ]),
                   ([      "quest"      :    "土匪",
                           "quest_type" :    "杀",
                           "msg"        :    "最近土匪猖狂。\n",
                           "exp_bonus"  :    50,
                    ]),
                   ([      "quest"      :    "强盗",
                           "quest_type" :    "杀",
                           "msg"        :    "最近强盗猖狂。\n",
                           "exp_bonus"  :    50,
                    ]),

                });
void create()
{
        set_name(HIR"张天恩"NOR, ({ "zhang tianen", "tianen", "zhang" }) );
        set("gender", "男性" );
        set("title", HIY"华亭镇守将"NOR);
        set("age", 42);
        set("long",
            "他是朝廷派来的守将，负责维持治安，围剿海盗。\n");
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("attitude", "friendly");

        setup();
        set("chat_chance", 5);

        carry_object("/d/junying/obj/tiejia")->wear();
        carry_object("/d/junying/obj/gangjian")->wield();
}
void init()
{

        add_action("give_job","askjob");
}


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
