
#include <ansi.h>
inherit ITEM;
int do_sit(string arg);
int do_check(string arg);
void create ()
{
  set_name(HIW"��Ƥ����"NOR,({"chair"}));
  set ("long","����һ�ź�ľ���Σ���������һ�Ű�ɫ�Ļ�Ƥ��\n"+
              "ֻ�б��������������档\n");
  setup();
 
}
int is_get_of(object ob,object ob2)
{
  return notify_fail("����������������\n");
}
void init()
{
  add_action("do_sit","sit");
  add_action("do_check","check");
}
int do_sit(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="down"))
  return notify_fail("��Ҫ����������\n");
  if(ob->query("family_lingwu")!="songjia")
  return notify_fail("����书��ô������ô�����������������أ�\n");
  message_vision("$Nսս������������������������ֻΣ����úܲ����,����Ӧ�ü��[check]һ�¡�\n",ob);
  return 1;
}
int do_check(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="����")
  return notify_fail("��Ҫ���ʲô��\n");
  if(ob->query("family_lingwu")!="songjia")
  return notify_fail("ʲô��\n");
  tell_object(ob,"�㿪ʼ������Σ��������ӵ��Ұ����ϵ���һ����ֵĻ�ͷ��\n"+
                 "��ͷ��������������[up,right,left]Ť��[roat].\n");
  return 1;
}
  
  