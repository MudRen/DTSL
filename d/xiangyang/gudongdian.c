
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ŷ���");
  set ("long", @LONG
������һ�ҹŶ��ꡣ���Ǯ�ƽ�ȱ���ƺ�û����Ը���Ǯ�ƻ�����
���������������ⲻ�Ǻܺá����ڹٸ����ܣ���Ȼ�ϰ�ͬ�ٸ�ǩ��
������Լ����ǿ������ϴ���������Ρ���Ȼ�ſڵĽ������ƻ��ڣ���
���������Ѿ�����ȥ¥���ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie3",
        ]));
set("valid_startroom", 1);
  setup();
 
}

