
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�쾮");
  set ("long", @LONG
���߽�һ��С�쾮����ʯ����·��·��Χ�����ļ����ݣ���������
����ͨ����Ժ�䣬����һ��СС���쾮�����õ�Ҳ�Ǿ���ϸ�£����
���ġ�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"houhuayuan",
 "southwest":__DIR__"zoulang",
 //"north":"/d/clone/room/cityroom/changan",
 //"east":"/d/clone/room/orgsaferoom/lifa/baihutang",
        ]));
  
set("valid_startroom", 1);
  setup();
 
}

