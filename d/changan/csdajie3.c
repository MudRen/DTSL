
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǳ�����֣��ϱ����ӳ����ǵĳ��ַ����������������ʮ����
�֣���������������Ϣ���������򱱣����Ե��ﱱ���һ������������
·����ͨԶ��֡������Ǹ���վ�������м���ݡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie8",
 "south":__DIR__"csdajie2",
 "west":__DIR__"yizhan",
 "east":__DIR__"wuguan",
        ]));
 
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

