
inherit ITEM;
mapping name=([
"�����":"yu guanyin","��ɺ��":"bai shanhu","ҹ����":"ye mingzhu",
"���":"fei cui","è��":"mao yan","������":"yudiao baima",
"ǧ���˲�":"ren shen","����":"hu po","������":"jin wawa",
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
     set("unit", "��");
     set("dm_find_job",1);
   }
   setup();
}
