
inherit ROOM;
void create ()
{
  set ("short","���");
  set ("long", @LONG
��������������ǰ�ķ����Ѿ��ƾɲ�����û������Ŀ��������
�����ӡ������ӣ��������������������µĽ�̼��һ��紵����ֻ�м�
���ƾɵķ�ᦻ��ں����������ţ�����һ�ֱ����ķ�Χ��
LONG);

  set("exits", ([ 
 "out":__DIR__"door",
        ]));
  set("objects",([
     __DIR__"pishou-xuan":1,
     __DIR__"anlong":1,
     __DIR__"youniao-juan":1,
     __DIR__"zuoyou-xian":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}
