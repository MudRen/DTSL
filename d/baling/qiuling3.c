
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

  "southwest":__DIR__"qiuling2",
  "north":__DIR__"qiuling4",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

