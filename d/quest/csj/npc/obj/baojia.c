
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "��˿����" NOR, ({ "bao jia", "jia" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rumor",1);
	        set("value", 500);
	        set("no_save",1);
	        set("no_sell",1);
                set("material", "gold");
                set("armor_prop/armor",100);
        }
        setup();
}

