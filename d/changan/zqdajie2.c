
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ���");
  set ("long", @LONG
������ǳ������������ģ���������֣���ȸ����ˣ���λ�ڳ�
���ǵ��������ϣ��������������ţ�����ֱͨ�ʳǵ���ȸ�ţ�������ʮ
�ɣ����Ծ��Ƿǳ�����Ρ��Ľ�����������ң�������Ļʳǣ����ƺ�ΰ��
����׳�ۡ������ǳ������ã�������һ�ҹ�ģ��С�Ŀ�ջ��
LONG);

  set("exits", ([ 
 "north":__DIR__"zqdajie3",
 "south":__DIR__"zqdajie4",
 "west":__DIR__"donglaikezhan",
 "east":"/d/clone/room/cityroom/changan",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

