
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·��������һ����ͤ�����µĿ����˱Ƕ������㲻��
����һ�񡣱�����һ����ͤ���������μұ����˷�����ʱ��������˵�
�μұ����ӳ�������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"qingshilu1",
  "north":__DIR__"liangting2",
  "west":__DIR__"zhangfang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

