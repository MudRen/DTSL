
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��¥");
  set ("long", @LONG
�����Ƕ���ɽ��һ����¥���˸�λ��ţ�����£����а�����������
������������֮ˮ�������������¡�
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"jingxinan",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

