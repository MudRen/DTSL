
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ���");
  set ("long", @LONG
������ǳ������������ģ���������֣���ȸ����ˣ���λ�ڳ�
���ǵ��������ϣ��������������ţ�����ֱͨ�ʳǵ���ȸ�ţ�������ʮ
�ɣ����Ծ��Ƿǳ�����Ρ��Ľ�����������ң�������Ļʳǣ����ƺ�ΰ��
����׳�ۡ�������һ����ΰ׳�۵Ĳ�˹���¡�
LONG);

  set("exits", ([ 
 "north":__DIR__"zqdajie2",
 "south":__DIR__"zqdajie1",
 "west":__DIR__"bosihusi",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

