
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ʒ�");
  set ("long", @LONG
���Ʒ壬λ�ڻ���嶫�ϣ�ɽ���վ����ݴ�˵����é����������ɫ
�����ڷ嶥�Ͽչۿ���ɽ�˾�������۳�����ɫ�Ʋʳ��֣��������Ʒ塣
�����Ʒ����������ͱڣ��ɼ��ơ���ɫ���Ļ�����ʯ��������ƣ���
���������ơ���Ϊ���������˾�֮һ��
LONG);

  set("exits", ([ 
 "northdown":__DIR__"canglongling",
 "southup":__DIR__"jinsuoguan",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
