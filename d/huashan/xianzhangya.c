
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
ÿ�����ʵ��糿����ӡ��Ƴ��ΡȻ���������׳������������
��̾Ϊ��ֹ����ɽ;���ڲ����룬���Ʒ�ȴ�Ҳ�ɽ������ƣ���Ч����
��Զ�ۡ�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"yanggongta",
 "northwest":__DIR__"wushangdong",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
