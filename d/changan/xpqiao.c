
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ��");
  set ("long", @LONG
����һ����ɫ��ʯ�ţ���Խ���ϱ������������֮�ϣ����������
�����������Գ����������ܾ��Ǿ�լ������վ��������Զ����ȥ����
�����������Ծ���š�
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishinankou2",
  "eastdown":__DIR__"xpdajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

