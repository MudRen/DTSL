
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�����Ǻ��ݵ��ϴ�֡������Ǻ��ݵ������ˡ�����Ҳ�������֡���
���������������ַǷ��������Ǻ���������ļң�ֻ���ſ�վ�ż�����
���������ע�������������ˡ�����������Ů��Ҫ���������ˣ�����
�Ҷ�����Ҫ�úÿ����ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie2",
  "north":__DIR__"center",
  "west":__DIR__"dafu",
        ]));
  set("objects",([
       "/d/clone/npc/yougui":1,
       ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

