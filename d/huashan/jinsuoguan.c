
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����������������塢�Ϸ�����壬����֮����һɽ��С��ء���
����ƺ������֮ˮ����ƺ�У�С�ݵػ�ˮ�����񾮡�ÿ���꼾���񾮵�
ˮ�ڶ�����������������γɷ���ֱ�µ��ٲ�����Ϊ��ɽʤ��֮һ��
LONG);

  set("exits", ([ 
 "northdown":__DIR__"wuyunfeng",
 "westup":__DIR__"wushangdong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
