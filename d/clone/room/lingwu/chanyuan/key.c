#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIY"黄金钥匙"NOR, ({ "key"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "黄金");
     set("long","这是一个黄金打造的钥匙，样子看起来很奇怪。\n");
     set("unit", "枚");
     set("no_drop",1);
     set("no_sell",1);
     set("unique",1);
   }
   setup();
}
