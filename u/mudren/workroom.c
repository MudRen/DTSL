inherit ROOM;
void create()
{
  set("short", "陋室");
  set("long", @LONG
山不在高，有仙则名，水不在深，有龙则灵，斯是陋室，惟吾德馨。
LONG);
  set("exits",
      ([ //sizeof() == 4
          "west":"/d/wiz/wizroom",
  ]));
  set("objects",
      ([ //sizeof() == 1
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
