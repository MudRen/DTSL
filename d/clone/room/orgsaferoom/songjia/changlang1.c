
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȣ����߻���һЩ������ɽˮ�����������μұ�Ӣ��
����ϰ���պ���Ϣ�ĵط���������һ�����䳡���ϱ���һ����������ʱ
���μұ����Ӵ������߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"xuandaotang",
 "northdown":__DIR__"lianwuchang",
 "southeast":__DIR__"chufang",
 "northeast":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
 
  setup();
 
}
