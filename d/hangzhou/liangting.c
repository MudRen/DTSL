
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
����������ͤ�����ο���Ϣ֮�á�������������ӭ���������
������һ����������ȥ�����������ķ�⾡���۵ף�ֻ������ɻ���
Ҷ��΢����΢΢�ζ�����ʱ��С�۴��д������Ϸ�Ů���ö��ĸ�������
��������
LONG);

  set("exits", ([ 
"south":"/d/hangzhou/xidajie2",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

