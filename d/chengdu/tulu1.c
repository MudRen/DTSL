
inherit ROOM;
 void create()
{
       set("short", "��·");
       set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է���
��ȥ�����ܵ��������������ࡣ���ϱ��߾��ǳ����İ����ˡ�
LONG);
       set("exits", ([
               "northeast" : __DIR__"tulu2",
               "south" : __DIR__"caodi1",
                    ]));

       setup(); 
       replace_program(ROOM);
}


