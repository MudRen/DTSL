
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(HIR"��"NOR, ({"heart"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",HIR"����һ��Ѫ���ܵ��ģ���΢΢�����š�\n"NOR);
                set("unit", "��");
                set("food_remaining", 15);
                set("food_supply", 60);
                set("no_drop",1);
                set("no_give",1);
                set("no_steal",1);
        }
}

int do_eat(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ��ʲô��\n");
   
   if(!objectp(obj=present(arg,ob)))
   return 0;
   
   if(obj!=this_object())
   return 0;
   
   message_vision("$N�������е�"+query("name")+"��������Щ������\n"+
     "��æ����˫�ۣ��͵��ſڽ�"+query("name")+"�̽��˶������\n",ob);
   message_vision(HIB"\n$N"+HIB+"���˲��죬΢΢̧��ͷ��ֻ��Ŀ�������ѳ�����а��\n"NOR,ob);
   
   ob->set_temp("bai_yingui/step1",1);
   
   destruct(this_object());
   return 1;
}