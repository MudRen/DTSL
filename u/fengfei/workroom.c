inherit ROOM;
void create ()
{
set ("short", "����");
set ("long", @LONG
����ǵ���
LONG);
set("exits", 
([ //sizeof() == 4
"west": "/d/wiz/wizroom",
 ]));
set("objects", 
([ //sizeof() == 1
  ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

