
#include <ansi.h>

inherit NPC;

int do_action1();
int do_action2();

void create()
{
   set_name("֣ʯ��",({ "zheng shiru","zheng"}) );
        set("gender", "����" );
	set("title","���Ͽ�ʿ");
        set("age",32);
   set("long", "�������˳ơ����Ͽ�ʿ����֣ʯ�硣\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 25);
  
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",150);
   set_skill("sword",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-huanzong",130);
   set_skill("jiutian-huanzhang",130);
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   
   set("inquiry",([
     "������":(:do_action1:),
     "��ʦ":(:do_action2:),
     ]));
  
   setup();
  
}


int do_action1()
{
    object ob,heart;
    
    ob=this_player();
    
    if(ob->query("family")){
      if(ob->query("family/family_name")!="������"){
        command("kok "+ob->query("id"));
        command("say �������˽�������֮�ɣ������ⶼ��֪������\n");
        return 1;
      }
      
      command("hi "+ob->query("id"));
      command("say ԭ���������ɵ��ˣ�������������\n");
      return 1;
   }
   
   if(ob->query("no_family")){
    command("say ���Ѿ�����Ͷ�뵽�κ�����֮���ˣ�������������ʲô��\n");
    return 1;
   }
   
   if(present("heart",ob)){
     command("kao1 "+ob->query("id"));
     command("say �㵱���������𣿣���������İ���������ֻ���Һ��ٵģ���\n");
     return 1;
   }
   
   heart=new(__DIR__"obj/heart");
   heart->move(ob);
   tell_object(ob,query("name")+"������һ"+heart->query("unit")+heart->query("name")+"\n");
   command("whisper "+ob->query("id")+" Ҫ�������ɱ����ȡ���ħ�ġ���\n"+
           "�������Ҳ��ҳ��أ�\n");
   return 1;
}

int do_action2()
{
    object ob,obj;
    
    ob=this_player();
    
    if(!ob->query_temp("bai_yingui/step1")){
     command("heihei");
     command("say ��Ȼ�Ҳ����������յ��ӣ���Ҳ֪��Ҫ�������ɣ�Ҫ��һЩ�µģ�");
     return 1;
    }
    
    if(present("yinguibaishimihan",ob)){
     command("say ���Ѿ������ܺ��ˣ�������г��⣬��ȥ��ʦ�ɣ�");
     return 1;
    }
    
    obj=new(__DIR__"obj/mihan");
    obj->move(ob);
    
    command("say �ã�"+RANK_D->query_respect(ob)+"����������");
    command("whisper "+ob->query("id")+" �Ҹ�����ţ���ȥ����ʿ���÷��ʦ�ɣ�");
    return 1;
}