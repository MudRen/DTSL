
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Թ�");
  set ("long", @LONG
������һ���Թ�����·���۸��ӣ����ҹ��߲��㣬�ǳ�������·��
������һЩ�к�ʬ�ǣ��������������Թ��е������µġ�
LONG);

  set("exits", ([ 
 "out":"/d/job/cisha/chunzailou", 
        ]));  
  set("valid_startroom", 1);
  setup();
 
}

