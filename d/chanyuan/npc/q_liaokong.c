
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("ľ��",({ "mu ren","ren"}));
        set("gender", "����" );
     
   set("class","bonze"); 
   set("combat_exp",1000000);
   
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("staff",200);
    set_skill("cuff",200);
    set_skill("finger",200);
    set_skill("strike",200);

    set_skill("tiangang-quan",200);
    set_skill("fumo-zhangfa",200);
    set_skill("dujie-zhi",200);
    set_skill("rulai-shenzhang",200);
    set_skill("lianhua-step",200);

    set_skill("literate",200);
    set_skill("chanzong-fofa",200);
    set_skill("wuxiang-shengong",200);
    set_skill("bikouchan",200);

    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);

   setup();
  
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
   object ob;
   string newname;
   
   if(!killer->query_temp("gage_liaokong")){
    destruct(this_object());
    return 1;
   }
   message("vision",HIG"��������Ժ��:"+killer->name()+HIG+"��������Ժ�ķ��飬�������������ӷ𡱣�\n"NOR,users());
   
   newname=killer->query("name");
   newname=no_color(newname);
   newname="��"+newname[2..3];
   killer->set("name",newname);
   killer->set("family/generation",3);
   tell_object(killer,HIY"��������Ժ���"+newname+"�����Ϊ����Ժ���������ӣ�\n"NOR);
   killer->reward_family_point();
   
   tell_object(killer,"ľͷ�˿���һ���ѳ�����Ƭ��\n");
   tell_object(killer,"��ľͷ���������һ��������\n");
   ob=new("/d/clone/room/lingwu/chanyuan/key");
   ob->move(killer);
   killer->set("family_lingwu","chanyuan");
   killer->set("title","����ʥɮ");
   tell_object(killer,"�������һ���ƽ�Կ�ס�\n");
   destruct(this_object());
   return 1;
}
