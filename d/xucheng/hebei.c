
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"hebei"
#define TO __DIR__"henan"

#include "/std/shiproom.c";

void create ()
{
  set ("short","�ƺӱ���");
  set ("long", @LONG
�����ǻƺӵı�������ǰ�ǹ����Ļƺӣ��㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵��ƺ��ϰ��ˡ�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"dadao7",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}


