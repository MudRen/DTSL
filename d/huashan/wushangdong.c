
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���϶�");
  set ("long", @LONG
�˴�Ϊ��ɽ�����϶���Խ�������룬�����Ʒ�������ϵ�ͨ���ţ�
��ɵ����������������Ե���ɽ�з壬��������Ů�塣�ӡ���Ů��
����С�����пɵ����塣
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"jinsuoguan",
 "westup":__DIR__"lianhuaping",
 "southeast":__DIR__"xianzhangya",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
