
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ܹܸ�");
  set ("long", @LONG
���������ݳǵ��ܹ�ξ��ʤ�ĸ��ڡ��ŵ����Ϸ�����һ�����Ž��
�Ĵ����ӣ�����д���ܹܸ��������֡��ſ��м����ٱ������ţ�������
�ݵ�վ��������������������ˡ�ƽʱ��������������ͣ����
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie2",
 "enter":__DIR__"neiting",
        ]));
  
  set("valid_startroom", 1);
  setup();
 
}

