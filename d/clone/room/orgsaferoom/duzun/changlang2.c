
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȣ����߻���һЩ������ɽˮ����һ�����ǳ�������
�ֱʡ�����ǳ����������߹���Ѿ�ߵĶ��ǳ�С�ġ�������һ�����ң�
�Ƕ��𱤵�������Ϣ��˯���ĵط���
LONG);

  set("exits", ([ 
 "southeast":__DIR__"changlang1",
 "enter":__DIR__"woshi",
 "west":__DIR__"lingwuroom"
      ]));
  set("valid_startroom", 1);
  set("outdoors","duzunbao");
  setup();
 
}
