
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Է�");
  set ("long", @long
������Ѱ������֮ʿ���֮���ˣ���������ÿ���˶����������
ҹ�ģ�ҲҪ����Щ��˵��Ĳųɡ�
long);

  set("exits", ([ 
 "west":__DIR__"2chuancang4",
 
        ]));
  set("objects",([
  	"/d/clone/npc/jinv":1,
  ]));
  set("sleep_room",1); 
  set("no_fight",1);
  set("valid_startroom", 1);
  setup();
 
}
