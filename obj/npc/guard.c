#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({"guard"}));
        set("long", "����һ�����ڡ�\n");
        set("attitude", "peaceful");

        set("max_gin", 800);
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 500);
        set("max_force", 500);
        set("combat_exp", 500000);
        set_skill("unarmed",130);
        set_skill("parry",130);
        set_skill("dodge",130);
        set_skill("cuff",130);
       setup();
}

int kill_object(object killer,object victim)
{
  message_vision(HIR"$Nһ����Ц������һ�Σ��ټ�������\n"NOR,killer);
  destruct(killer);
  return 1;
}
