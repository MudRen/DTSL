/*
 * File    : ���� (/d/clone/room/riowang/riowang_2_2.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 15:55:09 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
����һ����Ĵ����ӣ����ϸ߹���һ�����䡱�֣��Ե�ʮ
�������ɡ��������Ů�����ǲ�����˪��Riowang�������ǣ�Kuk
u������Ȼ�ڽ����϶��㲻�϶������ ��������Ϊ����ֱ�¸߾�
�������г�ҡ���˵���ǹ��������������ڴˣ���֪�������
Ȼ֪�����ǻ���Ϊ���ֵĸ����������   
LONG
);
        set("exits",([
	"west" : __DIR__"riowang_2_0",
    "east":"/d/clone/room/yzplayerhome/nandajie5",
	"southwest" : __DIR__"riowang_4_0",
	"north" : __DIR__"riowang_0_2",
        ]));
        setup();
//        replace_program(ROOM);
}
