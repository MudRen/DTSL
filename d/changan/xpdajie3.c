
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
������֡��������ߣ����ǰ������ˡ�
LONG);

  set("exits", ([
 "north":__DIR__"ahdajie1",
 "south":__DIR__"anhuamen",
 "east":__DIR__"zqdajie1",
 "west":__DIR__"xpdajie2",
        ]));
  set("objects",([
   __DIR__"npc/yahuan":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

