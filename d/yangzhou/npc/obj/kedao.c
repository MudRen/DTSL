

#include <weapon.h>

inherit BLADE;
int do_ke(string arg);
void create()
{
set_name("�̵�", ({ "ke dao","dao"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 100);
     set("material", "iron");
     set("long", "����һ��С�̵��������������Ͽ����֡�\n");
     set("wield_msg", "$N��$n�������С�\n");
     set("unequip_msg", "$N�����е�$n�Ż��¶��С�\n");
   }
   init_blade(5,10,10);
   setup();
}

void init()
{ 
	add_action("do_ke","ke");
}

int do_ke(string arg)
{
	object me,ob;
	string obs,name;
	me=this_player();
if(!present("ke dao",me))
return notify_fail("ʲô��\n");
	if(!arg||
		sscanf(arg,"%s %s",obs,name)!=2)
	return notify_fail("��ʹ�� ke ���� �����ȥ����\n");
	if(!objectp(ob=present(obs,me)))
		return notify_fail("�����˰��죬�������ϸ�����û�����������\n");
	if(!ob->query("skill_type"))
		return notify_fail("����ϸ���˿���Ŷ��ԭ���Ǹ����Ͳ���������\n");
	message_vision("$N����"+this_object()->name()+"��"+ob->name()+"�Ͽ���������\n",me);
	ob->delete_temp("apply/long");
	ob->set("long",name);
	message_vision("$N�����������ڿ̺��ˣ�\n",me);
	return 1;
}
	
