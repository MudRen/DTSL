
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ɵĽ���ף���������ҡ����ϵı�������������롣��
�߰ڷ���һ����ױ̨���Ա������ϻ�����һ��û����ɵ��ֻ�����ߵ�
ǽ�Ϲ���һ�ڱ�����������費��ʮ�ֺ��������ǵ��Գ������ס�����
���辮����������������������Ŀ��
LONG);
  set("exits",([
	  "north":__DIR__"changlang",
	  ]));
  set("objects",([
 __DIR__"npc/zhuyu-yan":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

