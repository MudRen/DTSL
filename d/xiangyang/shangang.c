
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������ɽ�ԡ����������ңң�����������ˡ����Ｘ��û��ʲô�ˣ�
һƬ������ɪ�����ա������Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ���
LONG);

  set("exits", ([ 
 "west":__DIR__"shashilu3",
       ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

