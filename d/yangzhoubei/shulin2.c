
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������Ƭ���֡��������ľ���Ǻ�ïʢ����ϸ�������ƺ��иոձ�
�չ��ĺۼ�����������ոշ�����һ��ս�������߾��ǳ���ɽ�Ľ����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"cbsjiao",
 "west":__DIR__"shanlu10",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

