
inherit ROOM;
 void create()
{
       set("short", "�ȴ�����");
       set("long", @LONG
����һƬ�ȴ����֡����Ѿ��������ֵ��ڲ����㲻��С����������
˵���Ǻ��������ȴ���������·�ġ�
LONG);
       set("exits", ([
               "northeast" : __DIR__"shulin2",
               "southwest" : __DIR__"shulin4",
                    ]));

       setup(); 
       replace_program(ROOM);
}


