
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͷ");
  set ("long", @long
�������к��������ݺᣬ����˵�������ܲ���������ͣ�����ͽ���
Ҳ����Ҫר����ͷ�ſ��ԡ�������Ǿ��������ź�ͣ����ֻ�ĵط���
long);

  set("exits", ([ 
      "south":__DIR__"shennvdi1",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

