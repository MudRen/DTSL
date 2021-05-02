
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

int do_action(string arg);

void create()
{
   set_name("ذ��", ({ "bi shou","shou","dagger","sjb_mengshi_bishou" }) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "iron");
     set("long", "����һ��Сذ�ס�\n");
     set("wield_msg", "$N���$n�������С�\n");
     set("unequip_msg", "$N�����е�$n������䡣\n");
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
   return notify_fail("��Ҫ��ʲô���ģ�(mengshi with xxx)\n");
   obj=present(name,ob);
   if(!objectp(obj))
   return notify_fail("������û�����������\n");
   if(!obj->query("sjb_mengshi_bishou"))
   return notify_fail("��������������ģ�\n");
   if(!ob->query_temp("bai_sjb/step1"))
   return notify_fail("������û�����ĵı�Ҫ�ɣ�\n");
   
   msg="\n$N������������Ϊ�μұ����ң���\n\n"+
       "˵�գ�����"+obj->name()+"���Լ��ĸ첲����ȥ��\n"+
       HIR+"����һƬ��Ѫ����\n\n"NOR+
       "$N΢΢һЦ�������ӵ���"+obj->name()+"��\n";
   message_vision(msg,ob);
   ob->set_temp("bai_sjb/step2",1);
   ob->delete_temp("bai_sjb/step1",1);
   destruct(this_object());
   return 1;
}