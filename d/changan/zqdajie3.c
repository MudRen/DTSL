
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ���");
  set ("long", @LONG
������ǳ������������ģ���������֣���ȸ����ˣ���λ�ڳ�
���ǵ��������ϣ��������������ţ�����ֱͨ�ʳǵ���ȸ�ţ�������ʮ
�ɣ����Ծ��Ƿǳ�����Ρ��Ľ�����������ң�������Ļʳǣ����ƺ�ΰ��
����׳�ۡ������м���Ժ���������ŵĶ�������
LONG);

  set("exits", ([ 
 "north":__DIR__"guangchang",
 "south":__DIR__"zqdajie2",
 "east":__DIR__"shuyuan",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

