
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"�Ⱥ���ի"NOR);
  set ("long", @LONG
������һ��իԺ����ǰ��ֻ�����Ϻ���һ�顸�Ⱥ���ի�������ҡ�
����ž�����������ԼԼ������իԺ�����о���������ֻ�����ﳬ����
�ף�ׯ�����¡�
LONG);

  set("exits", ([ 

  "enter":__DIR__"suishilu1",
  "southdown":"/d/changbaishan/shanlu5",
       ]));
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
set("outdoors","jingzhai");
  
  set("valid_startroom", 1);
  setup();
  "/obj/board/party_jz_b.c"->foo();
}

int valid_leave(object me,string dir)
{
  if(me->query("gender")=="����"&&
     present("di zi",environment(me))&&
     dir=="enter")
  return notify_fail("����������ס���㣺�Ⱥ���ի��ֹ�������ڣ�\n");
  return ::valid_leave(me,dir);
}
