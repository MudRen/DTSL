
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�����Թ�");
  set ("long", @LONG
������һ�������Թ�����������·��ͨ�˴�ǳ�������·��
���ܵ�ǽ���Ͽ��������ֵ�ͼ��������ڶ����ģ����ֲ�����
ָ���㲻��С��������
LONG);

  set("exits", ([ 
 "out":__DIR__"door",
        ]));
  set("no_quit",1);
 
  setup();
 
}

#include "room.c"