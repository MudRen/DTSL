
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIR"��"HIG"��"NOR, ({ "bian pao","bian","pao"}) );
   set_weight(150);
   
     set("material", "ֽ");
     set("unit", "��");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"��ã�ף��"HIY"����"NOR"���֣�\n"+
          "��л���"HIC"����˫��"NOR"��֧�֣�\n"+
          "ף�����µ�һ���﹤��˳����ѧϰ��������Զ���֣�\n"+
          "����һ�ұ��ڣ��������������ͻ�õ����ڵ����\n"+
          HIG"��dian bian pao��\n"NOR;
       
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
     return notify_fail("������ڲ�����ģ��㲻�ܵ㡣\n");
   
   tell_object(ob,"\n��С������ص�ȼ�˱���... ...\n\n");
   write(@LONG
   
[1;32m ֻ��[1;31m��ž[1;32m������һ�������Ա����±����˳�����[2;37;0m 
   
    [42;1m[1;33m�ļ�����[2;37;0m
   
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33m��[2;37;0m
   [42;1m[1;33m��[2;37;0m      [42;1m[1;33mԱ[2;37;0m
      
LONG);
   
   ob->add("potential",400);
   ob->add("food",1000);
   ob->add("water",1000);
   ob->add("char_lev/points",2);
   
   tell_object(ob,"\n���Ǳ������ˣ��������̱�ñ�����\n"+
                  "��õ���"+HIY+" �� "+NOR+"�����ԣ�\n");
      
   destruct(this_object());
   return 1;
}