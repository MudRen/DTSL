
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�̵�ƪ");
  set ("long", @LONG
����̻�������������������������Ҫ���̵ꡢС�Ե�򷹵�
�У�Ȼ��ʹ�� list ���������ʲô������
> list
����Թ���������Щ������
������                        (zhouzi)        ��ʮ��Ǯ  
��Ѽ                          (kaoya)         һ������  
ţƤ�ƴ�                      (jiudai)        ��ʮ��Ǯ  
��֭��ζ��                    (yu)            ��������  

��������򡰽�֭��ζ�㡱��ʹ��  buy yu from ���������־Ϳ����ˡ�
��Ȼ����Ҫ�������������ˣ�
LONG);

  set("exits", ([ 
 "west":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

