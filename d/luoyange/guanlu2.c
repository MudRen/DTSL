
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������Ѿ�Զ�����������������˻��Ǻܶࡣ��˵��
�����ʦ�Ƿ�����������أ����ڷ�����������ƥ�����ϳˣ�����ȥ��
��ƥ���˺ܶࡣ
LONG);

  set("exits", ([ 
  "northwest":__DIR__"guanlu1",
  "east":__DIR__"xiaolu1",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

