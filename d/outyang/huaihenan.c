
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huaihenan"
#define TO __DIR__"huaihebei"
#include "/std/shiproom.c"
void create ()
{
  set ("short","�����ϰ�");
  set ("long", @LONG
�����ǻ��ӵ��ϰ���ֻ��һҶ���������������ˡ������˱Ƚ��٣�
ֻ���ҹ������������е����š�
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaolu2",
         ]));
set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

