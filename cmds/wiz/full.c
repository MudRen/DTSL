//By MHSJ 2001/1/7

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object ob,string arg)
{
        object me,obj;
        int jin, qi, neili, fali, shiwu, yinshui;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("��Ҫ�ָ�˭��״̬��\n");
      }
		log_file("static/full",
			sprintf("%s(%s) full %s(%s) ʱ�� %s\n",
				ob->name(1), geteuid(ob), me->name(1), geteuid(me),ctime(time()) ) );
	        if (!wizardp(me)){
	message("war",HIM"���� ������"+"��˵"+ob->query("name")+"�ָ��� "HIW+me->query("name")+HIR" �ĸ������塣\n"NOR,users());
	        }

        jin = me->query("max_sen");
        qi =me->query("max_kee");
        fali = me->query("max_mana");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        me->set("eff_sen", jin);
        me->set("eff_kee", qi);
        me->set("sen", jin);
        me->set("kee", qi);
        me->set("mana", neili*2);
        me->set("force", neili*2);
        me->set("food", shiwu);
        me->set("water", yinshui);
write(HIY"�����������������ѽ�����һظ��������ɣ�����\n"NOR);
tell_object(me,HIW"��ͻȻ��һ������Χ������ȫ���������������\n"NOR);

        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : full

��ָ�������ָ����еľ�����
HELP
    );
    return 1;
}
