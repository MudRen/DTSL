/*
 * File    : ����ɽ�� (/u/yanyan/dmjob/dmjob_0_13.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����ɽ��");
        set("long", @LONG
����������ɽ�ڵ���ڴ��ˡ�ֻ������ɽ�������������ƶˣ�����
�ǳ���Ҫ��ǰ����һ����ʯ·�����ܲ�ʱ���������е����������ﾰɫ
�������������¡�
LONG
);
        set("exits",([
        "northup":"/d/dongming/shanya2",
	"south" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
        replace_program(ROOM);
}
