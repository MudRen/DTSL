#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","���ε�");
  set ("long", @LONG
����һ��ר����Ů���õ����εĵ��̣��ڳ����ǳ�������ǰ�����
�Ĵ��ǹ���ϱ���������аڷ���һ�ų�����ľ����������Ŵ��СС
�ĺ��ӣ��������涼����������ĸ������Ρ�һ�����ֵ��ϰ������к�
�����Ĺ˿͡�
LONG);

  set("exits", ([ 
 "west":__DIR__"xishidongjie1",
      ]));
  set("objects",([
         __DIR__"npc/zhubao-boss2":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
