
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

  "west":__DIR__"qiuling2",
  "northeast":__DIR__"qiuling6",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

