
inherit NPC;

void create()
{
   set_name("����",({ "shang ren","ren"}) );
   set("gender", "����" );
   set("age",30+random(40));
   set("long", "����һ�����ˣ��������ƴ����֡�\n");
       
   set("combat_exp", 200000);
   
   set("chat_chance",20);
   set("chat_msg",({
    "���˺Ǻ�һЦ����ר�ŷ�ս���ƣ��⼸����׬�˲��ٰ���\n",
    "���˵����˲�Ϊ���������������ͷ��˭����˭���ܻ���ȥ��\n",
    "������ĥ�����¸�����ƭ˭�أ��������뿴... ...\n",
    "������Ц����˭Ҫ����ɱ���ң����л����á��ͼ���񡹵ĳƺţ�����˭�ң�\n"+
    "�ҿ��ĸ��ң���\n",
   }));
   
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ�����̣������"+
      "���ͼ���񡹵ĳƺţ�\n");
     ob->set_temp("rank/class","�ͼ����");
   }
   
   return ::die();
   
}