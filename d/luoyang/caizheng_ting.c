
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����ǲ��������������������ĵط���ƽʱֻ�в�����Ա�ſ���
�����﹤��������ľ������ɭ�ϣ�����ƽʱ�ǲ����������˵Ƚ�����
��
LONG);

  set("exits", ([ 

  "west":__DIR__"zoulang1",
      ]));
  set("objects",([
	  __DIR__"npc/zhao":1,
	  ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

