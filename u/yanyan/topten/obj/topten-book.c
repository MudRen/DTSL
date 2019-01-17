//���а�

#include <ansi.h>

inherit ITEM;

mapping *exp_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *richman_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *oldman_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *force_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *literate_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *unarmed_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *dodge_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
});
mapping *thief_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *axe_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *blade_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *throwing_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *fork_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *hammer_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),
});
mapping *staff_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *sword_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});
mapping *whip_topten = 
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),
});

string *whichpart =
({
        BLU"��һ��    ʮ��������а�  --------------------  P1"NOR,
        BLU"�ڶ���    ʮ�������а�  --------------------  P2"NOR,
        BLU"������    ʮ���������а�  --------------------  P3"NOR,
        BLU"������    ����ڹ�����  ----------------------  P4"NOR,
        BLU"������    ����Ļ�����  ----------------------  P5"NOR,
        BLU"������    ������͵  --------------------------  P6"NOR,
        BLU"������    ���師  ----------------------------  P7"NOR,
        BLU"�ڰ���    ���ݵ���  --------------------------  P8"NOR,
        BLU"�ھ���    ��������  --------------------------  P9"NOR,
        BLU"��ʮ��    ���  ------------------------------  P10"NOR,
        BLU"��ʮһ��  �ȿ�  ------------------------------  P11"NOR,
        BLU"��ʮ����  �˴�  ----------------------------  P12"NOR,
        BLU"��ʮ����  ������  ----------------------------  P13"NOR,
        BLU"��ʮ����  ̽��ҹ��  --------------------------  P14"NOR,
        BLU"��ʮ����  ��ȭ�޵�  --------------------------  P15"NOR,
        BLU"��ʮ����  ̤ѩ�޺�  --------------------------  P16"NOR,
});
string printdate = NATURE_D->game_time();

void create()
{
        string id;
        int i,exp;

        set_name("���� ���а�", ({ "topten" }));
        set_weight(800);
        set("unit", "��");
        set("long","���Ǽ��ؽ�������������顣�������(READ)�����ġ�\n");
        set("value", 1600);
        set("material", "paper");
}

void init()
{
        object ob,me=this_object();

        seteuid(getuid());
        if( ob = new("/obj/magic-rice") )
                if( (exp_topten=ob->query( "exp_topten" ))
                        &&(richman_topten=ob->query("richman_topten"))
                        &&(oldman_topten=ob->query("oldman_topten"))
                        &&(force_topten=ob->query("force_topten"))
                        &&(unarmed_topten=ob->query("unarmed_topten"))
                        &&(dodge_topten=ob->query("dodge_topten"))
                        &&(literate_topten=ob->query("literate_topten"))
                        &&(thief_topten=ob->query("thief_topten"))
                        &&(axe_topten=ob->query("axe_topten"))
                        &&(blade_topten=ob->query("blade_topten"))
                        &&(throwing_topten=ob->query("throwing_topten"))
                        &&(fork_topten=ob->query("fork_topten"))
                        &&(hammer_topten=ob->query("hammer_topten"))
                        &&(staff_topten=ob->query("staff_topten"))
                        &&(sword_topten=ob->query("sword_topten"))
                        &&(whip_topten=ob->query("whip_topten")) )
                        destruct( ob );
                else
                        write(CYN"\n�������а�������⣡��֪ͨ����ִ����\n\n"NOR);
        else
                write(CYN"\n�������а�������⣡��֪ͨ����ִ����\n\n"NOR);

        add_action("do_read", "read");
}

int do_read( string arg )
{
        int i;
        string si;
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});

        switch( arg )
        {
                case "topten":
                case "�����˲����а�":
                        write( "�㷭�����������а񡷣�ֻ������д�ţ�\n" );
                        write( "--------------------------------------------------------\n" );
                        for( i = 0; i < sizeof(whichpart); i++ )
                                write( "    "+whichpart[i]+"\n" );
                        write( "--------------------------------------------------------\n" );
                        write( "                          ----"+printdate+"����\n" );
                        write( "��Ҫ�Ķ���һ�£�\n" );
                        break;
                case "P1":
                case "p1":
                case "��һ��":
                case "ʮ��������а�":
                        write( "�㷭����һ�� ��"+HIC"ʮ��������а�"NOR+"����ֻ������д�ţ�\n" );
                        write( "��������ʮ������������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( exp_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P2":
                case "p2":
                case "�ڶ���":
                case "ʮ�������а�":
                        write( "�㷭����һ�� ��"+HIC"ʮ�������а�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺�ʮ�����������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( richman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P3":
                case "p3":
                case "������":
                case "ʮ���������а�":
                        write( "�㷭�������� ��"+HIC"ʮ���������а�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( oldman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P4":
                case "p4":
                case "������":
                case "����ڹ�����":
                        write( "�㷭�������� ��"+HIC"����ڹ�����"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( force_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P5":
                case "p5":
                case "������":
                case "����Ļ�����":
                        write( "�㷭�������� ��"+HIC"����Ļ�����"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( literate_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P6":
                case "p6":
                case "������":
                case "������͵":
                        write( "�㷭�������� ��"+HIC"������͵"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( thief_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P7":
                case "p7":
                case "������":
                case "���師":
                        write( "�㷭�������� ��"+HIC"���師"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( axe_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P8":
                case "p8":
                case "�ڰ���":
                case "���ݵ���":
                        write( "�㷭���ڰ��� ��"+HIC"���ݵ���"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( blade_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P9":
                case "p9":
                case "�ھ���":
                case "��������":
                        write( "�㷭���ھ��� ��"+HIC"��������"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( throwing_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P10":
                case "p10":
                case "��ʮ��":
                case "���":
                        write( "�㷭����ʮ�� ��"+HIC"���"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( whip_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P11":
                case "p11":
                case "��ʮһ��":
                case "�ȿ�":
                        write( "�㷭����ʮһ�� ��"+HIC"�ȿ�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( staff_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P12":
                case "p12":
                case "��ʮ����":
                case "�˴�":
                        write( "�㷭����ʮ���� ��"+HIC"�˴�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 8; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( hammer_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P13":
                case "p13":
                case "��ʮ����":
                case "������":
                        write( "�㷭����ʮ���� ��"+HIC"������"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( sword_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P14":
                case "p14":
                case "��ʮ����":
                case "̽��ҹ��":
                        write( "�㷭����ʮ���� ��"+HIC"̽��ҹ��"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( fork_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P15":
                case "p15":
                case "��ʮ����":
                case "��ȭ�޵�":
                        write( "�㷭����ʮ���� ��"+HIC"��ȭ�޵�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )

                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( unarmed_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "P16":
                case "p16":
                case "��ʮ����":
                case "̤ѩ�޺�":
                        write( "�㷭����ʮ���� ��"+HIC"̤ѩ�޺�"NOR+"����ֻ������д�ţ�\n" );
                        write( "���񽭺��������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( dodge_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
		   default:
                        return 0;
        }
        return 1;
}

