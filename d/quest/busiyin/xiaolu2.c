
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���������ۡ�ǰ���ƺ���һ���������Ե��Ӳݷ�
��ïʢ��һ��紵�����Ӳݺ����˰�����·�ӿ��
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaolu1",
 "north":__DIR__"xiaolu3",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
