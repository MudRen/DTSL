
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������ɽ���㣬Ϫ�����ȣ���ľ��ï���������š�Ȫ�Ժ�ɽ��ʯӢ
��������������һС�����У���䣴����������µ���Ȫ֮�ơ��û���
Ȫ�������裬������Ƣ����Ϊ����˫����
LONG);

  set("exits", ([ 
  "north":__DIR__"hupan",
  "southwest":__DIR__"nanan2",
  "northeast":__DIR__"yhs",
        ]));
   set("objects",([
       __DIR__"npc/daoke":1,
       ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

