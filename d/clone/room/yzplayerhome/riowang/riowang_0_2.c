/*
 * File    : ��¥ (/d/clone/room/riowang/riowang_0_2.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��¥");
        set("long", @LONG
һ���ţ�һ�����Ϯ����Ŷ��������һ��С��¥���������
���С�֣��Ե�ʮ������Ȥ����˵��Ů���˳��������ﹲ�����䡣
LONG
);
        set("exits",([
	"south" : __DIR__"riowang_2_2",
	"east":"/d/clone/room/yzplayerhome/nandajie5",
        ]));
        setup();
//        replace_program(ROOM);
}
