
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
��������������ڻʹ���ס�����������������е�����ڶ�����
�����Ϊů����Ϊ��ס�����ң��ŵ������ļ����ϡ����������濻��
��Ϊ����ĳ�����������Ժ���������ɱ������֮�á������ǻʼ�
���ã�������������ţ������¬�֣�װ�ο���������
LONG);

  set("exits", ([ 
 "northdown":__DIR__"tcgc",
 "southdown":__DIR__"chengqingmen",
        ]));
  set("objects",([
	  "/d/changan/npc/lishimin":1,
	  ]));
 
  set("valid_startroom", 1);
  setup();
  "/obj/board/lifa_b.c"->foo();
}

