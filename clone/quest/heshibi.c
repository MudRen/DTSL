#include <ansi.h>
inherit ITEM;


void create()
{
   set_name(HIW"�����"NOR, ({"heshi bi","bi"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "���������������õ��ĺ���赡�\n");
     set("unit", "��");
     set("value", 400000);
     
   }

}

