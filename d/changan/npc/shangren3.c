
inherit NPC;

void create()
{
   set_name("����",({ "yan shang","yan","shang"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ���̡�\n");
       
   set("combat_exp", 300000);
   
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
     command("say ���ǿ��̫�࣬���ⲻ�����˰���");
     break;
    case 1:
     command("say ���ó����ΰ�������Ȼ����������ô�");
   }
   
}

