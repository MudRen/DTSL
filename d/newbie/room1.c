
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
���ｫ�����ѧ���ڴ���������Ļ������ܡ������ʹ�� help ��
�����õ�������
���������û�нӴ�������������ʹ�� help newplayer �����ɣ�
�������õ���ֱ�۵İ������������������վ�㣺
www.dtsky.com 
dt66.126.com 
�����к���ϸ�İ���˵����
����������ߵĽ������;���������ʹ�ø���Ƶ����ĿǰƵ���У�
chat    ����Ƶ�����磺�����ġ������(Yanyan)����Һ�
party   ����Ƶ��������������ɲſ���ʹ�á�
rumor   ҥ��Ƶ����˭�������ã���ҥ�ĺö�������
banghui ���Ƶ�������������ſ����á�
dt      ����Ƶ����

����ʹ�� tune ����������Ŀǰ����ʹ����ЩƵ������ tune Ƶ������
����Թص���ЩƵ����
LONG);

  set("exits", ([ 
 "east":__DIR__"room2",
 "west":__DIR__"room3",
 "north":__DIR__"room4",
 "south":__DIR__"door",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

