
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
�������������̣�qiuzhi tie�Ϳ��Գ�Ϊ�������������Ϲ�����ѧ
ϰ���켼����xue shangguan duanzao-jishu�����켼��ֻ��ѧ��100
�����Ժ󿿴��춫����ߡ������������ѯ�ʡ���֧����ȷ���Լ�����
����֧��
Ŀǰ������������֧�� 
1 ���������(weapon) 
2 ������ס�ҩ����(armor) 
3 �������Ϳ��������(poison)�� 
�����ʹ��choose ��ѡ���� choose weapon 
ÿ����֧�����Լ������ã����廹�ǿ��� help vocation�ɣ�
LONG);

  set("exits", ([ 
 "west":__DIR__"room7",
 "east":__DIR__"room8_1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

