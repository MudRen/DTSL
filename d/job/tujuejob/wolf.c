
inherit NPC;

#include <ansi.h>

string *name=({
WHT"������"NOR,YEL"����"NOR,
WHT"�����"NOR,YEL"����"NOR,
});

void create()
{
   set_name(name[random(sizeof(name))],({ "lang","wolf"}) );
        set("race", "Ұ��" );
        set("combat_exp",200000);
     set("long", "����һֻ���͵��ǣ��������ܼ�����\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}
