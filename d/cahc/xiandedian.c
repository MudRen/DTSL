#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Եµ�");
  set ("long", @LONG
�����������ڻʹ���ס�����������������е�����ڶ�����
�����Ϊů����Ϊ��ס�����ң��ŵ������ļ����ϡ����������濻��
��Ϊ����ĳ�����������Ժ���������ɱ������֮�á������ǻʼ�
���ã�������������ţ������¬�֣�װ�ο���������
LONG);

  set("exits", ([ 
 "north":__DIR__"chongjiaodian",
 "southdown":__DIR__"xiandemen",
        ]));
  set("objects",([
	  "/d/changan/npc/lijiancheng":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

