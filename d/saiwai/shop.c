// shop.c ��ԭ��

inherit ROOM;

void create()
{
        set("short", "��ԭ��");
        set("long", @LONG
���ǲ�ԭ�е�һ�����У�����Ҳ�ǲ�ԭ�и�������ļ�ɢ�أ�ֻ
�ʻ���ĺû������ʻ������Դ����Ȼ˵�Ǹ����ж����ɿ��̵�������
��ɡ�
LONG);
        set("exits", ([            
						"southwest":"/d/dingxiang/dongmen",
            "east" : __DIR__"room1",
            "northwest" : __DIR__"room2",
            "southeast" : __DIR__"caoyuan3",
            "north": "/d/clone/room/cityroom/saiwai"
        ]));        
          set("objects",([
          __DIR__"npc/shang":1,
          "/d/tujue/ji":3,
          ]));

        set("outdoors", "saiwai");
        
        setup();
        replace_program(ROOM);
}
