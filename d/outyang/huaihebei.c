
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huaihebei"
#define TO __DIR__"huaihenan"
#include "/std/shiproom.c"
int do_yell(string arg);
void create ()
{
  set ("short","���ӱ���");
  set ("long", @LONG
�����ǻ��ӵı�����ֻ��һҶ���������������ˡ������˱Ƚ��٣�
ֻ���ҹ������������е����š�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaolu1",
         ]));
set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

