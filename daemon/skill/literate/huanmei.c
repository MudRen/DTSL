//�Ĺ�����
//����

#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap,vp;
	
	if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
        
	if(target==me)
			return notify_fail("���Ĺ�������ֻ�������������ˣ�\n");
	if(me->query("gender")!="Ů��")
	return notify_fail("ֻ��Ů����ʹ���Ĺ�����ȥ�Ի���ˣ�\n");
	if(me->query("age")>60)
	return notify_fail("�������̫���ˣ�˭�������Ի�\n");
	if(target->query("gender")=="Ů��")
	return notify_fail("�Է�Ҳ��Ů�ˣ�ʹ���Ĺ������������κ�Ч����\n");
	if(!me->is_fighting())
	return notify_fail("���Ĺ�������ֻ����ս����ʹ�ã�\n");
	if(!living(target))
		return notify_fail("���ȰѶԷ�Ū�����Ի�Է��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("meigong-huanshu",1))
		return notify_fail("��ѧ�Ĺ��������ʹ�á����ġ���\n");
	if((int)me->query_skill("meigong-huanshu",1)<110)
		return notify_fail("����Ĺ�������Ϊ������\n");

        if(time()-me->query_temp("exert_busy/huanmei")<15)
        return notify_fail("���������㣬�޷�ʩչ�����ġ���\n");
        
        ap=me->query_skill("meigong-huanshu",1)/10;
        ap=ap*me->query_per()/(me->query_per()+60);
        
        vp=me->query_skill("chanzong-fofa",1)/10;
        vp=vp*me->query_per()/(me->query_per()+40);
        
        if(vp<=0) vp=random(ap/2);
        
        if(target->query("class")=="bonze")
        vp=vp*2;
        
        if(random(ap+vp)>vp){
          msg=HIY"\n$N"+HIY+"�����������������"+RANK_D->query_self(me)+"���ˣ����͵���������������ӯӯ����Ŀ����\n"+
              "��ˮ������$n"+HIY+"�� $N"+HIY+"�Ƕ��˵���̬�����������ŵ����Ĺ���γ��⼫��\n"+
              "�ĶԱȣ���ʹ�����𲻹�һ�У��������ׯ��������������\n"NOR;
          message_vision(msg,me,target);
          
          msg="\n$N��־ȫ����ֻ���ö�����ɱ�������Ҷᣬȫ�Ǿ��������һ���£���Ȼ\n"+
              "�����Լ���ս���С�\n";
          message_vision(msg,target);
          
          target->start_busy(3);
          target->set("apply_points",0);
          me->set_temp("perform_busy",time());
          me->set_temp("exert_busy/huanmei",time());
          return 1;
        }
        
        msg=HIY"\n$N"+HIY+"������������������Ŀ����̾��һ������ �ѽ��۵����ֵݸ�$n"+HIY+"����\n"+
            "���Ƶĵ�����"+RANK_D->query_respect(target)+"�����˼������𣿡� \n"NOR;
        message_vision(msg,me,target);
        msg="\n$n׿��������Ŀ�ޱ���ص�ͷ����$N���·�$Nֻ�Ǽ�û�����������\n"+ 
            "$N��������������$N������е������������ܶ���ȫ��¶�˳�����\n";
        message_vision(msg,me,target);
        me->start_busy(1);
        me->set_temp("perform_busy",time());
        me->set_temp("exert_busy/huanmei",time());
        return 1;
}

