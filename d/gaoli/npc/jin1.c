
inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
        set_name("������", ({"jin suanpan", "jin"}));
        set("title", "�����ƹ�");
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
		set_skill("wuxing-quan",130);
        set("hand",({"wuxing-quan"}));
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        //carry_object("/d/gali/obj/pao")->wear();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
        add_action("do_value","value");
}

void die()
{
  object *inv;int i;
  inv=all_inventory(this_object());
  if(sizeof(inv)==0)
  return ::die();
  for(i=0;i<sizeof(inv);i++)
   destruct(inv[i]);
   return ::die();
}