// ����˫����


inherit NPC;

int do_action1();

void create()
{
  set_name("�ذ����", ({"tuoba miefu", "tuoba", "miefu"}));
  set("gender", "����");
  set("long","���Ǹ������ذ����ר��Ϊ�����������ˡ�\n");
  set("age", 36);
  set("max_kee",400);
  set("max_gin",400);
  set("max_sen",400);
  set("max_force",400);
  set("force",400);
  set("combat_exp",4000);
 
  set_skill("force", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  
  set("target_id","###");
  
  set("inquiry",([
    "�뼮":(:do_action1:),
    ]));
  setup();
  
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
  ob->set_temp("bai_yjp_action1",1);
  command("say ����ֻ��ӭ���ո�ǿ�������������ܴ���ң��Ҿ����ϼ��Ƽ��㡣");
  return 1;
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("bai_yjp_action1"))
   return 1;
   killer->set_temp("bai_yjp_action2",1);
   killer->delete_temp("bai_yjp_action1");
   command("say "+RANK_D->query_respect(killer)+"��Ȼ����������ȥ���ҵ���˾��ȥ�����ɣ�");
   return 1;
}