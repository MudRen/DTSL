
#include <weapon.h>

inherit WHIP;

void create()
{
   set_name("皮鞭", ({ "whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "条");
     set("material", "iron");
     set("long", "这是一条皮鞭。\n");
     set("wield_msg", "$N抽出一把$n啪地抖了一声。\n");
     set("unequip_msg", "$N将手中的$n盘在腰间。\n");
   }
   init_whip(35,120,120);
   setup();
}
