// /d/xingxiu/silk10.c

inherit ROOM;

//string do_joke();

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵�����ɳ������һƬ��������������е�
�˳�û������ͨ��һƬ�����ɽ�����������ͨ����ԭ��·��·����һ
��ʯ��(shibei)��
LONG );
       set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk8",
                "west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
        ]));
        
        set("item_desc",([
         "shibei":"����Ľ��գ��˵ؽ���"+this_player()->name()+"������֮�أ�\n\n",
         ]));

        setup();
}
