
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ӽε�");
  set ("long", @LONG
�Ӽε��ڽ�ש�̵أ�������������ν��ᱦ�����������Ҽ�Ϊů��
���������ȣ��ϼ�ľ�ʸ����������������®ñ�������ϲ����˼�����
������������ǰ�ܽ�����ȥ������ʹ�ռ���� 
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yuhuayuan",
 "south":__DIR__"ganludian",
        ]));
  /*set("objects",([
	  "/d/changan/npc/liyuanba":1,
	  ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

