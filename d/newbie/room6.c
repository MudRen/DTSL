
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
����̻��������������뵱�̵��ϰ���н��ף�������Ҫ��һ��
����ȥ�ˡ��ڵ����������ʹ���������
list ������������ʲô������
value�������������Ķ������й���
buy  ���ӵ���������
sell : �ڵ���������

>list
��Ҫ��������Ʒ��
����[weapon]������[armor]����ʯ[iron]��ҩ��[medicine]������[other]��

��ʱ��Ҫʹ�� list ������Ŀ���鿴�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

