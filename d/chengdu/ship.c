
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
����һ�ұ��ۡ������ǹ����������˻��Ĵ��Ŵ�ͷ���ҹ��ڳ�����
���Ŷ档
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

