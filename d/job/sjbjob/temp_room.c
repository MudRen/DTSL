
inherit ROOM;
void create ()
{
  set ("short","临时房间");
  set ("long", @long
临时房间
long);

  set("exits", ([ 
      "west":__DIR__"gangkou2",
      ]));
  set("valid_startroom", 1);
  set("outdoors","jiujiang"); 
  setup();
 
}

