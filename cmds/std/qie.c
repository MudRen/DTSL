// qie . yanyan.2000.

#include <ansi.h>;
inherit F_CLEAN_UP;
inherit F_COMMAND;
inherit F_DBASE;

int main(object me, string arg)
{
     object weapon,shouji,corpse;
	 if(!arg)
		return notify_fail("��Ҫ��ʲô?\n");
	if(!objectp(corpse=present(arg, environment(me))))
	return notify_fail("����û�����������\n");
	if(!corpse->is_corpse())
	return notify_fail("�����������ʬ�壬�����У�\n");
	if(corpse->query("no_head"))
	return notify_fail("���Ѿ�����ͷ��ʬ����!\n");
	if(!objectp(weapon=me->query_temp("weapon")))
	return notify_fail("����ʲô��?\n");
	
if((string)weapon->query("skill_type")=="sword"||(string)weapon->query("skill_type")=="blade"
 ||(string)weapon->query("skill_type")=="dagger"
 ||(string)weapon->query("skill_type")=="axe") 
  {  
	  shouji=new("/obj/shouji");  
	  shouji->set("dead_id",(string)corpse->query("dead_id"));
          shouji->set("killed_by",(string)corpse->query("killed_by")); 
	  shouji->set("long","����"+corpse->name()+"���׼�\n");
	  corpse->set("name","��ͷʬ��");	 
	  corpse->set("long","����һ��ʬ�壬���Էֱ治������˭��\n");
	  corpse->set("no_head",1);
	  shouji->move(me);			
	message_vision(HIR"ֻ�����ۡ���һ����$N������ʬ����׼�������һƬѪ�⣡\n"NOR,me);  
return 1;} 
      else return notify_fail("�����������������ʬ��!\n");
	  

}