
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȣ����߻���һЩ������ɽˮ���������Ƕ���Ӣ��
����ϰ���պ���Ϣ�ĵط���������һ�����䳡���ϱ���һ����������ʱ
�ж��𱤵��Ӵ������߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"duzuntang",
 "northdown":__DIR__"lianwuchang",
 "southdown":__DIR__"chufang",
 "northwest":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
 
  setup();
 
}
