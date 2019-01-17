// kill.c

#include <ansi.h>
#include "valid_kill.h";
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	object *t;
	int i;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	
	if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("�������������أ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
	
	if(objectp(obj->query_temp("city_war_guard")))
        return notify_fail("�Է������������أ�\n");

	callname = RANK_D->query_rude(obj);
        t = me->query_team();
	if(sizeof(t) <=1)
	return notify_fail("�����ڲ�û�вμ��κζ�������ֻ��һ���ˡ�(use kill)\n");
	
	if(userp(obj)&&obj->query("age")<13)
        return notify_fail("��ôС����Ҷ�ɱ����̫�������������ˣ�\n");
        if(userp(obj)&&me->query("age")<13)
        return notify_fail("����书��ô�ͣ����ǲ�Ҫɱ���ˣ���\n");
        if(obj->query("accept_kill"))
          if(!obj->accept_kill(me,obj))
           return (int)obj->accept_kill(me,obj);
       
       if(stringp(obj->query("target_id"))&&obj->query("target_id")!=me->query("id"))
	return notify_fail(obj->name()+"������������ս������\n");
	if(arrayp(obj->query("target_id"))&&
	   member_array(me->query("id"),obj->query("target_id"))==-1)
	   return notify_fail(obj->name()+"������������ս������\n");
        if(!valid_kill(me,obj)) return 0;
        
	if( userp(obj))
   log_file( "KILL_LOG", sprintf("(%s)
%s tried to kill with team %s\n", ctime(time()), me->query("name"), obj->query("name")));
	/*if( userp(obj) )
		return notify_fail("������ɲ����Ըĵ������۹ѵĶ�ϰ��\n");*/
	for(i=0;i<sizeof(t);i++)
	if( t[i])
	if( environment(me) != environment(t[i]))
		return notify_fail("��Ա�����ڳ���(use kill)\n");		
	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ��������������ǻ��\n\n", me, obj);
        for(i=0;i<sizeof(t);i++)
	{
	if(t[i]){
		
		if(stringp(obj->query("target_id"))&&obj->query("target_id")!=t[i]->query("id"))
	        continue;
	        
	        if(objectp(t[i]->query_temp("city_war_guard")))
                continue;
                
	        if(arrayp(obj->query("target_id"))&&
	   member_array(t[i]->query("id"),obj->query("target_id"))==-1)
	   continue;
        if(!valid_kill(t[i],obj)) continue;
        if(t[i]->query("age")<13) continue;
        if( userp(obj))
   log_file( "KILL_LOG", sprintf("(%s)
%s tried to kill %s\n", ctime(time()), t[i]->query("name"), obj->query("name")));

                t[i]->set_temp("ttarget",obj->query("id"));
		t[i]->kill_ob(obj);
		if(!userp(obj))
		 obj->kill_ob(t[i]);
		else
		 obj->fight_ob(t[i]);
		}
	}
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : teamkill <����>
 
���ָ������Ķ�����������һ�����
�������ָ��: team,fight,kill

HELP
    );
    return 1;
}
 
