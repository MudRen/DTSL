
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

  "south":__DIR__"qiuling3",
  "northeast":__DIR__"xiaolu2",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

