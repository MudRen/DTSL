
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·�����������ɽ�ˣ�������Ƕ���������������ľï
ʢ��Զ�������ķ羰ӳ���������������ܴ����ܲ����ʻ��̲��������֣�
��ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "west":"/d/luoyang/tulu2",
 "northeast":__DIR__"shanlu2",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

