
inherit ROOM;

void create()
{
        set("short", "�ຣ��");
        set("long", @LONG
��ǰ��һƬ�������Ƭ��ˮ�����˾�ס��ɳĮ�е����ǣ����Ա���
���𾴵ĳ�Ϊ��ʥ�������������и�С�������������˳�ǧ����ĸ���
���е��������裬�еľ���������Ȼ����һ��ɧ��������ǧ��ֻ��
����������죬�γ���һƬ׳�۵�ͼ����
LONG );
        set("outdoors", "tuyuhun");
        set("exits", ([
                "southeast" : __DIR__"shatulu1",
                "west" : __DIR__"shamo1",
                "northwest" : __DIR__"shamo2",
        ]));
        set("objects",([
          __DIR__"npc/daoke":1,
         ]));
         
        set("valid_startroom", 1);
        setup();
}

