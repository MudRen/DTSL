// ����˫����
//bing.c С��
 
inherit "/std/guard.c";

void create()
{
        set_name("С��", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "����");
        set("long","����һ������ʿ������Щʿ���������־�����ʿ���еľ���\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("combat_exp", 80000);
        set("max_kee", 400);
        set("max_mana", 200);
        set("max_sen", 400);
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 10);
        
        set("guard","gaoli");
        set_this_skills("middle");
        set_all_skill(this_object(),160);
        
        setup();
        
}
