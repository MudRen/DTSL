
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"���궫��"NOR);
  set ("long", @LONG
�����ǰ���Ķ��š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա߻��м����ٱ�����������ǵİ��գ���һ���ٱ�������
��ָ�ֻ��ţ�һ�����������ӡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"dongjie2",
  "east":__DIR__"xiaolu1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

