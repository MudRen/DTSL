
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�����"NOR);
  set ("long", @LONG
�����������ʹ��Ķ�������š��м���������������أ�Ѱ������
�ǲ��ܽ���ġ������������������飬���ǲμ����϶��Ǵ������
ȥ������Ľ䱸ɭ�ϣ��ٱ���������ش��������������ˡ�
LONG);

  set("exits", ([ 
  "west":__DIR__"dongdian",
  "southeast":__DIR__"qingshilu2",
    "southup":__DIR__"dongchenglou2",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":2,
	  "/d/clone/npc/youchuhong":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query("kingdom")&&dir=="west"&&objectp(present("bing",environment(me)))&&!wizhood(me))
		return notify_fail("�ٱ���ס���㣬����˵�����ǻʼ���ʿ��������!\n");
	return ::valid_leave(me,dir);
}