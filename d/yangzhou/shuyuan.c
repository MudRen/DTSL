
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ժ");
  set ("long", @LONG
���������ݳǵ���������Ժ����Ժ���������Ϸ��Ӹ������˾�����
��ʦ������ѧ�������ݸ��ǳ�������˵���ĵ������кܶ඼���˴�١�
ֻ�����ﲢ�ŷ����������ӣ����Ϸ�����ǰ�������鱾������ʶ�����
���ѧ��Ҳ����ظ������ʶ������ʵĶ�����������ѧ�á�
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie2",
//"north":"/d/quest/csj/tianjing",
       ]));
  set("objects",([
	  __DIR__"npc/bai":1,
	  __DIR__"npc/boy2":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

