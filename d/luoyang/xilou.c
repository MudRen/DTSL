
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����Ժ��¥"NOR);
  set ("long", @LONG
����������Ժ����¥����Ҫ���������ֵĿ������޵ĵط�����Ȼ��
��������������Ц���������ﴫ�������������ж��������˽���ЩЦ��
�������ص���������᣿
LONG);

  set("exits", ([ 
	  "east":__DIR__"huayuan",
	  "up":__DIR__"kefang0",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
