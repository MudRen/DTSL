// ����˫����


inherit NPC;

void create()
{
  set_name("����", ({"zhang guan","guan"}));
  set("long","���ǳ���������ĳ��١�\n");
  set("gender", "����");
  set("combat_exp",200000);

  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  
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
     command("say ˭���Լ�ð�棬�������죬�̽������ߣ���һ���ϳͣ���");
     break;
    case 1:
     command("say �Ұ��¾��Թ�������ʲô��ƽ���µ���������˵�ͺ��ˡ�");
   }
   
}
