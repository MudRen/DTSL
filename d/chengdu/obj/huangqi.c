
inherit ITEM;

void create()
{
        set_name("����", ({ "huang qi","huang","qi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ�����Σ�������������ҩ�\n");
                set("value", 15);
				set("heal",([
					"heals":15,
					]));
                
        }

      
        setup();
}
