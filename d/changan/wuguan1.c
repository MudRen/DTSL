
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ݴ�Ժ");
  set ("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ����
��ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�������
������̨�׾�����ݴ�����
LONG);

  set("exits", ([ 
 "west":__DIR__"wuguan",
 "northup":__DIR__"wuguan2",
        ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
set("valid_startroom", 1);
  setup();
 
}

