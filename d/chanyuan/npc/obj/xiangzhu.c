
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY"����"NOR, ({"xiang zhu","zhu"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "�����������������\n");
     set("unit", "Щ");
     set("jinxiang_goods",1);
     set("nogive_player",1);
   }

   
}

