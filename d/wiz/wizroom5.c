
#include <ansi.h>
inherit ROOM;
string do_joke();
void create ()
{
  set ("short",HIC"��ʦ������"NOR);
  set ("long", @LONG
��������ʦ�����ĵط�����ǰ�ķ���һ�Ŵ����ӣ��������һ����
�ʼǱ�����¼����ʦ�Ĺ������̡��Աߵ�ǽ�ϻ����ż����·���������
���������ľ�ɫ����ˮ�������ò����֡�ǽ���ϻ�����һ��ɳ��������
������һ����(ren)����������˯�� ����֪����˭��
LONG);

  set("exits", ([ 
// "south":__DIR__"wizroom2",
         ]));
    
    set("item_desc",([
      "ren":(:do_joke:),
      ]));
    
    setup();
  "/obj/board/task_b.c"->foo();
  
}

string do_joke()
{
  object ob;
  ob=this_player();
  return HIC+ob->name()+HIC+"�����ſ�ˮ���������������ƣ���ˡ�\n"NOR;
}
