
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ���");
  set ("long", @LONG
������ǳ������������ģ���������֣���ȸ����ˣ���λ�ڳ�
���ǵ��������ϣ��������������ţ�����ֱͨ�ʳǵ���ȸ�ţ�������ʮ
�ɣ����Ծ��Ƿǳ�����Ρ��Ľ�����������ң�������Ļʳǣ����ƺ�ΰ��
����׳�ۡ����ﶫ������Ĵ������ƽ��֣���������������ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"zqdajie4",
 "south":__DIR__"mingdemen",
 "east":__DIR__"xpdajie4",
 "west":__DIR__"xpdajie3",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

