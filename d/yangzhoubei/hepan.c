
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ��С�ӵĺ��ϣ����ڳ�ʱ���ܵ���ˮ�������Աߵ�ֲ��
�����൱ïʢ����ˮ�峺����ɫ���ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"xiaolu4",
        ]));
  set("objects",([
    __DIR__"npc/yetu":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

