
inherit ITEM;

void create()
{
        set_name("��ҩ", ({ "dan yao","yao" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long","����һ�òݡ�\n");               
        }

        setup();
}
