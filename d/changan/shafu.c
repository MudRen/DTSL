
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɳ��");
  set ("long", @LONG
������һƬ�����ĸ��ڣ�������������ڻԻͣ����������������
���һʱ�������׸���ɳ�ң���Ϊ���ս�ң�ȫ��Ǩ�ӵ�������Ͷ����
Ԩ��
LONG);

  set("exits", ([ 
 "west":__DIR__"asdajie4",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
