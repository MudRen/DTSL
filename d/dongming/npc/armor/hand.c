
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(YEL"��Ƥ����"NOR, ({ "shou tao","tao"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("no_give",1);
     set("no_get",1);
     set("no_sell",1);
     set("armor_prop/armor",5);
   }
   setup();
}
