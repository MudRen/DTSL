
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ��");
  set ("long", @LONG
����һ����ɫ��ʯ�ţ���Խ���ϱ������������֮�ϣ�����������
�����Ե�ʮ�����֣�����ȥ�����ܵ��ﳤ�����������ֳ����ˡ�
LONG);

  set("exits", ([ 
  "westdown":__DIR__"tydajie1",
  "eastdown":__DIR__"tydajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

