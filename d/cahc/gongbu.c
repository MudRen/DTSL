
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǡ�������֮һ�Ĺ�����������ҵĽ��裬ˮ�����ֺ�������ƽ
ʱҲ�������бȽϷ�æ�Ĳ��ţ����������İ�����Ա�ܶࡣ
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie1",
       ]));
  set("valid_startroom", 1);
  setup();
 
}

