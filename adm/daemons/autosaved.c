
#include <ansi.h>

inherit F_DBASE;

void auto_save();
 
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���̾���(AutoSave)");
        CHANNEL_D->do_channel( this_object(), "sys", "\n�Զ������Ѿ�������\n\n");
        call_out("auto_save", 24);
}

void auto_save()
{
        int i;
        object *ob, link_ob;
        string id;

        seteuid(getuid());
        ob=users();
        for( i=0;i<sizeof(ob);i++) {
                id = (string) ob[i]->query("id");
                if (!id) continue;
                if(!environment(ob[i]) )        continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                if( (int)link_ob->save() && (int)ob[i]->save() ) {
                      if (!(ob[i]->query("env/blk_autosave")))
                              tell_object(ob[i], "���ĵ����Ѿ��Զ�������ϡ�\n");
                                
                }
                else
                        tell_object(ob[i], RED"���ĵ����Զ�����ʧ�ܡ�\n"NOR);
        }
        remove_call_out("auto_save");
        call_out("auto_save", 300+random(120));
}
