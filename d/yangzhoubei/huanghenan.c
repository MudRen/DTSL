
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghenan"
#define TO __DIR__"huanghebei"
#include "/std/shiproom.c"

void create ()
{
  set ("short","�ƺ��ϰ�");
  set ("long", @LONG
�����ǻƺӵ��ϰ�����ǰ�ǹ����Ļƺӣ��㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵��ƺӱ����ˡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"shanlu5",
"west":"/d/pengliang/huanghe3"
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

