
#include <ansi.h> 
inherit ITEM;
mapping name=([
"ÀÃ²İÃ±":"caomao","ÆÆ²İĞ¬":"caoxie","ÀÃÌÕ¹Ş":"taoguan","·ÏÌú":"feitie","¶Ïµ¶":"duandao",
"÷¼÷Ã":"kulou",	HIG"³¤Éú¾÷"NOR:"changshengjue",HIB"²»ËÀÓ¡"NOR:"busiyin",HIW"´Èº½½£µä"NOR:"jiandian",
HIC"ºÍÊÏèµ"NOR:"heshibi",YEL"ÌúÔ¿³×"NOR:"yaoshi","¹×²Ä°â":"guancaiban","ÀÃ±®":"lanbei","×À×ÓÍÈ":"tui",
"ÀÃÓæÍø":"yuwang",HIM"Ğå»¨Ğ¬"NOR:"xie",
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
   set_name("ÎïÆ·", ({"rice"}));
        set_weight(100000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
               
        }
}

