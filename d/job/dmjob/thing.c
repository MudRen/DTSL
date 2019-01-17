
inherit ITEM;
mapping name=([
"Óñ¹ÛÒô":"yu guanyin","°×Éºº÷":"bai shanhu","Ò¹Ã÷Öé":"ye mingzhu",
"ôä´ä":"fei cui","Ã¨ÑÛ":"mao yan","Óñµñ°×Âí":"yudiao baima",
"Ç§ÄêÈË²Î":"ren shen","çúçê":"hu po","½ğÍŞÍŞ":"jin wawa",
]);
void create()
{
   string *myname;
   int i;
   
   myname=keys(name);
   i=random(sizeof(myname));
   set_name(myname[i], ({ name[myname[i]]}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {   
     set("unit", "¸ö");
     set("dm_find_job",1);
   }
   setup();
}
