
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�������μұ��ĳ�����������ʦ����������ͷ�󺺵�æ�ţ�������
�µķ��˰ڵ��������ϡ��м����μұ��ĵ��������������̻��ʵسԷ���
������������������˿�ˮ��
LONG);

  set("exits", ([ 

  "east":__DIR__"xiaolu",
    ]));
  set("objects",([
	  __DIR__"obj/niurou":3,
	  __DIR__"obj/kaoya":3,
	  "/d/clone/npc/chuzi":1,
	  ]));
set("resource/water",1);
  set("valid_startroom", 1);
 setup();
 
}

