
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵ�����֡����治Զ���������ݵ������ˡ���������
�ݵ��ܹܸ����ſ��м����ٱ��������������������ע������������
�ˡ�������һ������������С�Ե꣬���洫���������������������죬
������Щ���ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie3",
 "west":__DIR__"xidajie1",
 "north":__DIR__"zongguanfu",
 "south":__DIR__"xiaochidian",
"northwest":"/d/slwg/damen",
        ]));
  set("objects",([
    "/d/clone/npc/chenshoubei":1,
    ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

