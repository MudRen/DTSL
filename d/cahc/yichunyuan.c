
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�˴�Ժ");
  set ("long", @LONG
������̫����ɽӴ�һ����͵ĵط����������ţ����¼��ѣ���
�����˹��������أ�ˮ�⳺�١�����ɸ������Ի������У�һ�����ſ�
����������������һ���Ǻ࣬ͨ��Ժ�š�
LONG);

  set("exits", ([ 
 "west":__DIR__"xiandemen",
         ]));
  set("valid_startroom", 1);
  setup();
 
}

