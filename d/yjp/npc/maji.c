// ����˫����


inherit NPC;

int do_action1();

void create()
{
  set_name("��", ({"ma ji", "ma", "ji"}));
  set("gender", "����");
  set("long","�����˳ơ����֡�������ר�����ߵ����⡣\n");
  set("age", 36);
  set("max_kee",400);
  set("max_gin",400);
  set("max_sen",400);
  set("max_force",400);
  set("force",400);
  set("combat_exp",600000);
 
  set_skill("force", 160);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("fengxue-leg",160);
  
  set("inquiry",([
    "�뼮":(:do_action1:),
    ]));
  setup();
  add_money("gold",3);
  
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("family")
    &&ob->query("family/family_name")!="�Ľ���"){
    command("say ���Ѿ����������ɵĵ����ˣ��޷������Ҹ������ˣ�");
    return 1;
  }
  if(ob->query("family")
    &&ob->query("family/family_name")=="�Ľ���"){
    command("say ���Ѿ����Ҹ����ĵ����ˣ���ȥѧϰ���հɣ�");
    return 1;
  }
  if(!ob->query_temp("bai_yjp_action2")){
    command("say ���Ϊ���������㻹���Զ�أ�");
    return 1;
  }
  ob->set_temp("bai_yjp_action3",1);
  ob->delete_temp("bai_yjp_action2");
  command("say ���ڵ���ս�ң���������ҿɲ�������������");
  command("grin "+ob->query("id"));
  return 1;
}

int accept_object(object ob,object who)
{
   if(!who->query("money_id")){
     return notify_fail("��ֻҪǮ�ģ����ʲôҲ��Ҫ��\n");
     
   }
   if(!ob->query_temp("bai_yjp_action3")){
     return notify_fail("û�������Ǯ��ʲô����Ҫ����\n");
    
   }
   if(who->value()<10000){
     return notify_fail("���ǮҲ̫���˰ɣ����Ҫ�����أ���\n");

   }
   ob->set_temp("bai_yjp_action4",1);
   ob->delete_temp("bai_yjp_action3");
   command("say �ðɣ������ȥ�Ҹ����Ŀ����ɣ�");
   return 1;
}