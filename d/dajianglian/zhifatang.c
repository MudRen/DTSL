
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIR"ִ����"NOR);
  set ("long", @LONG
�����Ǵ����ֶ��ִ���ã���������һ�����񣬿�������ɫ���࣬
û�а�ֵ�Ц�ݡ������ĵ��ӷ��˴��󣬶���������������
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi",
	     ]));
set("outdoors","dajiang");
/*  set("objects",([
	  "/d/job/banghuijob/dajiang":1,
          ]));*/
  set("valid_startroom", 1);
  setup();
 
}

