
#include <ansi.h> 
inherit ITEM;
mapping name=([
"�ò�ñ":"caomao","�Ʋ�Ь":"caoxie","���չ�":"taoguan","����":"feitie","�ϵ�":"duandao",
"����":"kulou",	HIG"������"NOR:"changshengjue",HIB"����ӡ"NOR:"busiyin",HIW"�Ⱥ�����"NOR:"jiandian",
HIC"�����"NOR:"heshibi",YEL"��Կ��"NOR:"yaoshi","�ײİ�":"guancaiban","�ñ�":"lanbei","������":"tui",
"������":"yuwang",HIM"�廨Ь"NOR:"xie",
]);
void create_name()
{
  int i;
  string *id;
  id=keys(name);
  i=random(sizeof(id));
  set_name(id[i],({name[id[i]]}));
  return;
}
	

void create()
{
   set_name("��Ʒ", ({"rice"}));
        set_weight(100000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               
        }
}

