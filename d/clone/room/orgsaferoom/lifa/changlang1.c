
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȣ����߻���һЩ������ɽˮ������������߸�Ӣ��
����ϰ���պ���Ϣ�ĵط���������һ�����䳡���ϱ���һ����������ʱ
����߸����Ӵ������߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"baihutang",
 "northeast":__DIR__"lianwuchang",
 "southwest":__DIR__"chufang",
 "eastdown":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
 
  setup();
 
}
