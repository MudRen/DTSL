// /d/gaoli/xiangfang2.c
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create()	
{
	set("short", "�᷿");
	set("long", @LONG
�ݵ��м���һ�ŷ�����������ͷ���������ǺȾƣ���̳�ӱ�ض�
�ǣ�ǽ�Ϲ��ż��Ѹֵ������м����˵��ڴ��Ϻ�����˯��
LONG);
set("exits", ([
                "north" : __DIR__"siheyuan",       
	]));
       setup();
	
}	
