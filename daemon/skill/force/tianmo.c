//��ħ������
#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int exert(object me, object target)
{
	object *ob;
	int ap,dp,i;
	string msg;
	
	if(target==me)
			return notify_fail("����ħ������ֻ�������������ˣ�\n");
	if(!me->is_fighting())
	return notify_fail("����ħ������ֻ����ս����ʹ�ã�\n");
	if(!living(target))
		return notify_fail("�ǲ��Ǹ�����Ү��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("tianmo-dafa",1))
		return notify_fail("��ѧ��ħ�����ʹ�á���ħ��������\n");
	if((int)me->query_skill("tianmo-dafa",1)<120)
		return notify_fail("�����ħ����Ϊ������\n");
	if((int)me->query_skill("force",1)<120)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
        
        if(time()-me->query_temp("exert_busy/tianmo")<10)
          return notify_fail("����ʩչ����ħ��������Ҫ������������֧�֣�����Ϊ������������У�\n");
	
	msg=HIB"\nΧ��$N"+HIB+"�����˶�����Ҫ��ǰ����Ŀ��¸о���$N��ħ����ɲ�Ǽ����������ޣ�\n"+
	       "��Χ�Ŀ������Ǹ�һ���ӳ�Ǭ�ˣ���Χ��Բ������Ŀռ��Ȼ������ȥ����һ\n"+
	       "���޵����\n\n"NOR;
	message_vision(msg,me);
	ob=all_inventory(environment(me));
	
	for(i=0;i<sizeof(ob);i++){
	 if(!living(ob[i])) continue;
	 if(ob[i]==me) continue;
	 if(!me->is_fighting(ob[i])) continue;
         ap=me->query_skill("force",1)+me->query("apply_points");
         dp=ob[i]->query_skill("force",1)+ob[i]->query("apply_points");
        
          if(random(ap+dp)>dp){
           tell_object(ob[i],HIY"����������ħ�����У����Ʋ��ɵ�Ѹ�ٽ��ͣ�\n"NOR);
           ob[i]->set("apply_points",ob[i]->query("apply_points")/10);
          }
          else
          message_vision("\n$N���Ʋ����æ�����������Ѷ�����\n",ob[i]);
        }
        
        me->set_temp("exert_busy/tianmo",time());//yun tianmo Ҫ�м��ʱ��
        me->set_temp("perform_busy",time());//ʹ�ú󣬲�������ʹ�� perform
        
        return 1;
}
