
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���������ۡ������ǲԴ����ľ����ʱ����������
���е������������Ӳݴ�������������Ұ�ô���Ľ�ǰ�ܹ���
LONG);

  set("exits", ([ 
 "south":"/d/quest/bawangdao/xiaojing",
 "northeast":__DIR__"xiaolu2",
 "west":__DIR__"chitang",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
