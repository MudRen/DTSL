
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ��");
  set ("long", @LONG
�����ǻʳǵ��ϴ��ţ���ʮ���ɣ�ƽ����Ρ�����Ϊ��ɫ����ʯ��
��������̨���Ŷ��������Ͻ���¥����ǰ��ʮ�ಽ�н���һ����Ҳ����
ɫ��ʯ����Ϸ������ֲ����������ڣ�������ʿ����Ӱ���ڴ�����
�ζ����˽�����Ի����¥���� 
LONG);

  set("exits", ([ 
 "north":__DIR__"tianjie1",
 "south":"/d/changan/guangchang",
 "west":__DIR__"hanguangmen",
 "east":__DIR__"anshangmen",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":4,
	  ]));

  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

