
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�ٵ�");
  set ("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο�����������������
���ò����֡���Ҳ���²����ؼ����ں��ݹ��������ķ羰��������һƬ
ïʢ�Ĵ��֣�������Ҷ��ס�����⣬���Ծ������ο���������·������
�㻹�ǲ�Ҫȥ�ĺá�
LONG);

  set("exits", ([ 
  "west":__DIR__"guandao1",
  "east":__DIR__"conglin",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

