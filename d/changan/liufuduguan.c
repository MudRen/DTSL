

inherit ROOM;

void create ()
{
        set ("short", "六福赌馆");
        set ("long", @LONG
这里是长安有名的赌场，一看其布置和结构，就能让人联想到有名
的香家，看样子，这里的老板和香家应该有一些特殊的关系。几个
赌徒光着膀子，满头大汗的推着牌九，一些人在旁边看着，多半是
输光了又不想走的人。虽然说只是输了钱的人想回家，但是从他们
全部赌红了眼，丝毫看不出有想回家的迹象。
LONG);

        set("exits", 
        ([
     "west" : __DIR__"yadajie2",
        ]));
        set("objects",([
         "/obj/mj":1,
         "obj/dutu":1,
         ]));
        setup();
   replace_program(ROOM);
}


