// drunk.c

inherit F_CLEAN_UP;
#include <ansi.h>
int update_condition(object me, int flag)
{
	object *usr;
	
	if(!me->query("pker"))
	 return 0;
	if(flag>2){
	usr=users();
	usr=filter_array(usr,"filter_listen",this_object());
	message("vision",HIM"��ҥ�ԡ�ĳ�ˣ���˵"+me->name()+HIM+"��"+
         MISC_D->find_place(environment(me))+HIM+"һ�����\n"NOR,usr);
         flag=1;}
        else flag++;
	me->apply_condition("pker_msg",flag);
	
	return 1;
}

int filter_listen(object ob)
{
  if(ob->query("pker")) return 0;
  return 1;
}
