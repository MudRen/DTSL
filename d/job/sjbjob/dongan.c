
inherit ROOM;
#include <job_money.h>
void create ()
{
  set ("short","��������");
  set ("long", @LONG
�������ݵ������⡣���߾������ݵı����ˡ��ϱ��ǳ�����������
��ˮ����������������������ݵ�������ͷ����������������ɹ�������
LONG);

  set("exits", ([ 
      "west":"/d/hangzhou/jiangbei",
//      "north":"/u/kouzhong/kuangchang",
"enter":"/d/quest/csj/ship",
      ]));
  set("valid_startroom", 1);
  set("outdoors","yangzhou"); 
  setup();
 
}

