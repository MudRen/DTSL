
inherit COMBINED_ITEM;


#define HEAL 200
#define HEAL_TYPE "kee"
#define LONG_MSG "����һ��������ʿ�ر��Ľ�ҩ������Է�(fuyong)���������Լ������ˡ�\n"
#define VALUE 2000


void create()
{
	set_name("��ҩ", ({"jinchuang yao", "jinchuang", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Щ");
                           
                set("value", VALUE);
                set("base_unit", "��");
                set("base_weight", 100);
 		set("long", LONG_MSG);
		set("base_value", VALUE);
		set("heal_up",([
					HEAL_TYPE:HEAL,
					]));
	}
	set_amount(1);
}
