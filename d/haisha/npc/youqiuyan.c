
inherit NPC;

void create()
{
   set_name("������",({ "you qiuyan","you","qiuyan"}) );
        set("gender", "Ů��" );
        set("age", 32);
   set("long", "���Ǻ�ɳ��������㣬�������Ǻ�ɳ�������永������¡�\n");
       
   set("combat_exp",100000);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set("youqiuyan",1);
   set("shili",([
      "name":"haisha_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void revive()
{
   object ob;
   string msg;
   
   ::revive();
   
   if(!query("flag_ob"))
   return;
   ob=query("flag_ob");
   if(environment(this_object())!=environment(ob))
   return;
   
   msg="\n$N���˸����£�����Ť������������¶��ʹ��ı��飡\n\n"+
       "$N��$n���ĵ���"+RANK_D->query_respect(ob)+"����ͬ���������������ҽ�ҩ�ɣ�\n";
   msg +="\n$n���յ�һЦ������$Nһ����ҩ��\n\n";
   msg +="$N��æ���½�ҩ������ʹ�����ɫ������ʧ��\n\n";
   message_vision(msg,this_object(),ob);
   command("follow "+ob->query("id"));
   delete("flag_ob");
   return;
}
   
