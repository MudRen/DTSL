
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
���ڻ�ɽ֮�У���ͷ��ȥ����ɽ��ɽ���������ƣ�Զ������Ů���
��ң����ߡ����ﲻʱ�������߹������Ż�ɽ��������ɫ�޲����ڡ���
ɽ�Թž���������ɽ֮һ�������йػ�ɽ����Ҳ�Ǻܶ࣬��˵�ڻ�ɽ
���кܶ�����������ʥ�ˡ�
LONG);

  set("exits", ([ 
 "southup":__DIR__"yuquanyuan",
            "northwest":"/d/taiyuan/road8a",
       ]));
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));
  set("no_select",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
