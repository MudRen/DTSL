
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ծ����");
  set ("long", @LONG
��ǰ���ʮ���ɵ�������������ϱ�����ǰ��������һ����ΰ�Ĵ�
ʯ�ţ��۾�ˮ��֮�ϣ�����������������ϳ������������Ե��侫��
��ʯ������������Ĵ󹰣�����ʮ���ɣ�������������ŵľ����
�����ĳ����У��ڴ󹰵������ָ�������С������������ˮ���ֿɼ���
�󹰵ĳе����������ϣ��������������ۣ��µ����ͣ����ͳ�ɫ�� 
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishidongjie4",
  "eastdown":__DIR__"xishidongkou2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  __DIR__"npc/youke":1,
	  __DIR__"npc/bing":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

