
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(WHT"��ħն"NOR, ({ "tianmo zhan","zhan","dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_save",1);
		set("long", "����һ����ħն��ר���ڼ�������\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("no_sell",1);
		set("material", "steel");
	}
	init_dagger(120,180,180);


	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");


	setup();
}

void hit_ob(object me,object victim)
{
  if(random(5)>3&&victim->query("force")>0){
    victim->add("force",-me->query("apply_points"));
    if(victim->query("force")<0)
    victim->set("force",0);
    message_vision("\n$N��"+query("name")+"����$n��$n���������ɵÿ�к������\n",
      me,victim);
  }
 return;
}