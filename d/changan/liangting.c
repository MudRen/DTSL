
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","С��ͤ");
  set ("long", @LONG
����������ͤ�����ο���Ϣ֮�á���վ����ͤ���棬�ųǳ�������
�۵ף���̧Ŀ��ȥ��ȴ������ɽ�ϵ���ľ�����дС�������һ�����ͷ�
�����ѵĳ�����
LONG);

  set("exits", ([ 
 "east":__DIR__"shanyao",
         ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
