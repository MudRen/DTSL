// ����˫����
//bing.c С��
 
inherit "/std/guard.c";

void create()
{
        set_name("С��", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "����");
        set("long","����һ��ʿ������Щʿ���������־�����ʿ���еľ���\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("combat_exp", 800000);
        
        set("guard","liyang");
        
        set_this_skills("high");
        set_all_skill(this_object(),180);

        setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
      
}
