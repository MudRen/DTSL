
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩʦƪ");
  set ("long", @LONG
��������ҩ�꣬qiuzhi shangguan�Ϳ����ˡ� 
ҩʦ��Ϊѧ���������ҩʦ��ѧ������ҩʦ���֣�����ֻ��ѡ��һ���� 
xue shangguan bencao-shuli�����Ϊ���������ҩʦ��
xue shangguan poison�����Ϊѧ������ҩʦ�� 
��������ֻ��ѧ�� 100 �����Ժ�����ҩ����ߡ� 
����������뿴�� help vocation�ɣ�
LONG);

  set("exits", ([ 
 "west":__DIR__"room8",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

