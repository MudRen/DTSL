/*
 * File    : ��ɽ���� (/u/yanyan/dmjob/dmjob_6_11.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��ɽ����");
        set("long", @LONG
����������ɽ��һ�����ɽ�ڵ���ߡ���˵������ɽ�����緢����
������ǳ����ȣ����ܵ���ľ���Ѿ���ή�����������Ѿ����������Щ
�ڸ������ˡ�
LONG
);
        set("exits",([
	"southeast" : __DIR__"dmjob_8_13",
	"northdown" : __DIR__"dmjob_4_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
