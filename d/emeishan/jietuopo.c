
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���
������Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����á�
LONG);

  set("exits", ([ 
 "eastup":__DIR__"guanyintang",
 "west":__DIR__"shiqiao",
 "southdown":__DIR__"shanlu3",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

