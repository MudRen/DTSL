#include <ansi.h>
inherit ITEM;

int do_du(string arg);
void create()
{
   set_name(HIR"����ɢ"NOR, ({"du longsan","du","san"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "���������ɵĲ�����ҩ[����ɢ]��\n");
	 set("poision",10);
     set("unit", "��");
     set("value", 200);
     
   }

}

void init()
{
	add_action("do_du","xiadu");
}

int do_du(string arg)
{
   object victim,ob,me;
   me=this_player();
   ob=this_object();
	if(!arg) return notify_fail("�����˭�¶�?\n");
   if(!objectp(victim=present(arg,environment(me))))
	   return notify_fail("����û�������!\n");
   victim->apply_condition("dulongsan",6+random(6));
   if(userp(victim))
	   tell_object(victim,"��е���Щ����,ԭ����"+me->name()+"�������˶�ҩ!\n");
   else victim->kill_ob(me);
   destruct(ob);
   return 1;
}
