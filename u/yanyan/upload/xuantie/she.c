
inherit NPC;

void create()
{
   set_name("������",({ "she"}) );
        set("race", "Ұ��" );
     set("long", "����һ���޶����ߡ�\n");
	 set("verbs",({"bite"}));
     set("limbs",({"ͷ","β��","�ߴ�"}));
     set("combat_exp",500000);
     set("max_gin",1000);
     set("max_kee",1000);
     set("max_sen",1000);
     set("cor",28);
     set("str",30);
     set_skill("snake_bite_poison",150);
     set_skill("snake_dodge",150);
     set_skill("dodge",150);
     set("chat_chance_combat",60);
     set("chat_msg_combat",({
     (:apply_action,"snake_bite_poison",1,8:),
     (:apply_action,"snake_bite_poison",2,8:),
     }));
  setup();

}

