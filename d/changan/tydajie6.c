
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ���������֣�������
�����š�
LONG);

  set("exits", ([
 "north":__DIR__"danfengmen",
 "south":__DIR__"qydajie5",
 "east":__DIR__"tydajie7",
 "west":__DIR__"tydajie5",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

