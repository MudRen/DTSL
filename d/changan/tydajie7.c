
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ�������ɴ�֡�
LONG);

  set("exits", ([
  "south":__DIR__"wxdajie3",
 "east":__DIR__"tydajie8",
 "west":__DIR__"tydajie6",
        ]));
  set("objects",([
   __DIR__"npc/dipi":1,
   __DIR__"npc/liumang":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

