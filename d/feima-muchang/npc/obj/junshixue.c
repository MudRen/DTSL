
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"������ѧ��"NOR, ({ "junshi xue","book" }) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ��������ѧ�������潲���˸��ֱ�����\n");
     set("unit", "��");
     set("value", 10000000000);
     set("skill", ([
     "name":      "junshixue",    
     "exp_required":   300000, 
                         
     "sen_cost":     50,   
     "difficulty":   30, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
