
#include <ansi.h>
inherit ITEM;

int do_eat(string arg);

void create()
{
   set_name(HIY"�±�"NOR, ({ "yue bing","bing"}) );
   set_weight(150);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�顸��Բз�ʡ��±����������ǳ��óԡ�\n");
     set("material", "��ɳ��");
     set("unit", "��");
     set("value",100);
     set("no_sell",1);
   }
   setup();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   object ob;
   ob=this_player();
   if(!arg)
   return notify_fail("��Ҫ��ʲô��\n");
   if(!present(arg,ob))
   return notify_fail("������û�����������\n");
   if(this_object()!=present(arg,ob))
   return notify_fail("�㻹���ȳ����±��ɣ�\n");
   if(ob->query("combat_exp")<200000)
   return notify_fail("����±����Ǹ���ģ��㲻�ܳԡ�\n");
   if(ob->query("give_present_eat"))
   return notify_fail("��һ���±��͹��ˣ��Զ��˻�ҭ���ģ�\n");
   ob->set("give_present_eat",1);
   ob->set_skill("literate",ob->query_skill("literate",1)+5);
   if(ob->query_skill("literate",1)>300)
   ob->set_skill("literate",300);
   tell_object(ob,YEL"�㼸�ڳԵ����±�������"+HIC+"������ʶ�֡�"+NOR+YEL+"����Щ������\n"NOR);
   ob->set("food",1000);
   ob->set("water",1000);
   destruct(this_object());
   return 1;
}