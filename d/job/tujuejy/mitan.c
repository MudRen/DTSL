
inherit NPC;


void create()
{
   set_name("��̽",({ "mi tan","mi","tan" }) );
        set("gender", "����" );
        set("con",30);
        set("age", 20+random(20));
   set("long", "����ͻ�ʵ���ԭ����̽����̽��\n"); 
   
   setup();
  
}


//�����ά�� 300 ��
int clear()
{
  if(time()-query("last")<1000)
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

int check_flag=0;

int chat()
{
   object ob;
   
   if(clear())
   return 1;
   
   ob=query_leader();
   
   check_flag++;
   
   if(ob&&check_flag>=6&&environment(ob)!=environment(this_object())){
     check_flag=0;
     move(environment(ob));}
   
   return ::chat();
}
