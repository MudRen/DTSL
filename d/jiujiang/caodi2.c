
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء���������˲��ࡣ�������ߣ���Ҫ�����ն����㽭
�ˡ�����羰������ɽˮ�续���������¡���ˮ�ĳ�ʪ��Ϣ�˱Ƕ�����
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shalu1",
  "west":__DIR__"caodi1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

