
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ǹ�");
  set ("long", @LONG
����������¥�Ķ�¥�����з���һ��Сľ�������Ϸ��ž���
���ġ��Ա���һ���񴲣��ݶ������촰���򸾶��˳����ڴ��Ͽ�
���������ǣ�����������Ը���򿪴����Ϳ��Կ������ݵ�������
ɫ�����������˼䡣
LONG);

  set("exits", ([ 
 "down":__DIR__"yll",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

