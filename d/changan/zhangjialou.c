
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ż�¥");
  set ("long", @LONG
�ż�¥�ǳ��������ľ�¥����Ȼ�Ȳ���Ծ�����ϵĸ���¥����Ҳ��
�ǳ�����һ�����ľ�¥�ˣ�������ÿ���˶����Ե��������Է��ġ�
LONG);

  set("exits", ([ 
 "west":__DIR__"xishixijie1",
        ]));
 set("objects",([
	 __DIR__"npc/xiaoer5":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

