// yupei.c ����

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIC "����" NOR, ({ "yu pei", "yu" }));
       	set("long", "\n����һ�鵭��ɫ�ı���Ө�����󣬹����覣�����ϡ�����С�\n"+
         "���������͸�����������Ů�Ķ������\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("value", 50000);
		set("material", "��");
		set("armor_prop/armor", 2);
		set("female_only", 1);
		set("no_get",1);
	}
	setup();
}	
int query_autoload()
{
	return 1;
}

int unequip()
{
	object ob = environment();

	if (userp(ob) && ob->query("couple/couple_id") && ob->query("couple/couple_name"))
		return notify_fail("�㲻��ж����Ķ������\n");

	return ::unequip();
}
