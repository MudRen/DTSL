
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"������"NOR);
  set ("long", @long
����������һ�������ţ������������մ���ʦ³���ӵ���ơ���¥
���ȴ��ʹ�ֻ����ʱ������ɴ��зֿ�������ͨ�������˾�̾���ѡ�
long);

  set("exits", ([ 
  

  "northdown":__DIR__"kaiheqiao1",
  "southdown":__DIR__"kaiheqiao3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

