
inherit NPC;

string *names=({
"��","jing",
"��","nian",
"��","kong",
"Ե","yuan",
"��","wu",
"��","zhi",
"��","hui",
"��","ming",
"��","yu",
});

int do_jiangjing(string arg);
int do_hua(string arg);

void create()
{
   int i,j;
   i=random(sizeof(names));
   
   if(i%2!=0) i--;
   j=i+1;
   
   set_name("��"+names[i],({ "xu"+" "+names[j],"xu",names[j] }));
   set("gender", "����" );
   set("class","bonze");
   set("long","���Ǿ�����Ժ���ӣ������߻���ħ�ˡ�");
   set("combat_exp",50000);
  setup();
  
}

void init()
{
   object ob;
   
   add_action("do_jiangjing","jiangjing");
   add_action("do_hua","hua");
   
   ob=previous_object();
   if(!ob||!living(ob)||!userp(ob)||
      query("target_id")!=ob->query("id")) return;
   if(query("target_id")==ob->query("id"))
    call_out("show_msg1",1,ob);
}

void show_msg1(object ob)
{
   string msg;
   
   if(!ob||!living(ob)) return;
   
   msg="\n$N��$n�Ǻ�ɵЦ�˼�����\n";
   message_vision(msg,this_object(),ob);
}

int do_jiangjing(string arg)
{
  object ob,obj;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("��Ҫ��˭������\n");
  
  if(!objectp(obj=present(arg,environment(ob))))
  return notify_fail("����û������ˡ�\n");
  if(obj->query("target_id")!=ob->query("id"))
  return notify_fail("�Է��ɲ����������\n");
  
  msg="\n$N��$n���˼��侭�ģ�$nһ����ͻȻ�����㵸��״�Ʒ�񲣡\n";
  msg +="\n������һ�����͵ؼ���ʦ������˵�������ȭ�ľ�������\n"+
        "����������������ʱ�ɻ�$n����(hua)�����������߻���ħ֮�ѣ�\n\n";
  message_vision(msg,ob,obj);
  set("crazy",1);
  call_out("do_destruct",15);
  return 1;
}

int do_hua(string arg)
{
  object ob,obj;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("��Ҫ��˭��������\n");
  
  if(!objectp(obj=present(arg,environment(ob))))
  return notify_fail("����û������ˡ�\n");
  if(obj->query("target_id")!=ob->query("id"))
  return notify_fail("�㲻�ܻ��Է���������\n");
  if(!obj->query("crazy"))
  return notify_fail("��û�з�񲣬û��Ҫ��������\n");
  
  msg="\n$N����˫ȭ���������ȭ��������$n������ȥ��\n"+
      "$n�پ�����ȫʧ��$NҲ���û�����������ȫ�ޡ�\n\n"+
      "$n����������������̨��������$Nһʩ�񣺶�л"+RANK_D->query_respect(ob)+"����һ����\n\n"+
      "$N��ͷ��˼һ�ᣬ���������ȭ�ľ���֮����\n\n";
  message_vision(msg,ob,obj);
  ob->set("perform_quest/tiangang",1);
  ob->set("force",0);
  set("last",0);
  return 1;
}

void do_destruct()
{
  string msg;
  
  if(!query("crazy"))
   return;
  msg="$N��ͷ����һЦ������񲳯Զ�����ˡ�\n";
  message_vision(msg,this_object());
  destruct(this_object());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   object ob;
   if(clear())
   return 1;
   
   return ::chat();
}
