
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǿ�����Ժ�ı����⡣������ż��Ѹֵ����������Ա߻���һ
�������ڴ�ĥ�ű������Աߵ�ǽ�ϻ�����һ�Ű�ֽ������д�š��ȱ�Ϊ������
LONG);

  set("exits", ([ 
	  "east":__DIR__"caodi1",

         ]));
 set("objects",([
	 __DIR__"obj/staff":2,
	 //__DIR__"obj/blade":2,
	 ]));
  
  set("valid_startroom", 1);
  setup();
 
}

