
inherit NPC;

int do_quest1();
int do_quest2();

void create()
{
   set_name("������",({ "han zenan","han"}) );
        set("gender", "����" );
		
        set("age", 25);
   set("long", "���Ǻ�С�ѵ��ɷ�\n");
       
   set("combat_exp",50000);
   
   set("inquiry",([
     "С��":(:do_quest1:),
     "����":(:do_quest2:),
     ]));
   
   setup();
  
}

int do_quest1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/hong_step1")){
     command("say ��˵ʲô�أ��ҿ���ʲôҲ��֪����\n");
     return 1;
   }
   
   ob->delete_temp("tmz_quest/hong_step1");
   ob->set_temp("tmz_quest/hong_step2",1);
   
   command("fear");
   command("say ��...��...����˭����ô֪���Һ�С�ѵĺ��ӵ����֣�");
   command("say ��λ"+RANK_D->query_respect(ob)+"���������̨���֣�\n"+
           "�Ź����ǰɣ�\n");
   return 1;
} 

int do_quest2()
{
   object ob,obj;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/hong_step2")){
     command("say ��˵ʲô�أ��ҿ���ʲôҲ��֪����\n");
     return 1;
   }
   msg="$N������������������ɵ��ӣ���Ҳ���Ǻ������ԣ�\n"+
       "ֻҪ���Ǹ��ҡ���ħ�󡹵��鼮������Ȼ��Ź����ǣ�\n";
   message_vision(msg,ob);
   msg="$N���˵�˵������лл��λ"+RANK_D->query_respect(ob)+"�ˣ�\n";
   message_vision(msg,this_object());
   
   obj=new(__DIR__"obj/xinwu");
   obj->move(ob);
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
              obj->query("name")+"��\n");
   return 1;
}