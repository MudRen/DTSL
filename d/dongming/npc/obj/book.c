
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name("������������", ({ "book" }));
   set_weight(300);
   set("unit", "��");
   set("long","���Ƕ����ɵ������书ָ����������������\n");
   set("no_sell",1);
   set("no_drop",1);
   set("no_give",1);
   set("no_get",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "hammer",    
     "exp_required":1, 
                         
     "sen_cost":40,   
 "difficulty":10,
     "max_skill":200,          
   ]) );
}

