inherit ROOM;
void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ɽ��ɽ·������ĵ���Խ��Խ��������ɽ
�Ƶ����ߣ�������������ӿ졣
LONG);

  set("exits", ([ 
 "southdown":__DIR__"shanlu",
 "enter":__DIR__"room",
        ]));
 set("valid_startroom", 1);
  setup();
}