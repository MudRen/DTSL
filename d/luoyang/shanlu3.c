
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����������ϵ�һ��ɽ·�����ﲻʱ�ؿ��������������޵�������
�㲻���ӿ��˽Ų���
LONG);

  set("exits", ([ 
  "eastdown":__DIR__"shanlu2",
  "southdown":__DIR__"shanlu4",
  "north":__DIR__"songlin",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

