
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������̩ɽ�������š��������̩ɽ������ڴ��������︽��ɽ�£�
Ⱥɽ�����أ����������ƣ���ؿ������޿���״��
LONG);

  set("exits", ([ 

 "eastdown":__DIR__"bixiaci",
 "enter":"/d/job/haishajob/shandong1",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

