
inherit ROOM;
 void create()
{
       set("short", "ɳʯ·");
       set("long", @LONG
��������ɳʯ·������������ǳ��ȣ�����Ҳ�Ƿǳ���ʪ������·
��û��ʲô������
LONG);
       set("exits", ([
               "north" : __DIR__"jiangan2",
               "southwest" : __DIR__"shalu2",
                    ]));

       setup(); 
       replace_program(ROOM);
}


