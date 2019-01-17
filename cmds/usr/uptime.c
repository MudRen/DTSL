// uptime.c

inherit F_CLEAN_UP;
#include <ansi.h>
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��\n";

	write(GRN "����˫���Ѿ�������" + time + NOR);
       printf(YEL"[ ����ʱ�� ] "+ CHINESE_D->chinese_newdate( time(), 1 ) +NOR+ "\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ���������Ϸ�Ѿ�����ִ���˶��.
 
HELP
    );
    return 1;
}
