
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�ͷ�"NOR);
  set ("long", @LONG
һ��ļ�Ժ�ڿͷ��ĳ����϶��Ժ�ɫΪ��������Ĳ���ȴ����Ĳ�
������ɫ�����Ǹ���һ����ˬ�ĸо���
LONG);

  set("exits", ([ 
	  "down":__DIR__"xilou",
  ]));
  set("objects",([
  ]));

  set("valid_startroom", 1);
  setup();
 
}
