
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����԰");
  set ("long", @LONG
������һƬ԰��ʽ��סլ������ģ��󣬷������أ����ҷ羰������
���ﻨ�㡣����Ľ������ھ���Ľ�������Ҹ���������ɣ����ڷ�
�����ַ��������ϳ�κ���ϱ������ŷ硣�ԴӶ����ŷ�Ͷ����Ԩ����
Ԩ�Ͱ���Ƭסլ�ʹ͸���������Ϊ���ڡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"xishidongkou2",
         ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
