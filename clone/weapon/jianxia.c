//ҹ��<<����>>�и�
// jianxia.c ������֮��ϻ
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��ϻ",({ "jian xia", "jianxia", "xia", "box" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "wood");
                set("long", "���Ǻ�ɫ�Ľ�ϻ,������,һ�ɺ����������ܡ�\n");
                 }
        setup();
}
void init()
{
       add_action("do_break", "break");
       add_action("do_break", "zhen");
       add_action("do_break", "sui");
       add_action("do_break", "posui");
}

int do_break(string arg)
{
        object me,ob;
        me = this_player();
               
       if (!(arg=="xia" || arg == "jian xia" || arg == "jianxia" || arg == "box"))
       return 0;

if( (int)me->query("max_neili") < 3000)
		        {
                       write("������̫���޷������񽣡�\n");
			return 1;
				}
       
        if( (int)me->query_skill("sword", 1) < 180)
		        {
              write("�㽣������̫��,�޷�ʹ�þ����ý���\n");
                 return 1;
				}
      
message_vision(HIY   "$Nһ�ѽ��Լ����ŵĽ�ϻ���ز��ڵ��ϣ���ϻ��ʱӦ���ƿ������ˡ���һ��,һ����â�������,\n"+
                                    "һ���񽣻�������,��ϻ �ڵ��񽣣���Ȼ�޷����ʣ�\n"+
                                    "ֻ  ��   ��    ��    ��   ��   ��   ��   ��\n"+
                                     "�������ڽ�ϻ�ƿ�֮ʱ����$N����ٱ�����𱬣���Ϊ���飡\n"+
                                    "һ�������޵е������񽣣��˿�����$N�����ϣ���\n" NOR, me);
            ob=new("/clone/weapon/tianlong-shenjian");
            ob->move(me);
            ob->wield();
            destruct(this_object());
            return 1;
}
