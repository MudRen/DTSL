//����ӡ
//������
//by rzy 02.09.20

#include <ansi.h>
inherit SSERVER;

int execute(object me,object victim) {
	int i;
	string msg;

	if(victim!=me)
		return notify_fail("�㲻�ܶԱ���ʹ������ķ���\n");
	
	if(me->query_skill("huachan",1))
		return notify_fail("��ѧ�˻������޷�ʩչ����ӡ��\n");
	if(me->query_skill("busi-yin",1)<130)
		return notify_fail("��Ĳ���ӡ��Ϊ������\n");
	if(me->query_temp("execute_shengsi"))
		return notify_fail("������ʹ�á�����������\n");
	if(time()-me->query_temp("execute_busiyin_busy")<10)
		return notify_fail("��ո�ʩ���ù�������������������Ϣ��δƽ����\n");  
	if(me->query("max_force")<2000)
		return notify_fail("���������Ϊ�޷�ʹ��������������\n");
	if(me->query("force")<1000)
		return notify_fail("����������㣡\n");


	message_vision(HIW"\n$N"+HIW+"˫����Ȼ��������������籩��"+HIY+"��������ȫ���ռ�Ŀ�쮼�Х��\n"+
			HIG+"\nһɲ�Ǽ��ֱ��ϸ����֯��"+MAG+"�����ھ�����ǧ˿���ơ�\n\n"+
			HIR+"��˹���ı仯��ֻ���ڻ������������˵�"+HIC+"����ӡ��"+HIR+"ʼ�ܰ쵽���������ɱ�Ϊ�������ɱ�Ϊ����\n"NOR,me);
		i=me->query_skill("busi-yin",1)*2/3+me->query("apply_points");
		me->add_temp("apply/damage",i);
		me->set_temp("execute_shengsi",1);
		me->add("force",-500);

		call_out("rid_damag",me->query_skill("busi-yin",1)/10,me,i);
		return 1;   
}

void rid_damag(object me,int i) {
	if(!me)
		return;
	message_vision(HIC"\n$N"+HIC+"��Ŀ���ú����ѩ�����ǲ����κ�����ĸ��飬��Ȼ�ֱ���է�֣�$N��̾һ����\n���������ջ�����������\n"NOR,me);
	me->add_temp("apply/damage",-i);
	me->delete_temp("execute_shengsi");
	me->set_temp("execute_busiyin_busy",time());
	return;
}