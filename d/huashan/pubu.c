
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"�ٲ�"NOR);
  set ("long", @LONG
������һ�ٲ����ٲ����϶������������������ɸߣ�����ĺ�����
������������Щ���顣ˮ���ɽ������������Щʪ�ˡ��㲻���뵽��
վ���ٲ�����ĸо�����ʲô���ӣ�
LONG);

  set("exits", ([ 
 "west":__DIR__"liandanlu",
 "enter":__DIR__"shui",
      ]));
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
