
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
���ǳ�����һ�����ֺŵ�ҩ�̣��ഫԭ�����ϰ��ǻʹ��е���ҽ��
�ֶο�֪һ����ҩ���еİ���Ҳʮ�ֿ��������α��ڿ�Ļ�Ʋ��ĸɸ�
������ǽ�Ϲ����˱���������л�ҡ�
LONG);

        
        set("exits", ([  
 "east" : __DIR__"xishidongjie1",
        ]));
   set("objects",([
		  __DIR__"npc/zhang":1,
		  ]));
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


