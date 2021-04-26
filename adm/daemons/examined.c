// examined.c

// #pragma optimize
// #pragma save_binary

#include <localtime.h>
#include <message.h>

inherit F_DBASE;
inherit F_SAVE;

void create()
{
        seteuid(getuid());
        ::restore();
        set("channel_id", "��龫��");
}

string query_save_file()
{
        return DATA_DIR "examined";
}

void remove()
{
        save();
}

void examine_player(object ob)
{
        int exp;
        string log_msg;
        int tval;

        if (wizardp(ob)) return;

                if (! ob->is_loging_now())
                        ob->start_log();
}

string create_log_file(object ob)
{
        string fn;
        mixed lt;

        if (! userp(ob))
                return 0;

        lt = localtime(time());

        fn = "user/" + sprintf("%d-%d-%d/", lt[LT_YEAR],
                               lt[LT_MON] + 1, lt[LT_MDAY]) +
             ob->query("id");
        assure_file(LOG_DIR + fn);

        return fn;
}

int start_log_player(string id, string me)
{
        mixed by;
        object ob;


        by = query("log_by/" + id);
        if (stringp(by) && (wiz_level(by) > wiz_level(me)))
                return notify_fail("�Ѿ���Ȩ�ޱ���ߵ��˼�¼����ҵ���־�ˡ�\n");

        if (stringp(by) && by == me)
                return notify_fail("���Ѿ���ʼ��¼�����ҵ���־�ˡ�\n");

        ob = find_player(id);
        if (! by && ob && ob->is_loging_now() && wizhood(me) != "(boss)")
                return notify_fail("EXAMINE DAEMON ���ڼ�¼�����ҵ���־������Ȩ���档\n");

        if (wizhood(id) == "(admin)" &&
            (! this_player() || this_player()->query("env/boss")))
                return notify_fail("���ܼ�¼ boss ����־��\n");

        set("log_by/" + id, me);

        log_file("static/log_user", sprintf("%s start log %s on %s\n",
                                            me, id, ctime(time())));
        if (objectp(ob)) ob->start_log();
        save();

        return 1;
}

int end_log_player(string id, string euid)
{
        object ob;
        mixed by;


        ob = find_player(id);
        by = query("log_by/" + id);

        if (! by && (! ob || ! ob->is_loging_now()))
                return notify_fail("ϵͳ���ڲ�û�м�¼�����ҵ���־��\n");

        if (euid == ROOT_UID || wizhood(euid) == "(admin)" ||
            stringp(by) && (by == euid || wiz_level(by) <= wiz_level(euid)))
        {
                delete("log_by/" + id);
                log_file("static/log_user", sprintf("%s stop log %s on %s\n",
                                                    euid, id, ctime(time())));
                save();
                if (objectp(ob)) ob->end_log();
                return 1;
        }

        return notify_fail("�㲻�� ROOT ���ǿ�ʼ��¼��־����ʦ��������ֹ��¼��\n");
}

mixed query(string idx, int raw)
{

        return ::query(idx, raw);
}

mixed set(string idx, mixed data)
{

        return ::set(idx, data);
}
