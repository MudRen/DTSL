/*
 * File    : ���� (/d/clone/room/riowang/riowang_2_0.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
����һ�����ң�����ʮ����͡������м���һ�Ŵ󴲣�����
��ɫ����ļҾߺ���Ʒ������һ�ֱ����������ӡ����������ĳ�
����
LONG
);
        set("exits",([
	"east" : __DIR__"riowang_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
