
inherit ROOM;
void create ()
{
  set ("short","��ʱ����");
  set ("long", @long
��ʱ����
long);

  set("exits", ([ 
      "west":__DIR__"gangkou2",
      ]));
  set("valid_startroom", 1);
  set("outdoors","jiujiang"); 
  setup();
 
}

