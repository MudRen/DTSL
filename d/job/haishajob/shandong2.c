
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"ɽ��"NOR);
  set ("long", @LONG
������һ��ɽ�����ںڵģ�������������ʲô��·����˵�������
���˺ܶ������ص��ˡ���֪��ǰ�滹��û�������ر�ͼ���ˡ�
LONG);

  set("exits", ([ 
 "enter":__DIR__"shandong3",
 "out":__DIR__"shandong1",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
