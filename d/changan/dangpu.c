
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ٴ��Ѻ");
  set ("long", @LONG
��ҵ��̾�˵��ƽҤ����ŷ�������ڳ������ķֺţ�ŷ�����ٿ���
����ң�����һ�����ֺ��ϰ������վ�ڹ�̨�󣬶�����������������
���������顣�м�����վ�����������ԥ�Ƿ��������Ķ�����
LONG);

  set("exits", ([ 
 "west":__DIR__"qydajie4",
        ]));
  set("objects",([
	  __DIR__"npc/tie":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

