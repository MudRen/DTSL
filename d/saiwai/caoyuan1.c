// Room in ��Ҷ

#include <room.h>
#include <ansi.h>


inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "westdown" : __DIR__"caoyuan2",            
            "east" : __DIR__"caoyuan1",
        ]));
        set("objects",([
          "/d/tujue/tree":1,
          ]));
        set("outdoors", "saiwai");
        setup();
        replace_program(ROOM);
}
