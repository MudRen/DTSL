

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����¹�ģ��󣬷����ǧ����Ժ�������������������ﾡ�Ǹ߸�
ʯ�ڣ���������Ʋ�һ�ᣬ��Ȼ�ֲ�����ʱ�ĵ�·��������һ�����
ʯ���ƺ���������������ٺٶ�Ц��
LONG);

  set("exits", ([ 
 "west":__DIR__"wxdajie2",
 "east":__DIR__"xiaojing",
]));
 
  set("objects",([
          "d/job/jj/heshang3":2,
	   ]));
  set("valid_startroom", 1);
  setup();
 
}
