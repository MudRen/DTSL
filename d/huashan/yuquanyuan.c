
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȪԺ");
  set ("long", @LONG
��ȪԺ������Դ����Ȫ���ഫԺ��ȪˮԭΪɽ����������Ǳ����
��ˮǱ���ų���ţ��ʯ�£�ʼӿ���ر��۶�ΪȪ����΢�о��㡱����
��ȥ���⡱��������Ȫ���˴�Ϊ���ٻ�ɽ�ı���֮·��
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shanlu1",
 "southup":__DIR__"konglingfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
