
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬����
�Ľ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�ͷ������������
�ȣ����������������õ��������졣
LONG);

  set("exits", ([ 

  "east":__DIR__"xishixikou1",

         ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

