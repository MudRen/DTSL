
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʶ�");
  set ("long",@LONG
������̩ɽ����ʶ����˴�����̩ɽ������������һ����۹ۣ���
ǰΪ�ŵǷ�̨�������ʵ۷�������ʽ������������С�̨����һ���ֱ���
��˵�Ǻ�������.��Զ����һʯ�٣����顸����С���´�����
LONG);

  set("exits", ([ 

 "westdown":__DIR__"bixiaci",
// "west":"/d/clone/biwutai/meeting_room",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

