
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·������羰������ɽˮ�续���������¡������кܶ�
Ư����Ұ�����ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ����������������һ
Ƭ�������Ĵ���ȥһƬƽ̹��������˺��٣�ֻ��ż�������������ܹ�
ȥ��
LONG);

  set("exits", ([ 

  "southwest":__DIR__"tulu1",
 "north":__DIR__"huanghe_dukou1",
 "east":"/d/mangshan/shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

