/*
 * File    : ��ɽ�� (/u/yanyan/dmjob/dmjob_8_13.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ɽ��");
        set("long", @LONG
������һ����ɽ�ڡ�ֻ������ð������������γ��������Ʈ����
���С���Щ�ط���ʱӿ�������ɫ�ҽ�����ɽ�����ʶ�ȥ������ǳ���
�ȣ��������Щ�Ժ��ˡ�
LONG
);
        set("exits",([
	"northwest" : __DIR__"dmjob_6_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
