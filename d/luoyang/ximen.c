
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�������������š��Ա߻����������š�����վ�ż����ٱ����ڼ��
�������İ��ա���Ⱥ�����Ե�ʱ�������������������С��������
����������Ӵ�������Ͷ��������Ҳ���١�
LONG);

  set("exits", ([ 
  

  "east":__DIR__"luoshenjie1",
  "north":__DIR__"xibianmen1",
  "southup":__DIR__"xichenglou",
  "west":"/d/changan/lguanlu2",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

