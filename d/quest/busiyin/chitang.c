
inherit ROOM;
void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ������ĳ�����������Χ������«έ���м�ֻҰѼ
����Ϣ�����С�ż������������ĳ�ˮ�档
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu1",
        ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}
