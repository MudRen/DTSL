
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����Ǯׯ");
  set ("long", @LONG
���Ǯׯ��˵��������ԭ��һλ��λ�߹���������ȫ�����ؿ��˲�
�ٷֵꡣ��Ϊҥ�ԣ������й�һ�μ��ҷ糱��Ǯׯһһ�Ҹ�����Ƿ�ֺ���
����������𣬷��е���Ʊͨ��ȫ����
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie1",
        ]));
  set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

