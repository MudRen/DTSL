
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����������ϵ�һ��ɽ·���������ľ�����дУ��羰�ǳ�������
����û���˸�������ͣ������˵�������ǿ����û��
LONG);

  set("exits", ([ 
  "northdown":__DIR__"shanlu1",
  "westup":__DIR__"shanlu3",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

