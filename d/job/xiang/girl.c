
inherit NPC;

string *name1=({
"��","��","��","��","Ǯ","��","��","��",
"��"});

void create()
{
   set_name(name1[random(sizeof(name1))]+"��С��",({ "girl" }) );
        set("gender", "Ů��" );
        set("con",1);
        set("age", 18);
   set("long", "����һλ����С�㡣\n"); 
   set("per", 25); 
   setup();
  
}

string *mesg=({
"������ȻһЦ��",
"����գ��գ�۾���",
"���ߵ������ܿ����˼��",
"���ߵص�����ͷ��"
});

string long()
{
   string msg;
   
   msg=query("name")+mesg[random(sizeof(mesg))]+"\n";
   return query("long")+msg;
}
   
   

//�����ά�� 300 ��
int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N̾����û��˼��ȥ��ط����ˡ�\n",this_object());
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
   
   if(clear())
   return 1;
   
   return ::chat();
}

int accept_fight(object who)
{
  return notify_fail(query("name")+"΢΢һЦ��СŮ�Ӳ����˴�ܵģ�\n");
}

void kill_ob(object ob)
{
   ob->remove_killer(this_object());
   message_vision("$N��$n������"+RANK_D->query_respect(ob)+"�ɱ������ˣ�\n",
   this_object(),ob);
   return;
}