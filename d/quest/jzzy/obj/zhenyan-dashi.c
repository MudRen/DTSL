
inherit NPC;
string do_quest1();
string do_quest2();
string do_quest3();
string do_quest4();
void create()
{
       set_name("���Դ�ʦ", ({ "zhenyan dashi"}) );
       set("gender", "����" );
       set("age",60);
       set("long","����һλ��¥�����Ļ�����ɮ��\n");
       set("combat_exp",20000000);
       set("inquiry",([
          "��ɨ":(:do_quest1:),
          "����":(:do_quest2:),
          "����":(:do_quest3:),
          "��������":(:do_quest4:),
          ]));
       setup();
 
}

string do_quest1()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step10"))
   return "��˵��ʲô����ɮ����һ��Ҳ��������\n";
  ob->set_temp("dtsl_quest_jzzy/step11",1);
   ob->delete_temp("dtsl_quest_jzzy/step10");
  return "ʩ����������ͳɣ���ɨ���ã������ĵ�ְ�����ɼ�����֮�֡�\n";
}
string do_quest2()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step11"))
   return "��˵��ʲô����ɮ����һ��Ҳ��������\n";
  if(ob->query_int()<50)
  return "��ʩ������������ʯ�����޻۸�������Щ����ʲô���أ�\n";
  ob->set_temp("dtsl_quest_jzzy/step12",1);
   ob->delete_temp("dtsl_quest_jzzy/step11");
  return "һ���Ϊ���������Բ���Ϊ����\n";
}

string do_quest3()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step12"))
   return "��˵��ʲô����ɮ����һ��Ҳ��������\n";
  if(ob->query_int()<50)
  return "��ʩ������������ʯ�����޻۸�������Щ����ʲô���أ�\n";
  ob->set_temp("dtsl_quest_jzzy/step13",1);
   ob->delete_temp("dtsl_quest_jzzy/step12");
  return "�ⲻ����Ϊ�����ڲ���Ϊ���������ڶ���������������ʱ��Ȼ�����ñ��ġ�\n";
}

string do_quest4()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step13"))
   return "��˵��ʲô����ɮ����һ��Ҳ��������\n";
  ob->delete_temp("dtsl_quest_jzzy");
  ob->set("dtsl_quest_jzzy_ok",1);
  return "��ʩ����ô̹����ϣ�ȫ��̰��������ˣ����ڿ���֮��\n"+
         "�������С��ٶ��������������Ⱥ������������¹�ɲ��ǧ������ʮ������\n"+
         "��������ӡ������ڡ�����������ӡ���ڣ����ʩ����Ե�����в��²�\n"+
         "�������ģ�ȷΪ��������������ӡ��������ӡ����ʨ��ӡ����ʨ��\n"+
         "ӡ���⸿ӡ���ڸ�ӡ����ȭӡ������ӡ�ͱ�ƿӡ��\n";
}
