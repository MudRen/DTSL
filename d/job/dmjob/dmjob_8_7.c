/*
 * File    : ����� (/u/yanyan/dmjob/dmjob_8_7.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
����������ɽ��������ˡ�����«έ������������������˵ÿ�궼
����������������Ϣ��������֮Ϊ�������һ��΢�紵����«έ�ں�
��������ذڶ��š�
LONG
);
        set("exits",([
	"east" : __DIR__"dmjob_8_9",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
