// zhang tianen
#include <ansi.h>;
inherit NPC;
inherit JOB;
mapping *quest = ({
                   ([      "quest"      :    "����",
                           "quest_type" :    "ɱ",
                           "msg"        :    "�����������\n",
                           "exp_bonus"  :    100,
                   ]),
                   ([      "quest"      :    "����",
                           "quest_type" :    "ɱ",
                           "msg"        :    "������˲���\n",
                           "exp_bonus"  :    50,
                    ]),
                   ([      "quest"      :    "ǿ��",
                           "quest_type" :    "ɱ",
                           "msg"        :    "���ǿ������\n",
                           "exp_bonus"  :    50,
                    ]),

                });
void create()
{
        set_name(HIR"�����"NOR, ({ "zhang tianen", "tianen", "zhang" }) );
        set("gender", "����" );
        set("title", HIY"��ͤ���ؽ�"NOR);
        set("age", 42);
        set("long",
            "���ǳ�͢�������ؽ�������ά���ΰ���Χ�˺�����\n");
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("attitude", "friendly");

        setup();
        set("chat_chance", 5);

        carry_object("/u/smokes/junying/obj/tiejia")->wear();
        carry_object("/u/smokes/junying/obj/gangjian")->wield();
}
void init()
{

        add_action("give_job","askjob");        
}


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

