
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ھִ�Ժ");
  set ("long", @LONG
��������Զ�ھֵĴ�Ժ��Զ���м�����������ϰ���գ��Ա߻��м�
����ʦ��ָ�����ǡ����ﾭ����������������Ǯ�Ĳ��������ǳ����Ĺ�
�£�������Ҫ���ڵġ�
LONG);

  set("exits", ([ 
 "west":__DIR__"biaoju",
       ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

