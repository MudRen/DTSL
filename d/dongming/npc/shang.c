
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "����һ���Ĵ��ߵ������ˡ�\n");
       
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("eff_kee",800);
   set("sen",500);
   set("eff_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   add_money("gold",1);
}

