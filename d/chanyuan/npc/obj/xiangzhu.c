
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY"香烛"NOR, ({"xiang zhu","zhu"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是用来进香的香烛。\n");
     set("unit", "些");
     set("jinxiang_goods",1);
     set("nogive_player",1);
   }

   
}

