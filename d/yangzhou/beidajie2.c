
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵı���֡����������ݵı����ˡ��ϱ������ݵı���
�У�Ҳ�����������ֵĵط�֮һ�����������������ı��ǹص�������
����Ҳ�ܶ࣬ս��ʱ������˷����ĳ��У�����Ҳֻ�������ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"beimen",
 "southwest":__DIR__"beijishi",
 "west":__DIR__"xiaolou",
        ]));
  
  set("objects",([
       "/d/clone/npc/dugu-sheng":1,
       ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

