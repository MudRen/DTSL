
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"����"NOR);
  set ("long", @LONG
�����������ɵ�������������ɵĽ���ƽʱ�������ﴦ����е�
���������һ�Ŵ����ӣ����߷���һ�����ӣ������ǽ�ϻ���һ����
��Ļ�棬��������ҫ�¹����ޱȡ�����һ��ׯ�ϵ����գ�ÿ������
�����������Ҳ���ҳ�һ����
LONG);
  set("exits",([
	  "south":__DIR__"qingshilu2",
	  "north":__DIR__"houdian",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

