
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������Ժ");
  set ("long", @LONG
����������֮�����ڳ��������������Ժ�������Ժ���ĺ�������
�ܶ೤���������Ѻ����͵������������������н̵�����Ժ�Ľ��ã���
��������һ����Ⱦ��һ�Ź��ⰻȻ���鰸���ڷ�������ϰ��ż�����
���˵���װ�鼮��
LONG);

  set("exits", ([ 
 "west":__DIR__"wxdajie3",
       ]));
  set("objects",([
         __DIR__"npc/xuxing-zhi":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

