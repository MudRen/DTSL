
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangbei"
#define TO __DIR__"matou"
#include "/std/shiproom.c";
void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ı��������˳��������ǽ����ľ����ˡ��������˺ܶ࣬
���ǳ˴����ÿͺ������������̷������������������ڶ���Զ�����м���
��ʻ�˹��������˳������Ϳ��Ե��Ž��ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaolu1",
  "northwest":__DIR__"caocong1",
  "north":"/d/hefei/caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

