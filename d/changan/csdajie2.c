
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǳ�����֣��ϱ����ӳ����ǵĳ��ַ��������������ﲻ����ô
�������ˣ�����ʮ�����֣���������������Ϣ��������һ���ھ֡�
������һ����Ӫ��
LONG);

  set("exits", ([ 
 "north":__DIR__"csdajie3",
 "south":__DIR__"gmdajie1",
 "east":__DIR__"biaoju",
 "west":__DIR__"bingying",
       ]));
  set("objects",([
   __DIR__"npc/xiaofan":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

