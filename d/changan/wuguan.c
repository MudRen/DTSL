
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ݴ���");
  set ("long", @LONG
������һ����լ�ӣ��ſڸ���һ�����ҡ�������ݡ�����������ʯ
ʨ����Ӵ��ſ��ƽ�ȥ�����������������������ܷ�æ�����ӣ��ſ�վ
�������������������ϡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie3",
 "east":__DIR__"wuguan1",
        ]));
set("valid_startroom", 1);
  setup();
 
}

