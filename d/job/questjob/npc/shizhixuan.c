
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("ʯ֮��",({ "shi zhixuan","shi"}) );
        set("gender", "����" );
        set("age", 46);
   set("long", "���ǻ����ɵ������ˡ�\n");
   set("combat_exp",6000000);
   set("str", 28);
   set_skill("unarmed",350);
   set_skill("cuff",350);
   set_skill("finger",350);
   set_skill("dodge",350);
   set_skill("parry",350);
   set_skill("force",350);
   set_skill("strike",350);
   set_skill("sword",350);
   set_skill("busi-yin",350);
   set_skill("blade",350);
   set_skill("literate",350);
   set_skill("tianyi-xuangong",350);
   set_skill("huanmo-shenfa",350);
   set_skill("zhehua-baishi",350);
   // set_skill("sanhua-zhi",350);
   set_skill("baihua-zhang",350);

   set("max_gin",6000);
   set("max_sen",6000);
   set("max_kee",6000);
   set("max_force",6000);
   set("force",6000);
   set("jiali",100);
   create_family("������",5,"����");

    setup();
   carry_object(__DIR__"obj/blade")->wield();
}


#include "job_npc.c"
