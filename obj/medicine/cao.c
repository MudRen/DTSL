
inherit ITEM;

void create()
{
        set_name("��", ({ "cao" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ�òݡ�\n");
                set("value", 3);
				set("heal",([
					"heals":20,
					]));
                
        }

      
        setup();
}
