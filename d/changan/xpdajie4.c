
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
���ϴ�֡�
LONG);

  set("exits", ([
 "north":__DIR__"asdajie1",
 "east":__DIR__"xpdajie5",
 "west":__DIR__"zqdajie1",
        ]));
  set("objects",([
   __DIR__"npc/xiaofan":1,
   __DIR__"npc/bing":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

