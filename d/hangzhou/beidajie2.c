
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵı���֡��ϱ߾��Ǻ��ݵ������ˡ����������������
�����ֵ������������οʹ���������߹�������̸�������������ľ�ɫ��
·���кܶ���ˣ�����ˣ������нкõ����������ﴫ����
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
 "east":__DIR__"yanju",
  "north":__DIR__"beidajie1",
  "west": "/d/clone/room/cityroom/hangzhou"
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

