
inherit NPC;
string do_quest();
void create()
{
       set_name("����", ({ "he shang","he","shang"}) );
       set("gender", "����" );
       set("age",18);
       set("long","���������������ҵ�С���С�\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
	   set("inquiry",([
		   "����":(:do_quest:),
		   ]));
       setup();
 
}
string do_quest()
{
 
  return "����������ħ����һ�����Ѳ������\n"+
         "�����ڵĺ��о�����������Ժ����ܻ���\n"+
         "һ�첻��ƽ��ִ�������һ�����\n";
}