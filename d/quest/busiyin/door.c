
inherit ROOM;
void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ǰ�������ϵ������Ѿ���������ˣ������Ѿ�������
�Ӳݣ������������������ѡ������ǽ���Ѿ��󲿷�̮�����Գ�������
���ա�
LONG);

  set("exits", ([ 
 "enter":__DIR__"simiao",
 "out":__DIR__"xiaolu3",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
