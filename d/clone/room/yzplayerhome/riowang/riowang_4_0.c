/*
 * File    : ���� (/d/clone/room/riowang/riowang_4_0.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
�����ǳ���������ư��������ȫ����ʱʱ�����ʵ����Ϲ�Ӧ��
��˵������һﲻ��ˣ���Ӳ���������Ҳ��һ��Ŷ������������
����Щɽ�亣ζ����˳��һ���ڸ���
LONG
);
        set("exits",([
	"northeast" : __DIR__"riowang_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
