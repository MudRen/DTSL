
inherit ROOM;
void create ()
{
  set ("short","池塘");
  set ("long", @LONG
这里是一个不大的池塘，池塘周围长满了芦苇。有几只野鸭
正栖息在其中。偶尔还会有鱼儿蹦出水面。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu1",
        ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}
