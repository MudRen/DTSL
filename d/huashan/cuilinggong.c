
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���鹬");
  set ("long", @LONG
���鹬Ϊľʯ�ṹ�����¾��ƶ��������������������������λ���
���������������š�����ǰ������������㣬��������������
ǰ�����ͨ��Ϊһ�塣����Ŷ����д��ƹ����ң����ڹ�������֮ĸ
������λ��������̬���϶�ׯ��
LONG);

  set("exits", ([ 
 "northdown":__DIR__"lianhuaping",
 "westup":__DIR__"julingzu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
