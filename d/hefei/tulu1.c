
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·����������˺��٣���ʱ�����������������Գ۹���
ż������һ�����Ұ�޽�����ͷ����һЩ��֪����С����������ȥ������
�����ܲ����ʻ��̲��������֣�����ɽ���ﴵ����������磬����������
��������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 

  "east":__DIR__"wguanlu2",
  "west":__DIR__"tulu2",
  "south":__DIR__"xiaoqiao",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

