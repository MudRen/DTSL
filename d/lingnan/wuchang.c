
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�䳡");
  set ("long", @LONG
�������μұ������䳡�������Ӿ���������ϰ���ա�����������
������Ŭ������ϰ�μҵ�����ֻ�������������䳡��ʱ���ɱ�����ڡ�
�������μұ��ı����ң��ϱ����μұ�������Ϣ�ĵط���
LONG);

  set("exits", ([ 

   "west":__DIR__"liangting1",
   "east":__DIR__"bingqishi",
   "south":__DIR__"xiuxishi",
       ]));
  set("objects",([
	  __DIR__"npc/songlu":1,
	  __DIR__"npc/boy":2,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

