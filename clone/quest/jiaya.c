#include <ansi.h>
inherit ITEM;


void create()
{
   set_name(HIY"����"NOR, ({"jia ya","ya"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "��������Դ�ʦ�ļ�����������.... ....�ö��ġ�\n");
     set("unit", "��");
     set("value", 400000);
     
   }

}

