#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵ������ݡ��������������������У�ֻ��������
һ���͹�̨����̨��վ��һλ���ߣ������������˫Ŀ���·�һ�۾���
�������б����ʵ�ʼ�ֵ��
LONG);

  set("exits", ([
 "out":"/d/yangzhou/guangchang",
        ]));
  set("objects",([
	  __DIR__"paimaishi":1,
	  // "/u/chris/dtangel":1,
	  ]));
  set("no_fight",1);
  set("no_exert",1);
  setup();

}
