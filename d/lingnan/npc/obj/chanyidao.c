
//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(BLU"�쵶"NOR, ({ "tian dao","blade","dao" }) );
   set_weight(40000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 500000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", BLU"ʲô�������������������У��������޺�����ʲô�����������˵�����\n"+
                    "��δ��һ�ܣ�ʲô�������԰������¸�����ƽ�룿�Ǿ��������о�����\n"+
                    "���쵶��ȱ���õġ��쵶���˵��������꣬�������࣬���쵶��ȱ����\n"+
                    "��ɺ���֣�������Ϊ��ȱ�Լ����죬Ҳ���˴Ӵ˵��ش�ٽ��ʵ��\n"+
                    "������ƶϴ˵�ӦΪ�Ϲű��������Σ����񼹣�������ͷ�����У�\n"+
                    "��һ��ı������������ֳ���˧���ٵı��������¿�������⣬ֻ��һ\n�Ѷ��ѡ�\n"NOR);
     set("wield_msg", BLU"$N"+BLU+"���еذ�������������������ǰ�����ں�Ȼ������һ�����͸߹š�\n�����쳣�����ʱ���������һЦ���ְѱ��������ڰγ���\n"NOR);
     set("unequip_msg", HIC"$N"+HIC+"����ݳ�һ˿Ц�⣬������$n"+HIC+"������������е�ɱ���ܽ⣬\n�漴�������ʡ�\n"NOR);
   }
   init_blade(200,200,200);
   setup();
}
