
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ǻʹ��ı����������ţ�Ҳ�ǻʹ�������Ҫ�Ĵ��ţ�������ȥ��
�������컧�������������Ŷ�����ͭ�ߣ������������֮״��Ρ��׳
������ҫ��Ŀ��������ʿ�¼�����������Ѳ�ӡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"qingshilu2",
 "south":__DIR__"yuhuayuan",
        ]));
  set("objects",([
          "/d/cahc/npc/changhe":1,
          "/d/changan/npc/bing":4,
          ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

