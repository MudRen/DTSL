
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ��ʯ���̳ɵ�С·��̧ͷ��ȥ��ǰ����һ������������
�������ϵ��֡�ʯ�׵������Ǳ��̵���ľ���Ա߻�����һ��ʯ��������
д��[������]�������֡�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"suishilu1",
  "westup":__DIR__"miaodoor",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

