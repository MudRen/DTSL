
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
���������������ʯ��·����·�����ɾ�������������·�汻��
ˮ��ù����羵����·�������Ų���Ĺ�ľ���������ϵ�С��ʱ����ʱ
��������������ﵽ����ɢ���Ű������������ա����������Ƕ�����
���ţ���������Ҵͥ���ĺ��š�
LONG);

  set("exits", ([ 
 "north":__DIR__"xineiyuan",
 "south":__DIR__"xuanwumen",
 "west":__DIR__"qingshilu1",
 "east":__DIR__"qingshilu3",
        ]));
 

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

