
inherit NPC;

void create()
{
   set_name("���",({ "huo ji","huo","ji"}) );
        set("gender", "����" );
        set("age", 20+random(10));
		
   set("long", "���ǲ÷��Ļ�ơ�\n");
       
   set("combat_exp", 50000);
   
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  
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
      command("say ��ӭ���٣�С��ķ�װ�ɶ����ṩ���ʹ������õ�Ŷ��");
      break;
     case 1:
      command("say ����������·��ֹ��ϳˣ��������⣡");
   }
   
}