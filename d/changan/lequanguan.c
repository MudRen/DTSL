

inherit ROOM;

void create ()
{
        set ("short", "��Ȫ��");
        set ("long", @LONG
�����ǳ��������Ѻ������Ĺ�֮�⣬�����������Ķĳ����������
�������������ĳ�һֱ���������������������£����Բ��ٶĿͶ��ĵ�
��������������
LONG);

        set("exits", 
        ([
     "west" : __DIR__"hgdajie3",
        ]));
        set("objects",([
         "/obj/mj":1,
         ]));
         
        setup();
   replace_program(ROOM);
}


