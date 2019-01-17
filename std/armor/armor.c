// armor.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if(!query("rumor")&&!query("set_weight") )
	set_weight(query("armor_prop/armor")*50);
	
	if( clonep(this_object()) ) return;
	set("armor_type", TYPE_ARMOR);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
	
}
