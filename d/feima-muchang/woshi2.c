
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƿ���������ܼ���������ҡ�ƽʱ�������˵�������������
�ı�������������롣ǽ�Ϲ���һ���ֻ����ּ��������Ծ���������ʾ
��һ��Ӣ�ۺ��������ա�
LONG);

  set("exits", ([ 
	  "south":__DIR__"qingshilu6",
    ]));
  set("objects",([
 "/d/job/feima/shangzhen":1,
	  ]));
 set("no_fight",1); set("no_exert",1);

  
  set("valid_startroom", 1);
  setup();
 
}

