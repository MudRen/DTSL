// write by huarong 
// ��ѯ����player��ip����
#include <ansi.h>
int help(object me);
int main(object me, string name)
{       
        object ob; 
        string ip;
        if( !name) return help(me);
        seteuid(getuid());
        if(!ob=find_player(name))
              return notify_fail("û�������ҡ�\n");
        ip = query_ip_number(ob);
        write("\n"+HIY+ob->name(1)+NOR+"IP״̬���£�\n"NOR);
        write(HIY+"IP��ַ��"+HIR+ip+NOR+"����"+HIG+IP_D->seek_ip_address(ip)+"\n");
        write("\n");
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��ipname <id>
�쿴ĳ�����IP��ַ�Լ���ϸ�ص㡣
HELP
        );
    return 1;
}

