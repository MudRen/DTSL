
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��˼��԰");
  set ("long", @LONG
���������ҼҵĻ�԰��ֻ����ɽ������������������������
��ҩ��ĵ����õ�壬�ٺϣ���ֱ���ǻ��ĺ���ֻ������ʵ���
�裬���ϰ��鳪�裬ˮ�������ζ������������˼䡣����������
���������·��������¥��
LONG);

  set("exits", ([ 
 "south":__DIR__"xsl",
 "north":__DIR__"yll",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

