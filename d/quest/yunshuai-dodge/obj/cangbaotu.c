

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY"�ر�ͼ"NOR, ({ "cangbao tu","tu" }) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("give_lianrou",1);
     set("material", "paper");
     set("long", "����һ�Ųر�ͼ�����滭�ĺ��������ݵĹ㳡��\n");
     
   }
   setup();
}
