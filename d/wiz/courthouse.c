#include <ansi.h>
inherit ROOM;
int do_post(string arg);
void create ()
{
  set ("short",HIR"����˫����ͥ"NOR);
  set ("long", @LONG
�����Ǵ���˫���ķ�ͥ������ʦ������ҵĵط������ĳ�������
���ڴ���˫�����һ�����Դ���˫����չ���Ӱ�죬��ʦ�����������
���������С������н����������ʹ�� xuangao�����桹����������
�����
LONG);

  set("exits", ([ 
  "west":__DIR__"wizroom",
        ]));
  set("valid_startroom", 1);
  set("no_quit",1);
  set("no_shout","��ͥ��׼������������\n");
  set("no_look_msg","���ﲻ׼�Ĵ�������\n");
  set("no_suicide","���˴�����Ը�����û��Ҫ��ɱ�ɣ���\n");
  set("no_fight",1);
  set("no_channel","���˷�����������˵����\n");
  set("no_tell","���˷�����������˵����\n");
  setup();
}
int valid_leave(object ob,string dir)
{
  if(!wizardp(ob))
  return notify_fail("�㷸���˴��󣬻��ǲ�Ҫ���ĺã�\n");
  return ::valid_leave(ob,dir);
}
void init()
{
  add_action("do_post","xuangao");
}
int do_post(string arg)
{
  object ob;
  ob=this_player();
  if(!arg){
   if(!wizardp(ob))
     return notify_fail("ʲô��\n");
   else return notify_fail("��Ҫ����ʲô��Ϣ��\n");}
 if(!wizardp(ob))
 return notify_fail("ʲô��\n");
 message("vision",HIR+"����  ͥ��:"+arg+"\n"+NOR,users());
 return 1;
}
  
