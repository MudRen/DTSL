
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ƽ��"NOR);
  set ("long", @LONG
�����������ʹ������Ű�ƽ�š��м���������������أ�Ѱ������
�ǲ��ܽ���ġ������������������飬���ǲμ����϶��Ǵ������
ȥ������Ľ䱸ɭ�ϣ��ٱ���������ش��������������ˡ�
LONG);

  set("exits", ([ 
  "east":__DIR__"xidian",
  "southwest":__DIR__"qingshilu1",
  "southup":__DIR__"xichenglou2",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":2,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query("kingdom")&&dir=="east"&&objectp(present("bing",environment(me)))&&!wizhood(me))
		return notify_fail("�ٱ���ס���㣬����˵�����ǻʼ���ʿ��������!\n");
	return ::valid_leave(me,dir);
}