
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ů��");
  set ("long", @LONG
�з�Ӷ����������������룬�������ڶ��������һ��С�壬����
���ϴ��ף��������ģ��滨��ݶ಻֪�������˴������У�����䡣��
ͷ�е�������Ů������˵�Ǵ���ʱ���¹�ŮŪ�������֮�أ���˷���
����Ϊ��Ů�塣
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanlu6",
 "northdown":__DIR__"yanggongta",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
