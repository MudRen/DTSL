
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�ٵ�");
  set ("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С���������Ǻ��ݳ�
�ˡ����ѿ���һƬ����ɫ���������Ǻ��ݷ���
LONG);

  set("exits", ([ 
  "west":__DIR__"dongmen",
  "east":__DIR__"guandao2",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

