
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ů��");
  set ("long", @long
��Ů������ˮ���Եľ�ɫ���ǲ�ͬ�����ּ�ɽ��ʯ������䣬����
�о������ɾ��������˸�̾�����ݳ޲б���
long);

  set("exits", ([ 
  
  "north":__DIR__"matou2",
  "west":__DIR__"tianjie3",
  "east":__DIR__"shennvdi2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

