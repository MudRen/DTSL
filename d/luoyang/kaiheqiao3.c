
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
  

  "northup":__DIR__"kaiheqiao2",
  "south":__DIR__"shennvdi2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

