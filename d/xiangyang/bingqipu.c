
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һ�ұ����̡�����ս�ң������������Ǻ����ˡ��������
һ������ (pai)�����������������ʼ����ѧͽ����������������Ǻ�
����ֻ������һ������ʾ�����Աߵļ�����������������š����ܵ�¯
���յ�������Щ�����ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie2",
 "enter":__DIR__"tiejianggh",
       ]));
  set("objects",([
      __DIR__"npc/tiejiang":1,
      "/u/kouzhong/walker":1,
	  ]));
  set("item_desc",([
	  "pai":"������������ѧͽ����Ը���߿�������
             ѧͽҲ���д��������Ŀǰѧͽ����
             ����ı�������Ϊ��
             ���ࣺsword
             ���ࣺblade
             ���ࣺstaff
             ���ࣺhammer
             ���ࣺwhip
             ���ࣺaxe
             ���ࣺfork
             ǹ�ࣺspear             
             ذ���ࣺdagger\n",
			 ]));
	  
  set("valid_startroom", 1);
  setup();
 
}
/*
int valid_leave(object me,string dir)
{
        if(me->query("vocation")!="����" && dir=="enter")
                return notify_fail("�㲻�����������ܽ�����������!\n");
                return ::valid_leave(me,dir);
                return 1;
}
*/

