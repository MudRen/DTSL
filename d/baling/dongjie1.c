
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ���Ķ��֣���������˺ܶࡣ�����ǰ���������ˣ�����
���������ֵ��������ϱ���һ��С������޹⣬�ǵ�Ʀ��å�ۼ��ĳ�
�������洫���˳��ܡ������������
LONG);

  set("exits", ([ 

  "northwest":__DIR__"center",
  "east":__DIR__"dongjie2",
  "south":__DIR__"xiaoxiang1",
       ]));
 
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

