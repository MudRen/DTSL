
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ȡ����ȵ�ǽ���ϻ��Ÿ��ֲʻ����з羰�����һ��
���ǳ������ҹ���֮�֡��ϱ߾��������ɽ����������ˡ�������������
�˺ܶ�����Ǳ���ڽ�������������Ҫ���������硣�кܶ���Ӵӽ�����
�������������ŴҴ��߳���
LONG);
  set("exits",([
	  "west":__DIR__"liangting",
	  "south":__DIR__"woshi2",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

