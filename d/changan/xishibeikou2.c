
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���б���");
  set ("long", @LONG
�������λ�ڹ�������ϵ��������������У������еı��ڣ�ʮ��
·�����ϣ������ߵ����ַǷ������С�������һ�����ӵ���Ժ��һ����
ɮ���̾�����������һ���������Ľ������໥���ӣ��Ե�ʮ�ֹ��졣
LONG);

  set("exits", ([ 
 "north":__DIR__"wulousi",
 "south":__DIR__"xishidongjie1",
 "west":__DIR__"xishibeikou1",
 "eastup":__DIR__"gmqiao",
        ]));
  set("objects",([
         __DIR__"npc/xiaojie":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

