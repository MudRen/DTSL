
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ɵĳ������м���������������æµ�ţ�һ���������
�õĲ˷ŵ��������ϡ������Ϸ��˺ܶྫ���Ĳ��ȣ��м�������������
�����̻��ʣ��㲻����Щ���ˡ�
LONG);
  set("exits",([
	  "west":__DIR__"xiaolu",
	  ]));
  set("objects",([
	  __DIR__"obj/food1":2,
	  __DIR__"obj/food2":2,
	  __DIR__"obj/food3":2,
	  "/d/clone/npc/chuzi":1,
	  ]));

  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

