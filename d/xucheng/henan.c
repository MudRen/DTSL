
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"henan"
#define TO __DIR__"hebei"

#include "/std/shiproom.c";

void create ()
{
  set ("short","�ƺ��ϰ�");
  set ("long", @LONG
�����ǻƺӵ��ϰ�����ǰ�ǹ����Ļƺӣ��㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵��ƺӱ����ˡ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"dadao6",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}


