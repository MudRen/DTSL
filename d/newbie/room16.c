
#include <ansi.h>
inherit ROOM;

int do_reg(string arg);

void create ()
{
  set ("short","��ҵƪ");
  set ("long", @LONG
��ϲ��Ӵ���ѧԺ�б�ҵ�ˣ���������ȷʵû��ʲô�����ˣ���
��¥ down �Ϳ����ˣ��������û������⣬�����ٻ�ȥ�������Ժ��
��������������㣬����ʱʹ�� news �������鿴��Ϸ�ĸ��������
������ʦ��ɵĴ��󣬻��µ������������⣬���� e-mail ����ʽͨ
֪����Ҫ���ŷǵ���ʦ�����ٽ������Ϊ��ʦҲ���Լ��Ĺ�����������
�������ߵġ�Ŀǰ�� e-mail ����Ϊ��realyanyan@sohu.com ����ʲô
����Ҳ�뷢�ŵ����e-mail��������Ϸ���� bug��ɵ���ʧ������Ȩ��
����ʦȡ�ò��������ǧ��Ҫ���ģ�
*
������鷳�Ļ��������ʹ�� register ������ȷ�������Ч�����ʼ���
�Ա�����ʦ��ʱ����ȡ����ϵ��������費��Ҫ���˳���Ϸ��
*
ף���ڴ���˫������ÿ��ģ�
LONG);

  set("exits", ([ 
  "down":"/d/slwg/zoulang1",
 "south":__DIR__"room13",
        ]));
  
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  
  add_action("do_reg","register");
}

int do_reg(string arg)
{
   object ob,link_ob;
   
   ob=this_player();
   
   if(!arg)
    return notify_fail("��������ĵ����ʼ���ַ��\n");
  
   if(strsrch(arg,"/")!=-1)
    return notify_fail("��������ȷ�ĵ����ʼ���ַ��\n");
   
   if(strsrch(arg,"@")==-1)
    return notify_fail("��������ȷ�ĵ����ʼ���ַ��\n");
   
   ob->set("email",arg);
   if(!objectp(link_ob=ob->query_temp("link_ob")))
    return notify_fail("�����뱨����ʦ��\n");
  
     LOGIN_D->set_email(link_ob,arg);
 
   ob->save();
   
   tell_object(ob,"�����ʼ�ȷ����ϣ������ʦ��ͨ����������ʼ�������ϵ��\n");
   return 1;
}