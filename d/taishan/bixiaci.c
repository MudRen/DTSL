
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ϼ��");
  set ("long", @LONG
������̩ɽ�ı�ϼ��������Ժ���ж�������ֱ��Ϊ�������⣬
�����Ž���͵ľ�ʩ����������߶����������ɡ����ķ�������̩ɽ��
�����Ů�������ȵ���ϼ����Ȼ��ŵ�����������������
LONG);

  set("exits", ([ 

   "westup":__DIR__"nantianmen",
   "eastup":__DIR__"yuhuangding",
   "eastdown":__DIR__"wusongting",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

