
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̴Ϫ");
  set ("long", @LONG
�˴����ǵ�����������Ծ̴Ϫ֮�����Ӵ�֮��ųɾ�����������֮
��֡��˴������վ������滷ɽһ����ˮ��ˮ��ɽ������ν�˼��ɴ���
LONG);

  set("exits", ([ 
 "south":__DIR__"nongtian1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

