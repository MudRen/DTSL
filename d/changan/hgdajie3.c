
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�͹���");
  set ("long", @LONG
���Ǻ͹��֣��ϱ����ӳ����ǵĹ⻯�źͺ�ƽ�������ﲻ����ô��
�����ˣ�����ʮ�����֣���������������Ϣ��������һ�ҷ��̣����濴��
������һ���ĳ���
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie1",
 "south":__DIR__"hgdajie2",
 "east":__DIR__"lequanguan",
 "west":__DIR__"fanpu",
       ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

