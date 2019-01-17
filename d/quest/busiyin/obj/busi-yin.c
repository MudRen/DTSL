
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIB"不死印"NOR, ({ "busi yin","book" }));
   set_weight(300);
   set("unit", "本");
   set("long","这是武林秘籍《不死印》.\n");
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
 return notify_fail("你不能拿起那本书！\n");
 return 1;
}
