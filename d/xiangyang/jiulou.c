
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ӣ�۾�¥");
  set ("long", @LONG
�������������������ľ�¥����˵Ӣ�ۺú�·����������Ҫ������
�ȵ�ơ�ֻ�������������������Ʊ���յ���Ѿ��ȵ���Щ���������ˡ�
��С�����������к��Ž����Ŀ��ˣ��ϰ��ڹ�̨�������ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie2",
        ]));
 set("objects",([
	 __DIR__"npc/chen":1,
__DIR__"npc/xiaoer4":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

