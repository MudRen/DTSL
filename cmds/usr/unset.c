// unset.c
// by lanxin opren combat message
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        if( !arg || arg=="" ) return help();

        if(arg == "mute") 
                me->delete_temp("mute");

        else
                me->delete("env/" + arg);
        write("Ok.\n");
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��unset <������>

���ָ������ɾ�������������趨��

�޸ı����趨���� unset ָ�
TEXT
        );
        return 1;
}