/*
 * File    : С��ɽ (/u/yanyan/dmjob/dmjob_6_17.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С��ɽ");
        set("long", @LONG
�����ǵ���һ��С��ɽ��������Щ���ȣ���ɽ�ڵ������Ǵ�ݲ�����
Ҳ������Ұ�޵��㼣���������ʯ��״���죬�����˵�ǹ��񹤡�
LONG
);
        set("exits",([
	"northdown" : __DIR__"dmjob_4_19",
	"eastdown" : __DIR__"dmjob_6_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
