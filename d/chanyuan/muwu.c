
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ľ��");
  set ("long", @LONG
�����Ǿ�����Ժ��һ��Сľ�ݣ��ǻ��ɮ�˵�ס���������������
����ɮ��ҪЩ����ȶ���������Ҫ��Щ���Ǯ������İ������أ���
�ܶ��������������������
LONG);

  set("exits", ([ 
	  "southdown":__DIR__"shilu2",	
         ]));
  set("objects",([
    __DIR__"npc/huikeseng":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}

