
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIR"±Ş"HIG"ÅÚ"NOR, ({ "bian pao","bian","pao"}) );
   set_weight(150);
   
     set("material", "Ö½");
     set("unit", "¹Ò");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"ÄãºÃ£¡×£Äú"HIY"´º½Ú"NOR"¿ìÀÖ£¡\n"+
          "¸ĞĞ»Äã¶Ô"HIC"´óÌÆË«Áú"NOR"µÄÖ§³Ö£¡\n"+
          "×£ÄúÔÚĞÂµÄÒ»ÄêÀï¹¤×÷Ë³Àû£¬Ñ§Ï°½ø²½£¬ÓÀÔ¶¿ìÀÖ£¡\n"+
          "ÕâÊÇÒ»¹Ò±ŞÅÚ£¬Èç¹ûÄãµã×ÅËü£¬¾Í»áµÃµ½´º½ÚµÄÀñÎï¡£\n"+
          HIG"£¨dian bian pao£©\n"NOR;
       
}

void init()
{
  add_action("do_action","dian");
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
     return notify_fail("Õâ¸ö±ŞÅÚ²»ÊÇÄãµÄ£¬Äã²»ÄÜµã¡£\n");
   
   tell_object(ob,"\nÄãĞ¡ĞÄÒíÒíµØµãÈ¼ÁË±¬Öñ... ...\n\n");
   write(@LONG
   
[1;32m Ö»Ìı[1;31mÅüÅ¾[1;32mÉùÏìÆğ£¬Ò»·ù¶ÔÁª×Ô±¬ÖñÏÂ±ßÂäÁË³öÀ´£¡[2;37;0m 
   
    [42;1m[1;33mËÄ¼¾³ÊÏé[2;37;0m
   
   [42;1m[1;33mËê[2;37;0m      [42;1m[1;33m¼Ò[2;37;0m
   [42;1m[1;33mËê[2;37;0m      [42;1m[1;33m¼Ò[2;37;0m
   [42;1m[1;33mÄê[2;37;0m      [42;1m[1;33mĞÒ[2;37;0m
   [42;1m[1;33m·á[2;37;0m      [42;1m[1;33m¸£[2;37;0m
   [42;1m[1;33mÌí[2;37;0m      [42;1m[1;33mÇì[2;37;0m
   [42;1m[1;33mÃÀ[2;37;0m      [42;1m[1;33mÍÅ[2;37;0m
   [42;1m[1;33mÂú[2;37;0m      [42;1m[1;33mÔ±[2;37;0m
      
LONG);
   
   ob->add("potential",400);
   ob->add("food",1000);
   ob->add("water",1000);
   ob->add("char_lev/points",2);
   
   tell_object(ob,"\nÄãµÄÇ±ÄÜÌá¸ßÁË£¬¾«ÉñÁ¢¿Ì±äµÃ±¥Âú£¡\n"+
                  "ÄãµÃµ½ÁË"+HIY+" Á½ "+NOR+"µãÊôĞÔ£¡\n");
      
   destruct(this_object());
   return 1;
}