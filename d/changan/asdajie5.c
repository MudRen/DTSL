
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ϴ��");
  set ("long", @LONG
���ǰ��ϴ�֣��ϱ����ӳ����ǵ���ƽ�ֺͽ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ��ϱ��ֵ����档����ʮ�����֣���
������������Ϣ�������ǻʳǵ���ϲ�ţ�������һ����լԺ��
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie5",
 "south":__DIR__"asdajie4",
 "east":__DIR__"yuwenfu",
 "west":"/d/cahc/yanximen",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

