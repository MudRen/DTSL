//form.
//dtsl
inherit F_CLEAN_UP;
#include <skill.h>

#define FORM "/daemon/skill/form/"

int main(object me, string arg)
{
    object target;
    object *mem;
    
    if(!arg)
    return notify_fail("��Ҫʹ��ʲô�󷨣�\n");
    if(!me->query_temp("team_mark/form"))
    return notify_fail("��û������κ��󷨡�\n");
    if(me->query_temp("team_mark/form")!=arg)
    return notify_fail("��û���������󷨣������Ƚ�������[team form]��\n");
    mem=me->query_team();
    if(sizeof(mem)<=1)
    return notify_fail("ʹ���������������ˡ�\n");
    if(!objectp(target=me->query_temp("last_damage_from")))
    return notify_fail("����û����Ҫ������Ŀ�꣡\n");
    if(file_size(FORM+arg+".c")<=0)
    return notify_fail("���ļ��������⣬�뾡�챨����ʦ��\n");
    return call_other(FORM+arg+".c","form",me,target);
    	
}

int help()
{
  write("
����ʹ������������߶�����ʹ�õ��󷨡�
�� form yuehen��
ǰ����������� team form ��������󷨣�
����������Ƕ�������죬�������Լ�
��ս��Ŀ�������kill����ʹ���󷨵���
��������ս��Ŀ����kill������ֻ�ǽ�
��fight ��ʽ��
\n");
return 1;
}