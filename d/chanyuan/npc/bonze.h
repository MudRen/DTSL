
int do_action2()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������Ժ"){
     command("say �㲻�Ǳ��ɵ��ӣ��������������ʲô��");
     return 1;
   }
   if(ob->query("class")!="bonze"){
     command("say �㻹���ȳ�����˵�ɡ�");
     return 1;
   }
   
   if(ob->query("PKS")>=5){
     command("say ���������أ���������������⣿");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say ��ɱ�����أ���������������⣿");
     return 1;
   }
   if(ob->query("family/generation")<=5){
     command("say ������˵Ц��");
     return 1;
   }
   if(ob->query("family/generation")>6){
     command("say ��ı���̫���ˡ�");
     return 1;
   }
   if(ob->query_skill("wuxiang-shengong",1)<150){
     command("say �����������Ϊ̫���ˣ�");
     return 1;
   }
   if(time()-ob->query("mud_flags/try_beifen_time")<300){
     command("say �����˵�������˲��ɸ��꣬��ô��ô��������ˣ�");
     return 1;
   }
   
   ob->delete("mud_flags/try_beifen_time");
   msg="$N��$nһЦ���ã������ҿ�����Ĺ�������ˣ�\n";
   message_vision(msg,this_object(),ob);
   
   ob->set_temp("try_beifen",1);
   fight_ob(ob);
   return 1;
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

int surrender(object killer,object victim)
{
   string msg,newname;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N��$nһ��ʮ����������ţ������ӷ𣡿������ȷ�ǽ�����һ��������\n"+
          "�Ժ�����Ǳ��ɡ������ֱ������ˣ�\n\n";
      message_vision(msg,victim,killer);
      newname=killer->query("name");
      newname=no_color(newname);
      newname="��"+newname[2..3];
      killer->set("name",newname);
      tell_object(killer,HIY"�Ժ���������ǡ�"+newname+"��\n���Ϊ�˾�����Ժ��������ӡ�\n\n"NOR);
      killer->set("family/generation",5);
      killer->delete_temp("try_beifen");
   }
   return 1;
}

int end_fight(object killer,object victim)
{
     string msg;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N��$n����һ����˵�������������мǲ����ḡ�������ɵ�һ�������һ���ӡ�\n"+
      "����Ŭ���ɣ���\n\n";
      message_vision(msg,killer,victim);     
      killer->delete_temp("try_beifen");
      killer->set("mud_flags/try_beifen_time",time());
   }
   return 1;
}	

