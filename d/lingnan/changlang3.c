
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǹ����ȡ��������μұ����������ϱ��Ǹ���԰�����ȵ�ǽ��
�Ͽ̻���һЩ�����ıڻ������෱�࣬��ɽˮ������ȡ��������㹤��
��������ʱ��һЩ�μұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"zhengting",
  "south":__DIR__"huayuan1",
       ]));
  set("objects",([
	  "/d/clone/npc/wangzhongxuan":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

