
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������λ�ڻʳ����濿����ƽʱ�����������볯һ�㶼���������
��������������ȸ�ţ���ģ�����ƾ�����һЩ��������Ȼ����ɫ����
ʯ�Ľṹ�����ɫ�Ĵ�ľ�ţ�����ž������Ű�ʮһ�����������ͭñ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tianjie1",
 "southwest":"/d/changan/gmdajie5",
  "east":__DIR__"zhuquemen",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

