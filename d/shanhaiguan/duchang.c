// /d/gaoli/duchang
// Room in ɽ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ĳ�");
	set("long", @LONG
������һ�Ҷķ�����ҹĻ���ٺ�����͸������֡���������Ӯ��
��Ц����Ҳ����İû���������ʵ����һ���ݳ޵ĵط�����ʱ����Ϊ��
ʽ�����ݳ޵��ˣ�׼���Ÿ�ʽ�����ݳ޵����ܡ�
LONG	
       );
set("exits", ([
                "north":__DIR__"dongdajie",    
	]));
       setup();
       replace_program(ROOM);
}
