
#include <room.h>

inherit ROOM;
string do_look1();
string do_look2();
int do_nothing(string arg);
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ҡ�������һ���صء�����û�����⣬ֻ�����涴��©
�µ�˿˿���ߡ�ǽ������һ����,�Ա߻���һ��ʯ�̵Ļ���
LONG);


	set("exits", ([
		"out" :__DIR__"fendi",
		"west":__DIR__"mishi2",
	]));
	set("item_desc",([
	 "��":(:do_look1:),
	 "��":(:do_look2:),
	 "liuyan":"���մ󷨵�ѧϰ�������ˡ��Լ���ĥ�ɣ�\n",
	 ]));
	 set("no_channel","�㻹��ר�������ɣ�\n");
  	setup();
}

string do_look1()
{
 return "�˶�һ��ֻ�ܽ���һ�Σ��ú���ϧ�ɣ�\n";
}
string do_look2()
{
  object me,here,*ob;string *fs;int i,j;
   me=this_player();
   fs=me->query("force_skill");
   if(sizeof(fs)>0)
   if(sizeof(fs)>1||(fs&&fs[0]!="huanri-dafa"))
   return "�㿴�˰��죬����ʲôҲ��������\n";
  if(me->query("sen")<me->query_skill("huanri-dafa",1)/2)
   return "�㾫��̫���ˣ�\n";
   if(me->is_busy())
   return "����æ���أ�\n";
   here=load_object(__DIR__"mishi");
   ob=all_inventory(here);j=0;
   for(i=0;i<sizeof(ob);i++){
     if(interactive(ob[i])) j++;}
   if(j>1) return "������̫���ˣ����޷���������ѧϰ��\n";
   if(me->query_skill("huanri-dafa",1)>=100)
   return "����û��е�ͼ��ʮ����ǳ���������Ѿ�û��ʲô����ˡ�\n";
   me->receive_damage("sen",me->query_skill("huanri-dafa",1)/2?me->query_skill("huanri-dafa",1)/2:1);
    me->improve_skill("huanri-dafa",me->query_int()/10+me->query_skill("huanri-dafa",1)/5);
   me->start_busy(1);
   return "�㿴�Ż���ͼ�󣬾���[���մ�]����Ϊ����һ������ߡ�\n";
}

