/*
 * File    : ���� (/u/yanyan/dmjob/dmjob_4_19.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ������
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�������
�ڵ�˿��Ҳ�ޡ�
LONG
);
        set("exits",([
	"southup" : __DIR__"dmjob_6_17",
	"north" : __DIR__"dmjob_2_19",
	"east" : __DIR__"dmjob_4_21",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}