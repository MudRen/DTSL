
inherit ROOM;
#include <job_money.h>
void create ()
{
  set ("short","�ۿ�");
  set ("long", @LONG
����Ž������ۿڡ������ǾŽ������ۿڡ�����ǳ����֣����ִ�
ֻͣ��������̴����㴬������ˮк��ͨ���Ա߻��кܶ�С��������
���������ڶ���
LONG);

  set("exits", ([ 
      "east":"/d/jiujiang/matou",
      ]));
  set("valid_startroom", 1);
  set("outdoors","jiujiang"); 
  setup();
 
}

