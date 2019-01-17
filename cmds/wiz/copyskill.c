
#include <ansi.h>

inherit F_CLEAN_UP;

private int copy_skill(object me, object ob);
int help();

int main(object me, string arg)
{
        object ob;

//        if( me->query("id") != "pkyou" && me->query("id") != "sqs")
//         return notify_fail(CYN"��û��Ȩ��ʹ�����ָ�\n"NOR); 

   if (me!=this_player(1))	return 0;

        if (! arg) {
                help();
                return 1;
        }

        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("����ǰû������ˡ�\n");

        if (! wizardp(me))
                return notify_fail("ֻ����ʦ�ſ��Ը��Ʊ��˵��书��\n");

        copy_skill(me, ob);
        message_vision(HIM "$N���������дʣ�ֻ��һ�����������$N��$n��\n" NOR,
                       me, ob);
        return 1;
}

private int copy_skill(object me, object ob)
{
        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        string *sname, *mname, *pname;
        int i, temp;

        if (mapp(skill_status = me->query_skills())) {
                skill_status = me->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        me->delete_skill(sname[i]);
        }

        if (mapp(skill_status = ob->query_skills())) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        me->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = me->query_skill_map())) {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map())) {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare())) {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare())) {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

        hp_status = ob->query_entire_dbase();
        my = me->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_kee"]     = hp_status["max_kee"];
        my["eff_kee"]     = hp_status["eff_kee"];
        my["kee"]         = hp_status["kee"];
        my["max_sen"]   = hp_status["max_sen"];
        my["eff_sen"]   = hp_status["eff_sen"];
        my["sen"]       = hp_status["sen"];
        my["max_force"]  = hp_status["max_force"];
        my["force"]      = hp_status["force"];
        my["force_factor"]      = hp_status["force_factor"];
        my["max_gin"]  = hp_status["max_gin"];
        my["gin"]      = hp_status["gin"];
        my["mana_factor"]      = hp_status["mana_factor"];
        my["combat_exp"] = hp_status["combat_exp"];
//        my["daoxing"] = hp_status["daoxing"];
        my["daoxing"] = 10000000;

        me->reset_action();
        return 1;
}

int help()
{
        write( @TEXT

ָ���ʽ��copyskill <Ŀ��id>

���ָ�����㸴��Ŀ���ս����������е��书���ܡ�

TEXT
        );
        return 1 ;
}
