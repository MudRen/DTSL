
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
������һ�����ȡ����߾��ǴȺ���ի�ľ��ĵ��ˡ��������������
�о��������������ǿ��ķ����о������ϱ��ǴȺ���ի�������յ�����
Ժ��
LONG);

  set("exits", ([ 

  "east":__DIR__"jingxindian",
  "north":__DIR__"kuxinfang",
  "northwest":__DIR__"songjingfang",
  "southwest":__DIR__"xiuluoyuan",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

