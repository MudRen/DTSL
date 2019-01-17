// kill.c

#include <ansi.h>
#include "valid_kill.h";
#include <org.h>

#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;

string get_kill_msg(string arg)
{
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);	
	
	//arg = replace_string(arg, "$N", "$N"+CYN);
	//arg = replace_string(arg, "$n", "$n"+CYN);
	
	return arg+NOR;
	
}

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	string kill_msg;
	
	seteuid(getuid());
	
	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
        if( (environment(me)->query("no_fight")||
	 environment(me)->query("sleep_room"))&&!obj->query("pker") )
		return notify_fail("���ﲻ׼ս����\n");
        if( me->query_temp("ridee") )
          return notify_fail("�㻹����������!\n");
        if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("�������������أ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
        
        if(objectp(obj->query_temp("city_war_guard")))
        return notify_fail("�Է������������أ�\n");
        
	if(stringp(obj->query("target_id"))&&obj->query("target_id")!=me->query("id"))
	return notify_fail(obj->name()+"������������ս������\n");
	if(arrayp(obj->query("target_id"))&&
	   member_array(me->query("id"),obj->query("target_id"))==-1)
	   return notify_fail(obj->name()+"������������ս������\n");
	
	if(userp(me)&&userp(obj)&&
	   me->query("shili/name")&&obj->query("shili/name")){
	  if(me->query("shili/name")==obj->query("shili/name"))
	   return notify_fail("ͬһ�����Ӳ�Ҫ��ɱ�ˣ�\n");
	  if(ORG_D->if_friend_org(me,obj))
	   return notify_fail("���˰����Ӽ䲻�ܻ�ɱ��\n");
	}
	
	if(!valid_kill(me,obj)) return 0;
	callname = RANK_D->query_rude(obj);
	if(userp(obj)&&obj->query("age")<13)
        return notify_fail("��ôС����Ҷ�ɱ����̫�������������ˣ�\n");
	if(userp(obj)&&me->query("age")<13)
        return notify_fail("����书��ô�ͣ����ǲ�Ҫɱ���ˣ���\n");
	if(obj->query("accept_kill"))
		if(!obj->accept_kill(me,obj))
        	return (int)obj->accept_kill(me,obj);
	if( userp(obj))
   		log_file( "KILL_LOG", sprintf("(%s)%s tried to kill %s\n", ctime(time()), me->query("name"), obj->query("name")));
        
	if(stringp(me->query("env/kill_msg")))
         kill_msg = "\n"+me->query("env/kill_msg")+"\n\n";
	else kill_msg = "\n$N����$n�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n";
	
	message_vision(get_kill_msg(kill_msg),me,obj);

	me->kill_ob(obj);
	if( !userp(obj) )
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() 
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�������ָ��: fight
HELP
    );
    return 1;
}
 
