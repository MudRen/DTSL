
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�ұ��ۡ������ǹ�����������ˮ�Ĵ��Ŵ����ҹ����ڳ�
���ذ��Ŷ�.
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

