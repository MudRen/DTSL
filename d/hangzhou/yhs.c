
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ɽ");
  set ("long", @LONG
���ɽ��ľ���̣�����ͦ�Σ�ͤ���ڶ࣬�������ƣ�������������
��������Χ��ȫ����ɫ��������͵��˻��ܡ�
LONG);

  set("exits", ([ 
  "southwest":__DIR__"hupao",
        ]));
  set("objects",([
       __DIR__"npc/daoke":2,
       ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

