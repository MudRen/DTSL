
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
������ǳ����������ľ�¥�ˣ�ͨ��һ������û�ʸ�������Է��ģ�
ֻ����Щ���﹫�ӣ��������̣��������˻���һЩ�ǲ���ĺڵ������
�����������ܡ���¥�ľ�����ã���������ϯ���ɾ��������ֺ�Ծ����
һ�������˷�⡣
LONG);

  set("exits", ([ 
 "west":__DIR__"xishidongjie3",
        ]));
 set("objects",([
	 __DIR__"npc/xiaoer5":1,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

