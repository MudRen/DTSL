
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ����������֣�������
��ҫ�š�
LONG);

  set("exits", ([
 "north":__DIR__"jingyaomen",
 "south":__DIR__"yadajie3",
 "westup":__DIR__"tyqiao",
 "east":__DIR__"tydajie3",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

