// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "��¡ɽ");
        set("long", @LONG
��ɽ��������ɽ���ϣ���Ȼ���ܲ�������ɼ���ɡ��롢���������
ľ����ľ�ԡ����͵��䣬�ļ����ࡣ����̫�ס���ҺȪ�����СϪɽ����
�������������д�Ͽ�ӣ��峺���ף��ϱ���ԽϿ�ȡ�������ʪ�����½�
�ͣ�Ϊ��������ʤ�ء�
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "north" : __DIR__"silk5",
        ]));

       /* set("objects", ([
                __DIR__"npc/muren" : 2,
        ]));*/

        setup();
        replace_program(ROOM);
}
