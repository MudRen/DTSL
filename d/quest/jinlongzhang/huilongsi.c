
inherit ROOM;


void create ()
{
  set ("short","������Ժ");
  set ("long", @LONG
������ǻ����µĴ�Ժ����ǰ���ǻ����µĴ��ܱ��������һ��
�᷿�����߳��ؿ������ƺ���������ɮϰ��ĵط��������Ե���Щ���壬
���������µ�����Ǻܺá�
LONG);

  set("exits", ([ 

  "out":__DIR__"miaodoor",
  "enter":__DIR__"baodian",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

