
inherit ROOM;
 void create()
{
       set("short", "ɳʯ·");
       set("long", @LONG
��������ɳʯ·���ϱ���һƬ�ȴ����֣���˵�����кܶ඾�����ޡ�
�㲻�ɵ�С��������
LONG);
       set("exits", ([
               "northeast" : __DIR__"shalu1",
               "southwest" : __DIR__"shulin1",
                    ]));

       setup(); 
       replace_program(ROOM);
}


