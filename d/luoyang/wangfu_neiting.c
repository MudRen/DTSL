
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��������"NOR);
  set ("long", @LONG
������������������������ǰ���һ��������ϸ���Ͽ���֪������
�ҵĴ����������������м��������ػ������Ŀ�����ϡ��м���Ѿ��
��������������Ρ�ƽʱ��������������ġ�
LONG);

  set("exits", ([ 

  "out":__DIR__"wangfu",
  "east":__DIR__"zoulang1",
  "west":__DIR__"zoulang2",
       ]));
  
  set("objects",([
	  __DIR__"npc/shiwei":2,
"/d/job/yangkilljob/yanggong-qing":1,
	  ]));
 set("no_fight",1); set("no_exert",1);
  
  set("valid_startroom", 1);
  setup();
 
}

/*int valid_leave(object me,string dir)
{
	if(objectp(present("shi wei",environment(me)))&&dir=="east"&&!wizardp(me))
		return notify_fail("��������:�����������˵�����,����������!\n");
	return ::valid_leave(me,dir);
}*/
