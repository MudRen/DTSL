inherit ROOM;
void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ɽ��ɽ·��·�������Ӳݴ�������ʱ�л�
ɫ��쵵�С�ߴ���Ľ��滬��������������ԼԼ����ɽ����Ժ��
�����о�����
LONG);

  set("exits", ([ 
 "northup":__DIR__"shanlu2",
 "southdown":"/d/xingyang/shanlu3",
        ]));
 set("valid_startroom", 1);
  setup();
}
