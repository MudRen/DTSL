
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�ʹ�����"NOR);
  set ("long", @LONG
������ǻʹ��Ĵ��ţ�Ҳ�������š������Ļʵ۶���ס�������
��վ�ż����ٱ������������������ǡ�
LONG);

  set("exits", ([ 
  
  "north":__DIR__"guangchang2",
  "south":__DIR__"xiangwangjie2",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":2,
	  __DIR__"npc/duguce":1,
	  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query("shili")!="dugu"&&dir=="north"&&objectp(present("bing",environment(me)))&&!wizhood(me))
		return notify_fail("�ٱ���ס���㣬����˵�����ǻʼ���ʿ��������!\n");
	return ::valid_leave(me,dir);
}

