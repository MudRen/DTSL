
inherit ROOM;
 void create()
{
       set("short", "�ݵ�");
       set("long", @LONG
������Ƭ�ݵء�ʪ��Ŀ����˱Ƕ������������������ˮ����������
�м�ֻҰ�ô��������������
LONG);
       set("exits", ([
               "north" : __DIR__"tulu1",
               "southwest" : __DIR__"jiangan1",
                    ]));

       setup(); 
       replace_program(ROOM);
}


