
inherit ITEM;

void create()
{
        set_name("�޻���", ({ "wuhua guo","guo" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ���޻�����������������ҩ�\n");
                set("value", 200);
				set("heal",([
					"heals":20,
					]));
                
        }

      
        setup();
}
