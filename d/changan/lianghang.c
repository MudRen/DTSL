
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�귢����");
  set ("long", @LONG
����һ��ר��������ʳ�����У������в��ٵĻ�ƶ���æµ���ϰ�
���ڹ�̨��������������ž���������ˣ����ϲ�ʱ¶�����������΢Ц��
LONG);

  set("exits", ([ 
 "west":__DIR__"xishixijie3",
        ]));
  set("objects",([
         __DIR__"npc/liangdian-boss":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

