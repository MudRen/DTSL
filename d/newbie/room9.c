
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɱ��ƪ");
  set ("long", @LONG
����ְҵ�����PK�������õİɣ� 
ɱ����������ѧϰ ��ʯ�����ķ�����Ӱ�ӽ����� 
xue yang yingzi-jianfa 
xue yang wanshi-jue 
��ʯ���������ô���execute(shizhan) huanmo(��ħ):������3 ����ʹ
���� �ﵽ���壬Ѹ��ս������������Ҳά�ּ���ͽ����ˡ� 
execute(shizhan) wuxing(����):����ʹ�Լ���������״̬�����˿���
���㣬�����ڴ�ʱ���ڲ����߶���һ������ս��״̬����������Ч���� 
ɱ�ֻ������ڱ�����ͿĨ��ҩ�� 
ɱ�ֻ�����ʹ�ð�ɱ (ansha)��������ɱ�������ĵ��ˣ�һ�����С�
���⣬ɱ�ֶ���Ѱ�ҺõĿ�ʯ��ҩ���и�������ơ�
LONG);

  set("exits", ([ 
 "east":__DIR__"room7",
 //"west":__DIR__"room9_1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

