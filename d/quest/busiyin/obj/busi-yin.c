
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIB"����ӡ"NOR, ({ "busi yin","book" }));
   set_weight(300);
   set("unit", "��");
   set("long","���������ؼ�������ӡ��.\n");
   set("no_sell",1);
   set("no_drop",1);
   set("no_give",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "busi-yin",    
     "exp_required":300000, 
                         
     "sen_cost":100,   
     "difficulty":50, 
     "max_skill":500,          
   ]) );
}
int is_get_of(object pal,object ob)
{
 if(!pal->query("dtsl_quest_bsy_ok"))
 return notify_fail("�㲻�������Ǳ��飡\n");
 return 1;
}
