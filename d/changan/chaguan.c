

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
���跿�ǳ����������Ӿ۵ĳ���������������˵İڷ���һЩľ
�Ƶ����Ρ�һ��˵��������������ϲ����Ľ���ʲô��һЩ���һ��Ʒ
�裬һ�����飬һ�߻�����ɫ��ͷ�Ӷ��������Ҫ����������ƹʺ�ҥ
�ԣ�������׼û��
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie3",
        ]));
  set("objects",([
	  __DIR__"npc/cha":1,
	  ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

