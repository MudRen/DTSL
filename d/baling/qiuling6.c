
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ�����ϵ�һƬ����أ����������ƽ�����ɫ����ʯ����
��״��ɳʯ·����������û������֮�У���Ϊ�⸽����ǿ�˳�û����
�˼�����������������
LONG);

  set("exits", ([ 

  "southwest":__DIR__"qiuling5",
  "northeast":__DIR__"shashilu2",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

