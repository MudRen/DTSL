//��ħ�ػꡣ
#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int exert(object me, object target)
{
        string msg;
        int eff_kee,time;
	
	if(target!=me)
			return notify_fail("����ħ�ػ꡹���������������ˣ�\n");
	if(!me->is_fighting())
	return notify_fail("����ħ�ػ꡹ֻ����ս����ʹ�ã�\n");
	if(!living(target))
		return notify_fail("�ǲ��Ǹ�����Ү��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(me->query("eff_kee")*100/me->query("max_kee")>30)
	return notify_fail("���ܵ��˲��أ�û�б�Ҫʹ�á���ħ�ػ꡹��\n");
	if(!me->query_skill("tianmo-dafa",1))
		return notify_fail("��ѧ��ħ�����ʹ�á���ħ�ػ꡹��\n");
	if((int)me->query_skill("tianmo-dafa",1)<160)
		return notify_fail("�����ħ����Ϊ������\n");
	if((int)me->query_skill("force",1)<160)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
        if(me->query("force")<300)
        return notify_fail("��Ŀǰ�������޷�ʩչ����ħ�ػ꡹��\n");
        if(me->query("apply_points")<180)
        return notify_fail("��Ŀǰ�������޷�ʩչ����ħ�ػ꡹��\n");
        
        if(time()-me->query_temp("exert_busy/huihun")<30)
        return notify_fail("���������㣬�޷�ʩչ����ħ�ػ꡹��\n");
        
        if(me->query_temp("exert_action/huihun"))
        return notify_fail("������ʩչ����ħ�ػ꡹��\n");
        
        if(me->query("eff_kee")*100/me->query("max_kee")>=100)
        return notify_fail("������û�����ˣ�û�б�Ҫʹ�á���ħ�ػ꡹��\n");
        
        eff_kee=me->query("eff_kee");
        time=me->query_skill("tianmo-dafa",1)/20;
        if(time>10)
        time=10;
        
        msg=HIR"\n$N"+HIR+"���˲��ᣬ����ȴ��ˮ�㹥���� \n"+
            "$N"+HIR+"��һҧ��������Ե��ġ���ħ�ػ꡹����ʱɱ�����죡\n"NOR;
        message_vision(msg,me);
	
        me->set_temp("exert_action/huihun",1);
        me->set_temp("exert_busy/huihun",time());//Ҫ�м��ʱ��
        me->set_temp("perform_busy",time());//ʹ�ú󣬲�������ʹ�� perform
        
        me->set("eff_kee",me->query("max_kee"));
        me->set("apply_points",0);
        me->add("force",-300);
        
        call_out("do_check",1,me,eff_kee,time);
        
        return 1;
}

void do_clear(object me)
{
        me->delete_temp("exert_action/huihun");
        me->set_temp("exert_busy/huihun",time());
        me->set_temp("perform_busy",time());
}

void do_check(object me,int eff_kee,int time)
{
    string msg;
    
    if(!me)
    return;
    if(me->is_ghost()){
     do_clear(me);
     return;
    }
    time--;
    if(time<=0){
      
      msg=HIG"\n$N����һ���³�һ�����Ѫ�������á���ħ�ػ꡹ѹ�Ƶ��������ٶȸ����ˡ�\n"NOR; 

      if(me->query("eff_kee")<eff_kee){
      	message_vision(msg,me);
      	do_clear(me);
      	return;
      }
      eff_kee=eff_kee-20;
      if(eff_kee<0) eff_kee=10;
      me->set("eff_kee",eff_kee);
      message_vision(msg,me);
      do_clear(me);
      return;
   }
   me->set("eff_kee",me->query("max_kee"));
   call_out("do_check",1,me,eff_kee,time);
}
   