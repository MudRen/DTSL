
inherit ROOM;
 void create()
{
       set("short", "�ȴ�����");
       set("long", @LONG
����һƬ�ȴ����֡�������ľ�ڵ�ס�����⣬�������Щ�����ˡ�
���ֱ���С�����ֵĶ������ޡ�
LONG);
       set("exits", ([
               "northeast" : __DIR__"shalu2",
               "south" : __DIR__"shulin2",
                    ]));

       setup(); 
       replace_program(ROOM);
}


