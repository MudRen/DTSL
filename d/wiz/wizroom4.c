//baimo by 2001/9/24

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIW"��ʦ�Ӵ���"NOR);
  set ("long", @LONG
��������ʦ�Ӵ���ҵĵط���������һ�����԰壬��������Ҷ�
skills �����
LONG);

  set("exits", ([ 
 "east":"/d/yangzhou/xiaolou",
         ]));
  
    setup();
  call_other("/obj/board/skill_b", "???"); 
  
}


