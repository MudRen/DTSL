
inherit ROOM;
#include <job_money.h>
void create ()
{
  set ("short","���Ʒ�");
  set ("long", @LONG
���������ɽ�ı��Ʒ塣ԶԶ��ȥ�����Կ�����ɽ�Ĵ��Ʒ壬��˵
�����ɷ����۾ͽ������������������£���ɫ��������һ����ɽ
��ˮ�ĺõط���
LONG);

  set("exits", ([ 
"southdown":"/d/mangshan/shanlu6",
      ]));
  set("valid_startroom", 1);
  set("outdoors","mangshan"); 
  setup();
 
}

