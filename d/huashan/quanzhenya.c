
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ȫ����");
  set ("long", @LONG
ȫ���£�����ʮ�ɣ���������״����������ϲ����죬�²��ŵأ�
������ȴ����š�ȫ���¡��������֣�ÿ���ֽ�Ϊ���״�С�����Ӹվ���
�̹�������ÿ�־����Գ�ɫ����֮���ƷǷ���������ն�ĵ��������£�
�Ŵ���ʯ����ƾ��ʲô������ʲô�취���ֿ���ȥ�ģ���ֱ�����������š�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
