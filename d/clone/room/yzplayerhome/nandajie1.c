
inherit ROOM;
void create()	
{
	set("short","����С·");
	set("long", @LONG
������������Ҵ�Ĵ���С·������Ŀǰ������˿ڷǳ��٣�
��������Ҳֻ���޽���һ��С·��������һ���˼ң���˵��
���˼ҵ���������һ�磨LIY����Ů����������������FOXGOD����
���˶�����������һ�����ĸ��֡���Ϊ���˸ոս�鲻�ã���
�԰ᵽ������ס�ˡ�
LONG);
    set("exits", ([
	        "south" : __DIR__"door",
	        "east":__DIR__"liy_foxgod",
	        "west":__DIR__"tong_and_wife",
	        "north":__DIR__"nandajie2",
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
