
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","���ĸ�");
  set ("long", @LONG
������һƬ԰��ʽ��סլ������ģ��󣬷������أ����ҷ羰������
���ﻨ�㡣����Ľ������ھ���Ľ�������Ҹ���������ɣ����ڷ�
�����ַ��������ϳ�κ���ϱ������ŷ硣�Դ������ŷ�Ͷ����Ԩ����
Ԩ�Ͱ���Ƭסլ�ʹ͸���������Ϊ���ڡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"asdajie5",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
