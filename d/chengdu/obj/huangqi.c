
inherit ITEM;

void create()
{
        set_name("黄芪", ({ "huang qi","huang","qi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
				set("long","这是一个黄芪，它能用来炼制药物。\n");
                set("value", 15);
				set("heal",([
					"heals":15,
					]));
                
        }

      
        setup();
}
