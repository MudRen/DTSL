
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��վ");
  set ("long", @LONG
�������ṩ������ƥ��������ƥ����ĵط��������ǹ�����������
�ο����ã���������˹ٸ����õ���Ϣ��վ��
LONG);

  set("exits", ([ 
      "east":__DIR__"changxiajie2",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

