
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",MAG"������Ժ����"NOR);
  set ("long", @LONG
������Ǿ�����Ժ���ſ��ˣ�����������ڳ����������з𾭵���
�����������ſ��и�ɮ�����к��Ž��������ˡ�������Ժ����������
����ƽʱ���������Ҳ�Ǻܶࡣ
LONG);

  set("exits", ([ 
	  "enter":__DIR__"shilu1",
	  "west":"/d/luoyang/xiaolu4",
  
         ]));
  set("objects",([
	  __DIR__"npc/heshang":1,
	  ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
   "/obj/board/party_cy_b.c"->foo();
 
}

