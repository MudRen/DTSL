
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���������ۡ�ǰ����һ�������������Ѿ��ܾ�û
����ס�ˡ���һ������Զ�Ϳ�������ľ�Ÿ�֨��֨��������
LONG);

  set("exits", ([ 
 "enter":__DIR__"door",
 "south":__DIR__"xiaolu2",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
