
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ���Ǻ�
���֡�
LONG);

  set("exits", ([
 "north":__DIR__"tongxingshe",
 "south":__DIR__"hgdajie3",
 "eastup":__DIR__"tyqiao",
 "west":__DIR__"kaiyuanmen",
        ]));
  set("objects",([
         __DIR__"npc/dipi":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

