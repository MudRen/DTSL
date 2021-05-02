
inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("��˪",({ "qin shuang","qin" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "���ǴȺ���ի����˪��\n");

   set("combat_exp",300000);
   set("str", 25);
   set("per", 26);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("max_force",3000);
   set("force",3000);
   set_skill("sword",120);
   set_skill("cuff",120);
   set_skill("strike",120);
   set_skill("dodge",120);
   set_skill("finger",120);
   set_skill("literate",120);
   set_skill("force",120);
   set_skill("sekong-jianfa",120);
   // set_skill("piaokong-zhang",120);
   // set_skill("jingxin-quan",120);
   set_skill("xiuluo-zhi",120);
   set_skill("wuwang-jing",120);
   set_skill("qingxin-force",120);
   set_skill("lingyun-shenfa",120);

   create_family("�Ⱥ���ի",8,"����");
   setup();
   carry_object(__DIR__"obj/changjian")->wield();

}

void die()
{
   object ob;
   int exp,pot,silver;

   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   if(ob->query("id")!=query("target_id"))
   return ::die();

   exp=R_JOB+40+random(50);
   pot=ob->query("max_pot")/3;
   silver=ob->query("max_pot");

   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",silver);
   add_shili(ob,exp/10,silver/10);
   tell_object(ob,"������ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                  "                    "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�"+
                  MONEY_D->money_str(silver)+"��\n");
   return ::die();
}

// #include "job_npc.c"
