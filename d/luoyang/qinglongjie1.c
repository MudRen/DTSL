
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����˷�");
  set ("long", @LONG
�����������˷���������һ��С���ݣ�ר��Ϊ��ЩС�̷����ṩһ
Щ���˵�ʳƷ����������������ˮ��������Ϊ������ƽϸߣ���������
��������ʧ��ĵط�����˽���͢��ˮ�������������
LONG);

  set("exits", ([ 
      "east":__DIR__"xiaofanguan",
      "west":__DIR__"shuichesi",
      "north":__DIR__"qinglongjie2",
      "south":__DIR__"luoshenjie2"
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

