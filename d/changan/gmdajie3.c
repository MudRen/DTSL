
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
�����ڹ�������ϣ�������ֺ�᳤���Ƕ��������������ţ�����
����ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ������
���֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"qydajie4",
 "south":__DIR__"qydajie3",
 "east":__DIR__"gmdajie2",
 "west":__DIR__"gmdajie4",
        ]));
  /*set("objects", ([
		
		"/d/clone/vocation/v_yaoshi1":1,
	]));
	*/
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

