
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name("��", ({ "fish"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     
     set("unit", "��");
     set("value",100);
     set("long","����һ���㡣\n");
    
   }
   setup();
}
