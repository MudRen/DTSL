
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"ͥԺ"NOR);
  set ("long", @LONG
�������Ͼ��۵�ͥԺ������������һ����ͭ�����������ơ�������
���������������£����������ڸ�һ����ɪ���������գ���ʱ����
�������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "out":__DIR__"door",
 "north":__DIR__"dadian",
 "east":__DIR__"fantang",
 "west":__DIR__"jingfang",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

