// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *inv;
	int i;
	
	if(!arg)
	return notify_fail("use destruct xxx\n");
	inv=children(arg);
	for(i=0;i<sizeof(inv);i++)
	  destruct(inv[i]);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dest [-r] <���֮���ƻ���>

���ô�һָ��ɽ�һ�����(object)���������(class)�Ӽ�������������������
������(����ָ�������������)����һ�βο�����������ʱ������½������롣

���� (admin) ��ֵ���ʦ������ -r ѡ���� ROOT_UID ���������������������
ʹ���ߡ�

�ο����ϣ� destruct()
HELP
    );
    return 1;
}
