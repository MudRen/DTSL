/*
 * File    : ʯ�� (/u/yanyan/dmjob/dmjob_6_19.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ʯ��");
        set("long", @LONG
������һ��ʯ�֣�������һ��С��ɽ�������ʯ�־��ǻ�ɽ������
�����γɣ�������״���죬�������һ�㡣���������쳣���㲻��
��ʼ��Щ�ڿ��ˡ�
LONG
);
        set("exits",([
	"westup" : __DIR__"dmjob_6_17",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
