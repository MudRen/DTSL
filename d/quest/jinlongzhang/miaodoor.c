
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������ǻ����µ��ſ��ˡ�ֻ���������ҵ���ɫ��Щ�����ˣ�ֻ��
[������]�����ֻ�������������������ţ���������ԼԼ�������̾���
���������
LONG);

  set("exits", ([ 

  "eastdown":__DIR__"shijie",
  "enter":__DIR__"huilongsi",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

