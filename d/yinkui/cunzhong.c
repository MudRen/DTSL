
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����Ǵ��ӵ����ġ��������Ӳ���һ����Ӱ��վ���������һ�ֿ�
���ĸо��������м���ʬ�����м�ֻͺ���������������׼����ʳ����
��ʬ�������ܶ����ջٻ򵹵��ķ��ݣ�һ�ɻ��������ա�
LONG);

  set("exits",([
	  "east":__DIR__"cundong",
	  "west":__DIR__"cunxi",
	  "south":__DIR__"tiandi",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

