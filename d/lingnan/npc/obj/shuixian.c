//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIB"ˮ��"NOR, ({ "shuixian dao","shuixian","dao" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 100000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", HIB"ֻ�����屡���У�����ë���������ɣ���������������Өâ�������\n"+
                    "����Ŀ�ã��������������侹���д�������������쵶��ȱ�ղصĵ���\n"+
                    "��Ʒ����ˮ�ɡ��˵��ഫΪ�����������������䵮��ʱ��ɱ�����磬��\n"+
                    "��ʹ�����߷�񲣬�����赶�������������е��߲����á�����������Ϊ\n"+
                    "�浶�������η��붫�齻������ʱ����Ϊ����������ȱ����ȱ��������\n"+
                    "�����쵶�˾����ټ����浶ˮ�ɣ�����Ϭ���ѵ���\n"NOR);
     set("wield_msg", HIC"$n"+HIC+"��ͬ������һ�㣬��δ��$N"+HIC+"���ֳ������Ȼ�Լ�����һ�룬\n�Ⱥ�����ʹ�á�\n"NOR);
     set("unequip_msg",HIB"$N"+HIB+"�ۿ��ŵ���Ө��ת����â�����ɸ�̾�������Ǵ�˵�е��浶��\n��������ؽ�������\n"NOR);
   }
   init_blade(140,220,220);
   setup();
}
