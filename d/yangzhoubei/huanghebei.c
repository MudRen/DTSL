
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghebei"
#define TO __DIR__"huanghenan"
#include "/std/shiproom.c"

void create ()
{
  set ("short","�ƺӱ���");
  set ("long", @LONG
�����ǻƺӵı�������ǰ�ǹ����Ļƺӣ��㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵��ƺ��ϰ��ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"caodi3",
   "west":"/d/leshou/road6"
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

