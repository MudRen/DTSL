// Room: /d/longyan/tenting.c

inherit ROOM;

void create()
{
        set("short", "ʮ��ͤ");
        set("long", @LONG
������һ��·��Сͤ���ƺ��Ѿ��ܶ���û������
��ɨ���ˡ�ͤ�ӵ�ǽ�ϻ���һ�����ƺ���һ������Ů
�ӣ��Ա��ƺ�����һ��ʫ��poem��������ͤ��������
�Ǻ���ɽ�ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road1",
]));
set("item_desc", ([
	"poem":"\nֻ  ��  ��  ʮ\n\n��  ��  ��  ��\n\nԧ  ��  ��  ƽ\n\n��  ��  ˿  ��\n\n��  ��  ��  ˪\n\n��  ��  ��  ��\n\n��  ��  ��  ��\n\n\n",
	]));
        setup();
        replace_program(ROOM);
}
