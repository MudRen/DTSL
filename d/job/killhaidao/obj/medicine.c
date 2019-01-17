
inherit ITEM;

void create()
{
        set_name("µ§“©", ({ "dan yao","yao" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ø√");
		set("long","’‚ «“ªø√≤›°£\n");               
        }

        setup();
}
