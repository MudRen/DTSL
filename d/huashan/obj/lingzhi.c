
inherit ITEM;

void create()
{
        set_name("��֥", ({ "ling zhi","ling","zhi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ����֥������������ҩ��\n");
                set("value", 3);
				set("wei_med",1);
				set("heal",([
					"heals":100,
					]));
                
        }

      
        setup();
}
