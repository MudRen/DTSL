
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������С����ﾭ�������˸���������̾������ָ�����ֻ��
������Ʀ�������������ڽ������Ǯ�����Ǵ�������ؽ����������м�
���˾ۼ���һ�������������ʲô�����ǻ�̧��ͷ���㼸�ۡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie1",
 "northeast":__DIR__"xiaoxiang2",
        ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));
   set("outdoors","xiangyang");
set("valid_startroom", 1);
  setup();
 
}

