
inherit NPC;

void create()
{
   set_name("��˹����",({ "bosi shangren","shangren"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ�ڳ�����������Ĳ�˹���ˡ�\n");
       
   set("combat_exp", 200000);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say ����������������˳��������ƣ�");
     break;
    case 1:
     command("say ��ÿ�춼�����ϣ�������ܱ����ҡ�");
   }
   
}

