
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","���ϻθ�");
  set ("long", @LONG
������һƬ԰��ʽ��סլ������ģ��󣬷������أ����ҷ羰������
���ﻨ�㡣����Ľ������ھ���Ľ�������Ҹ���������ɣ����ڷ�
�����ַ��������ϳ�κ���ϱ������ŷ硣�Դӻι���Ͷ����Ԩ����Ԩ
�Ͱ���Ƭסլ�ʹ͸���������Ϊ���ڡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"ahdajie4",
         ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
