
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ժ");
  set ("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ�������������
��̫ʦ���Ͻ�ѧ���Ǿ��ǵ�������������ˡ�������������������ѧ��
ѧ����һ�Ź��ⰻȻ���鰸������������ǰ�棬���ϰ��ż��������˵�
��װ�鼮��
LONG);

  set("exits", ([ 
 "west":__DIR__"zqdajie3",
       ]));
  set("objects",([
	  __DIR__"npc/xia":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

