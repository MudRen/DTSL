//��ħ���١�
//ħ�ݡ�

#ifndef GO_CMD
#define GO_CMD "/cmds/std/go.c"
#endif
         

#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me,object target)
{
        string msg,*doors,way;
        mapping exits;
        int ap,vp;
  		
	if(!objectp(target=offensive_target(me)))
	 return notify_fail("��û�кͱ��˽��֣�û��Ҫʹ�á���ħ�ݡ���\n");
	 
	if(!me->is_fighting())
	return notify_fail("����ħ�ݡ�ֻ����ս����ʹ�ã�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("tianmo-huanzong",1))
		return notify_fail("��ѧ��ħ�������ʹ�á���ħ�ݡ���\n");
	if((int)me->query_skill("tianmo-huanzong",1)<100)
		return notify_fail("�����ħ������Ϊ������\n");
	if((int)me->query_skill("dodge",1)<100)
		return notify_fail("��Ļ����Ṧ��Ϊ������\n");
	if(me->query("apply_points")<=0)
	return notify_fail("������Ʋ�����ʹ�á���ħ�ݡ���\n");
	
	if(time()-me->query_temp("perform_busy")<3)
      return notify_fail("����ʩչ����ħ�ݡ���Ҫ������������֧�֣�����Ϊ������������У�\n");

        exits=environment(me)->query("exits");
        if(sizeof(exits)<=0)
        return notify_fail("����û�г��ڣ����޷�ʹ�á���ħ�ݡ���\n");
        
        msg=HIG"\n$N"+HIG+"��Цһ�����������һζ���������������С���ħ�ݡ���\n"NOR;
        message_vision(msg,me);
        
        ap=target->query_dex();
        vp=me->query_dex()+me->query_skill("tianmo-huanzong",1)/5;
        
        if(random(ap+vp)>vp){
         msg=YEL"\n$n"+YEL+"��Ӧ��죬����һ������ס��$N"+YEL+"��ȥ·��\n"NOR;
         message_vision(msg,me,target);
        }
        else{
         msg=HIY"\n$N"+HIY+"����ɢȥ��$N"+HIY+"�Ѿ���Ӱ���٣�ֻʣ�°��յ�$n"+HIY+"��\n"NOR;
         message_vision(msg,me,target);
         
         GO_CMD->do_flee(me);
         me->set("force",0);
         me->set("apply_points",0);
        }
         
        
        me->set_temp("perform_busy",time());
        return 1;
}

