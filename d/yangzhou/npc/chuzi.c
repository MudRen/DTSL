
inherit NPC;

#include <ansi.h>

int give_food();

void create()
{
   set_name("����",({ "chu zi","chu","zi"}) );
        set("gender", "����" );
        set("age", 32);
        set("target_id","####");
        set("long","���ǻ�����Ӷ�ĳ��ӡ���������Щ��\n");
        
        set("inquiry",([
          "ʳ��":(:give_food:),
          "food":(:give_food:),
          "ˮ":"�����ֱ�� drink ��\n",
          "water":"�����ֱ�� drink ��\n",
          "��":"û�취�������﹤���ۣ����ܲ���ô��\n",
          ]));
    setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
   
}
/*
void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   
     command("bow "+ob->query("id"));
   
    tell_object(ob,"���ӳ���Ц�����������Զ������� "+HBMAG+HIW+"ask chu about ʳ��"+NOR+"��\n");
    tell_object(ob,"���ӳ���Ц������������ˮ���� "+HBMAG+HIW+"drink"+NOR+"��\n");
    
   
  return;
}
*/
int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}

int give_food()
{
   object ob,food;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000){
   command("say ����ô�߾��黹��ƭ��ƭ�ȣ�����������");
   return 1;}
   
   if(present("mantou",ob)){
   
   command("kok "+ob->query("id"));
   command("say ��������Ҫ�ɣ�");
   return 1;}
   
   food=new(__DIR__"obj/food");
   food->move(ob);
   
   tell_object(ob,"���Ӹ�����һ"+food->query("unit")+food->query("name")+"��\n");
   
   return 1;
}
   
