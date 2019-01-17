
inherit NPC;

void create()
{
   set_name("¶À¹ÂÐÛ",({ "dugu xiong","dugu","xiong" }) );
        set("gender", "ÄÐÐÔ" );
        set("age", 32);
        set("tetle","ÓùÇ°ÊÌÎÀ");
   set("long", "ËûÊÇ¶À¹Â·§µÄ¸ßÊÖ¶À¹ÂÐÛ£¬ÊÇËå³¯µÄÓùÇ°ÊÌÎÀ¡£\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   set_skill("sword",120);
   set_skill("cuff",120);
   set_skill("dugu-jianfa",120);
   set_skill("youming-zhang",120);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/sword")->wield();
}

