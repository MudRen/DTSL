#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIY"�ƽ�Կ��"NOR, ({ "key"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "�ƽ�");
     set("long","����һ���ƽ�����Կ�ף����ӿ���������֡�\n");
     set("unit", "ö");
     set("no_drop",1);
     set("no_sell",1);
     set("unique",1);
   }
   setup();
}
