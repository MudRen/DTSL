
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ�����ĸ��ڣ�������������ڻԻͣ�����ǰ�ļҶ�����
��ɷ��һ����֪���������ڵ����˲���ʲô���ˣ���˵�������ڻ��ϳ�
�������ӵĸ��ף������������书��ǿ����ʲôа�ɵĴ����أ��ѹֻ�
������š�
LONG);

  set("exits", ([ 
 "east":__DIR__"asdajie3",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
