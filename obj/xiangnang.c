// ���ҡ�

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIM "����" NOR, ({ "xiang nang", "nang","xiang" }));
       	set("long", "\n����һ�����ң�ɢ���ŵ��������������滹�о��Ƶ�ͼ����\n"+
         "���������͸�����������Ů�Ķ������\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("material", "��");
		set("armor_prop/armor", 2);
		set("male_only", 1);
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

