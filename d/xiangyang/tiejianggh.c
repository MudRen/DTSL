#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������ǵĹ��ᣬ���������Ĵ�С���鶼�����ﴦ���������
���ָ���Ĵ����þߣ�һ����������ָ��������ѧͽʹ����Щ��������
����һ��ͨ�����������ȡ�
LONG);

  set("exits", ([ 
 "out":__DIR__"bingqipu",
 "east":__DIR__"gongchang",
       ]));
  set("objects",([
	  "/d/job/tiejiangjob/tiejiang1":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

