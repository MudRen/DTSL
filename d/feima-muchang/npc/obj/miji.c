
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"����ѧ�ķ���"NOR, ({ "wuxu xinfa","book","xinfa"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ������ѧ�ķ������������ϳ˵��书�ķ���\n");
     set("unit", "��");
     set("value", 10000000000);
     set("skill", ([
     "name":      "wuxue-xinfa",    
     "exp_required":   500000, 
                         
     "sen_cost":     90,   
     "difficulty":   30, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
