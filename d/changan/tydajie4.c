
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���������򱱣����ܵ������ı������ˡ�
�������ǻʳǵ������š�
LONG);

  set("exits", ([
 "north":__DIR__"beidamen",
 "south":"/d/cahc/waixuanmen",
 "east":__DIR__"tydajie5",
 "west":__DIR__"tydajie3",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

