#include <ansi.h>
inherit ITEM;


void create()
{
   set_name(HIW"�ٷ�"NOR, ({"jia fa","fa"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ���ٷ���\n");
     set("unit", "��");
     set("value", 400000);
     
   }

}

