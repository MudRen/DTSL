
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵ�����֡������Ѿ������֣��������������ﲻ����
�ϱ������ݵİ����£�����Ϳ�������������о����������кܶ��˵�
����ȥ����ݷ�,�����ڽ���ս��,���԰ݷ����Ҳû����ǰ���ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie2",
 "south":__DIR__"baimasi",
 "west":__DIR__"ximen",
 "north":"/d/job/timejob/guandimiao",
        ]));
  set("objects",([
   __DIR__"npc/xiangke":2,
   ]));
   
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

