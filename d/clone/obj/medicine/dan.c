
inherit COMBINED_ITEM;

#define HEAL 100
#define HEAL_TYPE "��Ѫ"
#define LONG_MSG "����һ��������ʿ�ر��Ĳ�Ѫ��������Է�(fuyong)���������Լ������ˡ�\n"
#define VALUE 1500

void create()
{
	set_name("��Ѫ��", ({"buxue dan", "buxue", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
                           
                set("value", VALUE);
                set("base_unit", "ö");
                set("base_weight", 100);
 		set("long", LONG_MSG);
		set("base_value", VALUE);
		set("heal_up",([
					HEAL_TYPE:HEAL,
					]));
	}
	set_amount(1);
}
