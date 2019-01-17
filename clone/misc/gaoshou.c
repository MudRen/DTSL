// by smallfish

#include <ansi.h>
inherit NPC;

#define GAOSHOU_DIR "/data/gaoshou/"

void init_npc();
int is_c_file(string arg);              //�ж�arg�Ƿ�*.c�ļ���ʽ
// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
        string id;

        id = query("id");
        if (! stringp(id)) return 0;
        return sprintf(GAOSHOU_DIR "npc/%s", id);
}

int save()
{
        return 0;
}

int restore()
{
        string file;

        if (stringp(file = this_object()->query_save_file()))
                return restore_object(file);
        return 0;
}

void create()
{
        string id;

        ::create();
        id = COMPETE_D->query_top_id();
        set_name( "�Ĵ���ɮ" , ({ id }) );
        setup();        

        restore();
        call_out("init_npc", 2);
}

void init_npc()
{
        object me, cloth, weapon;
        mapping summon_ob;
        string *carry_ob, *summon_key, weapon_file;
        int i;

        me = this_object();

        if (mapp(summon_ob = me->query("can_summon")) && sizeof(summon_ob))
        {
                summon_key = keys(summon_ob);
                for(i = 0;i < sizeof(summon_key);i++)
                {
                        if (! stringp(weapon_file = summon_ob[summon_key[i]]))
                                continue;
                        if (file_size(weapon_file) < 0)
                                continue;
                        call_other(weapon_file, "???");
                        weapon = find_object(weapon_file);
                        if (! weapon || ! weapon->receive_summon(me))
                        {
                               message_vision(HIM "$N" HIM "��������������������"
                                       "�ʡ�\nȻ��ʲôҲû�з��� :)\n", me);
                        } else
                               weapon->set("value", 0);
                }
        }
        if (arrayp(carry_ob = me->query("carry_ob")) && sizeof(carry_ob))
        {
                for(i = 0;i < sizeof(carry_ob);i++)
                {
                        if (objectp(cloth = new(carry_ob[i])))
                        {
                                cloth->move(me);
                                cloth->set("value",0);
                        }
                }
        }
        command("wear all");
        command("wield all");

}

void kill_ob(object ob) 
{
        {
                ::kill_ob(ob);
                start_busy(0);
                return;
        }
        return ::kill_ob(ob);
}
              
int is_c_file(string arg)               //�ж�arg�Ƿ�*.c�ļ���ʽ
{
        int l;
        l = strlen(arg);
        if (arg[l - 1] == 'c' && arg[l - 2] == '.')
                return 1;
        return 0;
}



