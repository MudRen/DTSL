
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ʻ���");
  set ("long", @LONG
��һ�����������һ��������ֻ���ӷ��������棬ȫ�ǻ���
���硣�ӵ����ǩ�ϵĻ����������󲿷ֶ��ǵĵ��ص������������Ĺ�
��������˽�����æ���Ц�ݵ�ӭ��������
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie5",
        ]));
  set("objects",([
	  __DIR__"npc/guniang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

