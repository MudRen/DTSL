// #pragma optimize
// #pragma save_binary
#include <ansi.h>
inherit F_DBASE;

void create()
{
    seteuid(ROOT_UID);
    set("name", HIR "ϵͳ����" NOR);
    set("channel_id", "ϵͳ����");
    CHANNEL_D->do_channel(this_object(), "sys", "\n��������Ѿ�������\n");
    call_out("auto_clear", 30);
}

void auto_clear()
{
    CHANNEL_D->do_channel(this_object(), "sys", HIY "������������С�\n" NOR);
    cp("/log/usage", "/log/usage_log/usage_" + time());
    rm("/log/usage");
    cp("/log/debug.log", "/drive/debug" + time() + ".log"); //����debug.logΪsysterm.logΪ������
    rm("/log/debug.log");
    remove_call_out("auto_clear");
    call_out("auto_clear", 86400); //ÿ������һ��
}
