
inherit NPC;

void create()
{
   set_name("����",({ "chang zhen","chang","zhen" }) );
        set("gender", "Ů��" );
        set("age",28);
        set("nickname","����");
   set("long", "�������˳�[����]�ĳ��档���Ƕ��ܹ���\n"+
               "���ǵĴ��۾��ֺ����������۵����Ϸ���\n"+
               "�����ĺ��Σ���˿��ϸü���۽ǳ�����б��\n"+
               "ȧ�߱�ͦ���ۺ���촽���������ѩ�����ݣ�\n"+
               "���˵��޹⣬��̫������ҫ�����ܡ�\n");
   set("class","bonze");    
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("cuff",80);
   set_skill("tianmo-huanzong",80);
   set_skill("linglong-yuquan",80);
   set_skill("tianmo-dafa",80);
   set("str",30);
   set("cor",30);
   set("max_gin",700);
   set("max_kee",700);
   set("max_sen",700);
   set("max_force",800);
   set("force",800);
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:"apply_action","linglong-yuquan",2,10:),
   	}));
   setup();   
}

