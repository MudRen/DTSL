
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
������ǻ�ɽ������壬Ҳ��������߷壬����������ǡ���ɽԪ
�ס��������Ϸ�������ٸ������ߣ��Ƕ���ժ����Ŀ���ӣ�����Ⱥɽ
������Բ�çç���ƺ�μˮ��˿���ƣ�ĮĮƽԭ�粯���࣬�����۵ס�
ʹ���������Ի�ɽ�߾���ΰ�Ĳ������ƣ�����������硢���ĸ��Ƶ���
����Ȥ��
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yangtianchi",
        ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
