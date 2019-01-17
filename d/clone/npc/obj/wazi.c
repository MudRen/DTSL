
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIC"Ê¥µ®"HIG"Íà×Ó"NOR, ({ "wa zi","zi"}) );
   set_weight(150);
   
     set("material", "²¼");
     set("unit", "Ë«");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"ÄãºÃ£¡×£Äú"HIY"Ê¥µ®½Ú"NOR"¿ìÀÖ£¡\n"+
          "¸ĞĞ»Äã¶Ô"HIC"´óÌÆË«Áú"NOR"µÄÖ§³Ö£¡\n"+
          "½üÆÚÍøÂçÏßÂ·²»¶Ï³öÏÖ¹ÊÕÏ£¬»¹Ï£ÍûÄÜ¹»µÃµ½ÄúµÄÀí½â£¡\n"+
          "ÕâÊÇÒ»Ë«Ê¥µ®Íà×Ó£¬Èç¹ûÄã´©ÉÏËü£¬¾Í»áµÃµ½Ê¥µ®½ÚµÄÀñÎï¡£\n"+
          HIG"£¨chuan wa zi£©\n"NOR;
       
}

void init()
{
  add_action("do_action","chuan");
}

int do_action(string arg)
{
   object ob;
   ob=this_player();
   
   if(!arg)
   return 0;
   if(!present(arg,ob))
   return 0;
   if(!id(arg))
   return 0;
   
   if(query("owner_ob")!=ob)
   return notify_fail("Õâ¸öÍà×Ó²»ÊÇÄãµÄ£¬Äã²»ÄÜ´©¡£\n");
   
   tell_object(ob,"\nÍ»È»Ô¶´¦´«À´ÈÈÄÖµÄÉùÒô£¬ÄãÁ¬Ã¦³¯ÄÇÀï¿´¹ıÈ¥... ...\n\n");
   write(@LONG
   
   [1;32m Ö»ÌıÅéµØÒ»Éù£¬Ò»¸öÊ¥µ®Àñ»¨³åÉÏÁËÌì¿Õ£¡[2;37;0m 
   
   [5m[1;32m
   ¡ï¡ã¡à¡ã¡ã¡à ¡î¡ã£®¡¤¡ï¡ã¡à¡ã£®
         ¨¨        ¨¨Ê¥µ®½ÚÀ´ÁÙÁËÅ¶~
        ¨¡ï¨      ¨¡ï¨  
       ¨¡ö¡ö¨    ¨¡ö¡ö¨ £®¡¤¡ã¡à¡ï¡ã£®¡ã¡à¡ã£®¡î¡ã £®¡¤¡ã
      ¨¡ö¡ö¡ö¨  ¨¡ö¡ö¡ö¨ ×£ÄãÊ¥µ®½Ú¿ìÀÖ£¡
      ¦ñ¦ñ||¦ñ¦ñ!!¦ñ¦ñ||¦ñ¦ñ¡ã£®¡ã¡ï £®¡¤¡ã¡à¡ã¡ã£®¡ï¡î¡ã
               .  [2;37;0m   
LONG);
   
   ob->add("potential",800);
   ob->add("food",1000);
   ob->add("water",1000);
   
   tell_object(ob,query("name")+"ÀïÍ»È»Ã°³öÒ»ÕóÅ¨ÑÌ£¬Ò»Ê±¼äÄãÓÌÈç·ÉÏèÔÚÔÆÎíÖ®ÖĞ¡£\n"+
                  "ÑÌÎíÏûÉ¢£¬"+query("name")+"ÒÑ¾­ÏûÊ§ÁË¡£\n");
   
   destruct(this_object());
   return 1;
}