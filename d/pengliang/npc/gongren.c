
inherit NPC;

void create()
{
   set_name("��",({ "min gong","gong" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����һ���񹤡�\n");
       
   set("combat_exp",200000);
 
   setup();
 
}

void init()
{
  object ob;
  
  ob=this_player();
  
  if(!ob||is_fighting()) return;
  
  remove_call_out("welcome");
  call_out("welcome",1,ob);
  
}

void welcome(object ob)
{
  if(!ob||environment(ob)!=environment(this_object())) return;
  
  switch(random(2)){
   case 0:
    command("say ����Ҫ�������̵��������ػ���˧����");
    break;
   case 1:
    command("say �Ҽ�����˧���������£�");
  }
  
}