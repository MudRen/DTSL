
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ϴ��");
  set ("long", @LONG
���ǰ��ϴ�֣��ϱ����ӳ����ǵ���ƽ�ֺͽ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ��ϱ��ֵ����档����ʮ�����֣���
������������Ϣ�������ǻʳǵľ����ţ�������һ����լԺ��
LONG);

  set("exits", ([ 
 "north":__DIR__"asdajie5",
 "south":__DIR__"gmdajie4",
 "west":"/d/cahc/jingfengmen",
 "east":__DIR__"shafu",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

