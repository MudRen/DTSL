
inherit ROOM;
 void create()
{
       set("short", "�ȴ�����");
       set("long", @LONG
����һƬ�ȴ����֡����Ѿ��������ֵ��ڲ����㲻��С����������
��˵���Ǻ��������ȴ���������·�ġ�
LONG);
       set("exits", ([
               "north" : __DIR__"shulin1",
               "southwest" : __DIR__"shulin3",
                    ]));

       setup(); 
       replace_program(ROOM);
}


