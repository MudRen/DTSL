
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangan2"
#define TO __DIR__"jiangan1"
#include "/std/shiproom.c";
void create ()
{
  set ("short","�����ϰ�");
  set ("long", @LONG
�����ǳ������ϰ������˳������͵����Ĵ��ľ����ˡ���ǰ��ˮ��
����ֻ��һҶ���۰ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"shalu1",
         ]));
set("outdoors","jiang");
  set("valid_startroom", 1);
  setup();
 
}

