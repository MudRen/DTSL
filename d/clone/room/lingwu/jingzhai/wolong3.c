
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƺ");
  set ("long", @LONG
��������������ϵĸ���ƺ��������ƿ�������һƬƽ�ء���ѩ��
�����ϣ�����һ�澵��һ�㡣�����Ǹ��ʵ��ͱڡ�������ȥ����Լ����
�������������������С��ϱ�������ǣ����������Ϊ��Ҫ�ĵط���
LONG);

  set("exits", ([ 
 "southdown":__DIR__"wolong2",
 "east":__DIR__"wolong4",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

