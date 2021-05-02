
inherit NPC;
#include <ansi.h>
#include <job_money.h>
int do_ok(string arg);
void create()
{
        set_name("�ٲ�", ({"guan chai", "guan","chai"}));
        set("title", "�ξֹٲ�");
        set("gender", "����");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500);
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
		set_skill("cuff",120);
		set_skill("force",120);
		set_skill("wuxing-quan",130);
        set("hand",({"wuxing-quan"}));
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        set("yunyan",5);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	add_action("do_ok","task");
}

#include "/d/job/yunyanjob/job.c"
