
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangnan"
#define TO __DIR__"jiangbei"
#include "/std/shiproom.c";
void create ()
{
  set ("short","�����ϰ�");
  set ("long", @LONG
�����ǳ������ϰ������˳������͵��˺����ľ����ˡ���ǰ��ˮ��
����ֻ��һҶ���۰ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"tulu5",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

