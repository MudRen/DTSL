
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�͹���");
  set ("long", @LONG
���Ǻ͹��֣��ϱ����ӳ����ǵĹ⻯�źͺ�ƽ�������ﲻ����ô��
�����ˣ�����ʮ�����֣���������������Ϣ��������һ��ҩ�꣬�����ǳ�
�������ľ�¥--����¥��
LONG);

  set("exits", ([ 
 "north":__DIR__"hgdajie3",
 "south":__DIR__"gmdajie7",
 "east":__DIR__"changanlou",
 "west":__DIR__"huichuntang",
       ]));
  set("objects",([
         __DIR__"npc/haoke":1,
         __DIR__"npc/baixing":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

