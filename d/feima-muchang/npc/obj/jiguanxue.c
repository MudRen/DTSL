
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"������ѧ��"NOR, ({ "jiguan xue","book" }) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ��������ѧ��������������³���ӵ���Ѫ��\n");
     set("unit", "��");
     set("no_give",1);
     set("no_get",1);
     set("no_drop",1);
     set("no_sell",1);
     set("no_steal",1);
     set("skill", ([
     "name":      "jiguanxue",    
     "exp_required":   0, 
                         
     "sen_cost":     30,   
     "difficulty":   25, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
