
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ƽ��"NOR);
  set ("long", @LONG
�����������ʹ������ƽ���ˡ�������Ȼ�������������Ҳ��
��˵�����ûʡ����ܰ�����������棬����������һ���������ա�ƽ
ʱ�ʵۺ�����������������ԵñȽ��徻������������������ˡ�
LONG);

  set("exits", ([
  "north":__DIR__"guanhuayuan",
  "east":__DIR__"zijindian",
  "west":__DIR__"westdoor",
         ]));
  set("objects",([
      __DIR__"npc/dugufeng":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

