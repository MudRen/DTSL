
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

int do_action(string arg);

void create()
{
   set_name("匕首", ({ "bi shou","shou","dagger","sjb_mengshi_bishou" }) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("material", "iron");
     set("long", "这是一柄小匕首。\n");
     set("wield_msg", "$N抽出$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插回腰间。\n");
     set("sjb_mengshi_bishou",1);
     set("nogive_player",1);
   }
   init_dagger(15,80,80);
   setup();
}

void init()
{
   add_action("do_action","mengshi");
}

int do_action(string arg)
{
   object ob,obj;
   string name,msg;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"with %s",name)!=1)
   return notify_fail("你要用什么盟誓？(mengshi with xxx)\n");
   obj=present(name,ob);
   if(!objectp(obj))
   return notify_fail("你身上没有这个东西！\n");
   if(!obj->query("sjb_mengshi_bishou"))
   return notify_fail("这个东西不能盟誓！\n");
   if(!ob->query_temp("bai_sjb/step1"))
   return notify_fail("你现在没有盟誓的必要吧！\n");
   
   msg="\n$N高声道：誓死为宋家堡献忠！！\n\n"+
       "说罢，举起"+obj->name()+"朝自己的胳膊上扎去！\n"+
       HIR+"溅出一片鲜血！！\n\n"NOR+
       "$N微微一笑，随手扔掉了"+obj->name()+"。\n";
   message_vision(msg,ob);
   ob->set_temp("bai_sjb/step2",1);
   ob->delete_temp("bai_sjb/step1",1);
   destruct(this_object());
   return 1;
}