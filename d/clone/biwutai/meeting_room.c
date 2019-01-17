
inherit ROOM;
#include <ansi.h>
int do_dengji(string arg);
int do_register(string arg);
int do_list();
string give_msg();
mapping d_member=([
 "feima":"��������","haisha":"��ɳ��","songjia":"�μұ�",
 "duzun":"����","lifa":"��  ��","dajiang":"����",]);
void create()	
{
	set("short", HIG"����̨ǰ��"NOR);
	set("long", @LONG
�����Ǳ���̨��ǰ�����������߾Ϳ��Ա����ˡ�һ��˵����
�������������������ĵط��������Ĺ��������ʤ�ƣ�
ÿ�������������н������μӱ������ˣ�������������
���Ǽ����������(dengji),ÿ��ֻ�ܵǼ�����������Ȼ��
������Ա������ע��(zhuce)��ÿ��ֻ�ܳ�����ˡ�Ȼ��ȥ
����Ϳ����ˡ����ڵǼǵ������Ͱ��Ĵ����뿴����(pai).
����ʹ��list ���鿴�Ѿ��Ǽǵ��������ᡣ
(������ help biwu).
LONG);
    set("exits", ([
                "east" : "/d/taishan/yuhuangding",
	        "west":__DIR__"biwutai",
 	]));
 	set("no_fight",1);
 	set("no_sleep",1);
 	set("no_get",1);
 	set("no_quit",1);
 	set("item_desc",([
 	    "pai":(:give_msg:),
 	    ]));
 	  setup();
	
}	

void init()
{
   add_action("do_dengji","dengji");
   add_action("do_register","zhuce");
   add_action("do_list","list");
}
int do_dengji(string arg)
{
  object ob;string *party;
  ob=this_player();
   if(!arg)
   return notify_fail("��Ҫ�Ǽ�ʲô��\n");
   if(!d_member[arg])
   return notify_fail("����Ǽ�ʲô������look pai\n");
   if(arg+"_b"!=ob->query("shili/name"))
   return notify_fail("��û��Ϊ�������Ǽǵ�Ȩ����\n");
   party=environment(ob)->query("dengji");
   if(sizeof(party)==2)
   return notify_fail("�Բ����Ѿ��Ǽ����������ˣ��㻹�ǵȵȰɣ�\n");
   if(sizeof(party)>0)
   if(member_array(arg,party)!=-1)
   return notify_fail("��������Ѿ��Ǽǹ��ˣ�\n");
   if(sizeof(party)>0)
   environment(ob)->set("dengji",party+({arg}));
   else environment(ob)->set("dengji",({arg}));
   if(sizeof(party)==0)
   message("system",HIG"�������᡿:"+d_member[arg]+"�ڱ���̨��ʱ��������Ӣ�۵��ֽ̣�\n"NOR,users());
   else
   message("system",HIG"�������᡿:"+d_member[arg]+"ǰ��Ӧս��\n"NOR,users());
   return 1;
}

int do_register(string arg)
{
   object ob;string *party;string *mem;
   ob=this_player();
   if(!arg) return notify_fail("��Ҫע��ʲô��\n");
   if(!d_member[arg]) return notify_fail("����ϸһ��ѣ�look pai!\n");
   if(ob->query("clean/register_leitai"))
   return notify_fail("���Ѿ�ע����ˣ�\n");
   if(arg+"_b"!=ob->query("shili/name"))
   return notify_fail("��û��Ϊ���������������Ȩ����\n");
   party=environment(ob)->query("dengji");
   if(sizeof(party)<=0)
   return notify_fail("����û�������Ǽǣ����ȵǼǰɣ�\n");
   if(sizeof(party)>0)
   if(member_array(arg,party)==-1)
   return notify_fail("Ŀǰ�ǼǵĲ��������������������\n");
   mem=environment(ob)->query("register/"+arg);
   if(sizeof(mem)==5) return notify_fail("���Ѿ����ˣ�����´ΰɣ�\n");
   if(sizeof(mem)>0)
   if(member_array(ob->query("id"),mem)!=-1)
   return notify_fail("���Ѿ�ע����ˣ�\n");
   ob->set("clean/register_leitai",arg);
   if(sizeof(mem)>0)
   environment(ob)->set("register/"+arg,mem+({ob->query("id")}));
   else environment(ob)->set("register/"+arg,({ob->query("id")}));
   message("system",HIG"�������᡿:"+ob->name()+"����"+d_member[arg]+"׼������̨һ�����֣�\n"NOR,users());
   return 1;
}

string give_msg()
{
  return "Ŀǰ���ԵǼǵİ��������Ĵ����У�\n"+  
  "����: �μұ�:songjia ��������:feima   \n"+
  "      ��ɳ��:haisha  ����  :duzun   \n"+
  "      ��  ��:lifa    ����  :dajiang \n";
  
}

int valid_leave(object ob,string dir)
{
   if(dir=="west"&&!ob->query("clean/register_leitai"))
   return notify_fail("ֻ��ע����Ķ�Ա���Ե���̨��ȥ��\n");
   if(dir=="west"&&ob->query("clean/fail"))
   return notify_fail("���Ѿ����ˣ���������ȥ�ˣ�\n");
   if(dir=="east"&&ob->query("clean"))
   return notify_fail("�ȱ�����������߰ɣ�\n");
   if(this_object()->query("member_count")>=2&&dir=="west")
   return notify_fail("�����Ѿ����������ˣ�\n");
   this_object()->add("member_count",1);
   return ::valid_leave(ob,dir);
}

int do_list()
{
  string *party,str;int i;
  party=this_object()->query("dengji");
  if(sizeof(party)==0)
  return notify_fail("Ŀǰû�а��������Ǽǡ�\n");
  str=sprintf("Ŀǰ�Ǽǵİ��:\n");
  for(i=0;i<sizeof(party);i++)
  {
    str+=d_member[party[i]];
    str+="\n";
  }
  write(str+"\n");
  return sizeof(party);
}
