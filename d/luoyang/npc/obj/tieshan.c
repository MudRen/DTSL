
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIW"������"NOR, ({ "shan zi","shan" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("material", "iron");
     set("long", HIW"�����Ծ���Ϊ�ǣ����������˿��֯���ɡ�һ�滭��ʮ������ɫ��̬����Ů��
�޲�Ω��ΩФ����һ�浥��һ�ˣ�������欣���ϸ��ȥȴ���ǽ�������֮ɥ��
��ħŮ������\n"NOR);
     set("wield_msg", HIW"$N"+HIW+"�����г�$n"+HIW+"˳�����˼��£��Գ��޾�������������\n"NOR);
     set("unequip_msg", HIW"$N"+HIW+"����һҡ������һƬ��Ӱ����Ӱ��ȥ$n"+HIW+"����ʧ������\n"NOR);
   }
   init_blade(165,180,180);
   setup();
}
// Edit By Subzero
