
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
����һƬ���֡���ľïʢ����ס�����⡣��ʱ���˳�Ⱥ����߹���
��˵���ﾭ���е��˳�û���㲻���ӿ��˽Ų���
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaoxi1",
 "south":__DIR__"caodi2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

