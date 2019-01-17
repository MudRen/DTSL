
inherit NPC;

int change_name();

void create()
{
   set_name("��ͨ",({ "wang tong","wang","tong" }) );
   set("title","��������");
   set("gender", "����" );
   set("age", 48);
   set("long", "��ǰ����λ����������������˪���ޣ�ʹ��֪������Ͷ��Ȳ��٣�
����òֻ������ģ������һ�����ŷ�������̬Ʈ�ݣ�����һ�ֳ���
���׵ĸо���\n");
   set("combat_exp",60000);
   
   set("inquiry",([
     "����":(:change_name:),
   
   ]));
  
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   
}

void init()
{
 
   add_action("do_change","zhuanhuan");
  
}

int change_name()
{
   object ob;
   int cost;
   
   ob=this_player();
   
   if(time()-ob->query("change_name/busy_time")<3600*10){
     command("say �����Ƶ���ظĶ��Լ������֣�������������������Ŀ��֣�");
     return 1;
   }
   cost=1000000+ob->query("change_name/times")*1000000;
   
   cost=MONEY_D->player_pay(ob,cost);
   
   if(cost==0||cost==2){
     command("say ��Ҫ�����������ʧ���������գ�������һ���Ǯ�ǲ��еģ�\n");
     return 1;
   }
   
   ob->set_temp("can_change_name",1);
   
   command("say ������ zhuanhuan ������ �������Լ������ְɣ�\n");
   
   return 1;
   
}

int do_change(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("can_change_name"))
   return notify_fail("��Ҫ�����������ʧ���������գ�������һ���Ǯ�ǲ��еģ�\n");
  
  if(!arg)
  return notify_fail("�����������ʲô��\n");
  
  if(!LOGIN_D->check_legal_name(arg)){
    command("say ��ʹ�úϺ����������ص����ְɣ�\n");
    return 1;
  }
  
  command("rumor "+ob->name()+"����˴ӽ�������ʧ�ˣ�����������һ������"+arg+"���ˣ�");
  
  tell_object(ob,"����������ǡ�"+arg+"��\n");
  
  ob->set("name",arg);
  
  ob->delete_temp("can_change_name");
  ob->add("change_name/times",1);
  ob->set("change_name/busy_time",time());
  
  return 1;
  
}
