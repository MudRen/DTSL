
inherit NPC;

int do_action1()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say ��ľ���̫���ˣ����Ѿ������ٰ����ˡ�");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say Ŀǰû�л����ˣ����һ�������ɣ�\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say ��һ����һ���Ϳ����ˣ�\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say ��ѧ�������ķ���ҲҪ����ѧ�Ѱɣ�");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/mukuai");   
   target->move(ob);
   command("say �����������õĶ����������ƴװ��ľͷ����������");
   return 1;
}

int do_action2()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say ��ľ���̫���ˣ����Ѿ������ٰ����ˡ�");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say Ŀǰû�л����ˣ����һ�������ɣ�\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say ��һ����һ���Ϳ����ˣ�\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say ��ѧ�������ķ���ҲҪ����ѧ�Ѱɣ�");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/tiekuai");   
   target->move(ob);
   command("say �����������õĶ����������ƴװ�����޺���������");
   return 1;
}

int do_action3()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say ��ľ���̫���ˣ����Ѿ������ٰ����ˡ�");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say Ŀǰû�л����ˣ����һ�������ɣ�\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say ��һ����һ���Ϳ����ˣ�\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say ��ѧ�������ķ���ҲҪ����ѧ�Ѱɣ�");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/pinang");   
   target->move(ob);
   command("say �����������õĶ����������ƴװ��Ƥ������������");
   return 1;
}