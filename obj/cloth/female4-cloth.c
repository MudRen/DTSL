// female4-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"鹅黄夹袄"NOR, ({ "yellow ao", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件女孩喜欢的鹅黄夹袄。\n");
                set("material", "cloth");
                set("value", 0);
                set("armor_prop/armor", 3);
		set("female_only", 1);
              set("no_give", "随身的东西不能给人。\n");

        }
        setup();
}

