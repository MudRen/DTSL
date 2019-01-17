
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIR"鞭"HIG"炮"NOR, ({ "bian pao","bian","pao"}) );
   set_weight(150);
   
     set("material", "纸");
     set("unit", "挂");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"你好！祝您"HIY"春节"NOR"快乐！\n"+
          "感谢你对"HIC"大唐双龙"NOR"的支持！\n"+
          "祝您在新的一年里工作顺利，学习进步，永远快乐！\n"+
          "这是一挂鞭炮，如果你点着它，就会得到春节的礼物。\n"+
          HIG"（dian bian pao）\n"NOR;
       
}

void init()
{
  add_action("do_action","dian");
}

int do_action(string arg)
{
   object ob;
   ob=this_player();
   
   if(!arg)
   return 0;
   if(!present(arg,ob))
   return 0;
   if(!id(arg))
   return 0;
   
   if(query("owner_ob")!=ob)
     return notify_fail("这个鞭炮不是你的，你不能点。\n");
   
   tell_object(ob,"\n你小心翼翼地点燃了爆竹... ...\n\n");
   write(@LONG
   
[1;32m 只听[1;31m劈啪[1;32m声响起，一幅对联自爆竹下边落了出来！[2;37;0m 
   
    [42;1m[1;33m四季呈祥[2;37;0m
   
   [42;1m[1;33m岁[2;37;0m      [42;1m[1;33m家[2;37;0m
   [42;1m[1;33m岁[2;37;0m      [42;1m[1;33m家[2;37;0m
   [42;1m[1;33m年[2;37;0m      [42;1m[1;33m幸[2;37;0m
   [42;1m[1;33m丰[2;37;0m      [42;1m[1;33m福[2;37;0m
   [42;1m[1;33m添[2;37;0m      [42;1m[1;33m庆[2;37;0m
   [42;1m[1;33m美[2;37;0m      [42;1m[1;33m团[2;37;0m
   [42;1m[1;33m满[2;37;0m      [42;1m[1;33m员[2;37;0m
      
LONG);
   
   ob->add("potential",400);
   ob->add("food",1000);
   ob->add("water",1000);
   ob->add("char_lev/points",2);
   
   tell_object(ob,"\n你的潜能提高了，精神立刻变得饱满！\n"+
                  "你得到了"+HIY+" 两 "+NOR+"点属性！\n");
      
   destruct(this_object());
   return 1;
}