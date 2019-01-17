// /mudinfo.c
#include <mudlib.h>
#include <command.h>
#include <dbase.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_CMD;
 
#define SCALE	(1.0/10.0)
#define STATUS	"��ʽ������"

string memory_expression(int m);

void create() 
{ 
			seteuid(getuid(this_object())); 
}  

int main() {
   	float value;
  	
	write(YEL"��"+GRN+" Mud ��ʶ�����ƣ�  " + MUDLIB_NAME + ".\n");
	write(YEL"��"+GRN+" Mud ����·���֣�  " + INTERMUD_NAME + ".\n");
	write(YEL"��"+GRN+" ��������ҵƽ̨��  " + "Linux(Redhat 5.2)\n");
	write(YEL"��"+GRN+" ����ϵͳ�İ汾��  " + __VERSION__ + " driver \n");  
	write(YEL"��"+GRN+" ϵͳ������汾��  " +"Datang ShuangLong Mudlib"+ " " + MUDLIB_VERSION_NUMBER + ".\n"); 
  write(YEL"��"+GRN+" CPU �ĸ���״����  " + query_load_average() + ".\n");
  printf(YEL"��"+GRN+" ��ʹ�õļ����壺  %s bytes.\n", memory_expression(memory_info()) ); 
	write(YEL"��"+GRN+" ����ʹ����������  " + sizeof( users() ) + "����������.�������300\n");
	write(YEL"��"+GRN+" ��������������  " + sizeof( objects() ) + " �����.\n");
	write(YEL"��"+GRN+" ����ִ�е�ʱ�䣺  " + CHINESE_D->chinese_period(uptime()) + "\n");
	write(YEL"��"+GRN+" Mud ���ڵ�״̬��  " + STATUS + ".\n"+NOR);
	return 1; 
}

string memory_expression(int m)
{
	float mem;

	mem = m;
	if( mem<1024 ) return m + "";
	if( mem<1024*1024 )
		return sprintf("%.2f K", (float)mem / 1024);
	return sprintf("%.3f M", (float)mem / (1024*1024));
}

int help() {

   write(@HELP
ָ���ʽ��mudinfo

���ָ�����ʾ�й���� Mud ��һЩϵͳ��Ѷ�� 

HELP
	);
	 return 1; 
}
 
