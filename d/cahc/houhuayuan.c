
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�㻺�����ɽ��ȥ����ɽҲ�����ߣ�������ľ�д䣬���������̱�
����û��֦Ҷ֮�䡣����̤��ݣ������Ų�Ҳ��������Ϣ������ɽ����
ת�������䣬һ����磬����ȫ�ǻ��㡣������ȥ�����¾��Ǻ�ɫ����
ɫ����ɫ��õ�塣
LONG);

  set("exits", ([ 
 "northwest":__DIR__"tianjing",
 "south":__DIR__"huiketing",
 "northeast":__DIR__"lianwuting",
 "east":__DIR__"jiashan",
        ]));
  
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

