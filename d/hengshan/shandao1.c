// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Է�ɽ��");
        set("long", @LONG
�����ڼ��Է�ɽ��С·�ϣ�����ɽ��������ӹģ���ǰ����Ư����
�о����ݼ��ˡ�
LONG);
        set("exits", ([
           "southdown"  : __DIR__"beiyuedian",
           "northup"    : __DIR__"shandao2",
        ]));
        setup();
        replace_program(ROOM);
}

