
#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me,string arg)
{
    
	object master;
	if(!arg) return notify_fail("��Ҫ��˭��ְ��\n");
	if(!objectp(master=present(arg,environment(me))))
		return notify_fail("����û�������!\n");
	if(me->query("vocation"))
	return notify_fail("����������һ��ְҵ������suicide -f �ɣ�\n");
	if(!master->query("vocation"))
		return notify_fail("����˲�����������һ��ְҵ������\n");
	if(me->query("vocation")==master->query("vocation"))
		return notify_fail("���Ѿ���������ְҵ�ˣ�\n");
	me->set("vocation",master->query("vocation"));
	me->set("vocation_score",0);
	me->set("vocation_exp",me->query("vocation_exp")/3);
	if(master->query("killer"))
		me->set("killer",1);
	message_vision("$N������$nѧϰ����Ϊһ��"+master->query("vocation")+"��\n",me,master);
    return 1;
}
