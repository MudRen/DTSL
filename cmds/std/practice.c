
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string skillname,base,type;
   int skill, skill_basic,sen;int cost;

   if(!arg||sscanf(arg,"%s for %d",arg,cost)!=2)
   return notify_fail("��ʹ��practice|lian ���� for ������\n");
   if(cost<=0)
   return notify_fail("������������㣡\n");
   if(cost>=1000)
   return notify_fail("�㻹����ϧһ���Լ�������ɣ�\n");
   if(environment(me)->query("no_fight"))
   return notify_fail("�����ֹ��ϰ�书��\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   if( me->is_fighting() )
     return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
   if(!me->query_skill(arg,1)) return notify_fail("�㲢û��ѧ���ּ���!\n");
   type=SKILL_D(arg)->query_type();
   if(type&&(type=="knowledge"||type=="base"))
   return notify_fail("������ܲ�����ϰ��\n");
   skill=(int)me->query_skill(arg,1);
   base=SKILL_D(arg)->query_base();
   skill_basic=(int)me->query_skill(base,1);
   if(!skill_basic)
   return notify_fail("�㻹����ѧѧ��������ɣ�\n");
if((skill_basic)<skill)
	   return notify_fail("�㻹���Ȱѻ�������ѧ������ϰ��!\n");
   if((int)me->query("sen",1)<20)
	   return notify_fail("�����ڵľ����Ǻܺ�,������ϰ!\n");
   if((int)me->query("sen",1)<cost*20)
	   return notify_fail("�����ڵľ������Խ�������ǿ�ȵ���ϰ!\n");
   if(type=="hand")
   if(me->query("force")<=10*cost)
    return notify_fail("�������̫���ˣ�\n");
   skillname=to_chinese(arg);
   if(SKILL_D(arg)->practice_skill(me))
   {
           me->add("sen",-cost*20);
           if(type=="hand")
           me->add("force",-10*cost);
           me->improve_skill(arg,(skill/5+skill_basic/2+random(20))*cost);
	   message_vision("$N���ĵ�����"+skillname+"��\n",me);
	   return 1;
   }
   else (int)SKILL_D(arg)->practice_skill(me);
   
   
}

int help(object me)
{
   write(@TEXT
ָ���ʽ��practice <��������>

���ָ��������ϰĳ������ļ���.
�÷��� lian(practice) �书���� lian tianmo-jianfa
��������Ļ��������㹻�ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
   );
   return 1;
}
