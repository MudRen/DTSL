
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"������"NOR);
  set ("long", @long
���������������Ĵ�����֮һ��������ƾ��ɱ��£��������һ��
���������οʹ��һ����
long);

  set("exits", ([ 
  

  "north":__DIR__"xiangwangjie2",
  "southup":__DIR__"kaiheqiao2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

