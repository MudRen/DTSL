// Update by waiwai@2003/04/09

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string f;

        if( !arg ) return notify_fail("ָ���ʽ��which <ָ��>\n");

        if( f = me->find_command(arg) ) {
                write(f + "\n");
                return 1;       
        }
        write("���ָ��·����û�����ָ������� localcmds ���ָ�\n");
        return 1;
}

     
