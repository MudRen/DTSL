
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƺ");
  set ("long", @LONG
�����϶�ѭɽ�Ŷ��У�����ɽ��һ�����£�ʯ�ϱ�ˮ��ˢ����๵��
������֮���γɵ��ݵأ�������ͳ������ƺ���ݵ��������ʯ����Ϊ
����ʮ�˸����ж�ʮ����̶�����϶�������������顣ƺ�����������裬
��ɫ���ġ������񾮣�������Ȫ��һ����ˮ���ڻ��ͨ����Ȼһ�壬��ν
�����ɺϡ��񾮸���ԭ������¥��԰����֮��ˮζ�v����
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"wushangdong",
 "southup":__DIR__"cuilinggong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
