//���ƾŲ���
//���������


#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me,object target)
{
        string msg,*doors,way;
        mapping exits;
        object room;
        int ap,vp;
  		
	if(!objectp(target=offensive_target(me)))
	 return notify_fail("��û�кͱ��˽��֣�û��Ҫʹ�á������������\n");
	 
	if(!me->is_fighting())
	return notify_fail("�����������ֻ����ս����ʹ�ã�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("xingyun-dodge",1))
		return notify_fail("��ѧ���ƾŲ����ʹ�á������������\n");
	if((int)me->query_skill("xingyun-dodge",1)<100)
		return notify_fail("������ƾŲ���Ϊ������\n");
	if((int)me->query_skill("dodge",1)<100)
		return notify_fail("��Ļ����Ṧ��Ϊ������\n");
	if(me->query("apply_points")<=0)
	return notify_fail("������Ʋ�����ʹ�á������������\n");
	
	if(time()-me->query_temp("perform_busy")<3)
      return notify_fail("����ʩչ�������������Ҫ������������֧�֣�����Ϊ������������У�\n");

        exits=environment(me)->query("exits");
        if(sizeof(exits)<=0)
        return notify_fail("����û�г��ڣ����޷�ʹ�á������������\n");
        if(!me->query("startroom"))
        return notify_fail("��û�������ĵط����޷�ʩչ�������������\n");
        room=load_object(me->query("startroom"));
        if(!room)
        return notify_fail("��û�������ĵط����޷�ʩչ�������������\n");
        
        msg=HIG"\n$N"+HIG+"�������̰�Ʈ���������Ľ��ɵ����С������������\n"NOR;
        message_vision(msg,me);
        
        ap=target->query_dex();
        vp=me->query_dex()+me->query_skill("xingyun-dodge",1)/5;
        
        if(random(ap+vp)>vp){
         msg=YEL"\n$n"+YEL+"��Ӧ��죬����һ������ס��$N"+YEL+"��ȥ·��\n"NOR;
         message_vision(msg,me,target);
        }
        else{
         msg=HIY"\n$N"+HIY+"����ɢȥ��$N"+HIY+"�Ѿ���Ӱ���٣�ֻʣ�°��յ�$n"+HIY+"��\n"NOR;
         message_vision(msg,me,target);
         me->move(room);
         me->set("force",0);
         me->set("apply_points",0);
        }
         
        
        me->set_temp("perform_busy",time());
        return 1;
}

