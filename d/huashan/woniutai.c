
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ţ̨");
  set ("long", @LONG
��ţ̨��ɽ����һ�鲻��ĵط�����ǰ����ɽ������ͱڣ�������
�֣���ԨΣ�ȣ������۵ס���ţ̨�ϵ��Ǹ�����ţʯ�������ǵ����Ͼ�
����ţ����˵��ţ�������繵�󣬿�����ɽ��ɫ׳���������㻯Ϊʯţ��
��Զ�������˻�ɽ֮�ϡ�
LONG);

  set("exits", ([ 
 "westdown":__DIR__"konglingfeng",
 "northup":__DIR__"yuntaifeng",
 "southup":__DIR__"canglongling",
       ]));
  set("objects",([
	  __DIR__"npc/tucaizhu":1,
	  ]));
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
