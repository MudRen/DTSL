// purgebz.c
//by fengfei

#include <ansi.h>
#include <command.h>
#include <org.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
object ob;
string id;

if( !arg || sscanf(arg, "%s", id)!=1 ) return notify_fail("��Ҫ�����Ǹ�������\n");
        ob = LOGIN_D->find_body(id);
        if (ob) return notify_fail("�������ߣ�����kickout��\n");
  ORG_D->ShiZhong_BangZhu(me,id);
return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : purgebz <ĳ��>

ǿ��ĳ��������λ��ԭʼNPC�������Ρ�
HELP);
    return 1;
}

