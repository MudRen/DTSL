
inherit ITEM;

#include <ansi.h>

string *lev=({
BLU"����"NOR,HIB"����"NOR,CYN"����"NOR,GRN"�϶�"NOR,
HIC"�ܶ�"NOR,HIY"����"NOR,HIG"����"NOR,HIW"����"NOR,

});

void create()
{
        set_name("ҩ", ({ "medicine" }) );
        set_weight(10);
        set("unit", "��");
	set("long","����һ�òݡ�\n");
        setup();
}

string long()
{
  string longs;
  mapping m_types;
  string *eff_types,msg;
  int i,div=1;
  
  longs=query("long");
  
  m_types=query("heal_up");
  if(!mapp(m_types))
   return longs;
  
  eff_types=keys(m_types);
  
  longs+="��Ч��\n";
  
  for(i=0;i<sizeof(eff_types);i++)
   if( m_types[eff_types[i]]>0){
     if(eff_types[i]=="��ʱ��������"||
        eff_types[i]=="��ʱ������������"
       )
      div=300;
     else
     if(eff_types[i]=="��ʱ���ӷ���"||
        eff_types[i]=="��ʱ��������"
       )
      div=10; 
     else
     if(eff_types[i]=="��ʱ���ӱ���"||
        eff_types[i]=="��ʱ���Ӹ���"||
        eff_types[i]=="��ʱ������"||
        eff_types[i]=="��ʱ��������"
       )
      div=2; 
     else
     if(eff_types[i]=="������������")
      div=1; 
     else
     if(eff_types[i]=="���ӱ���"||
        eff_types[i]=="���Ӹ���"||
        eff_types[i]=="������"||
        eff_types[i]=="��������"
       )
      div=1; 
     else
     if(eff_types[i]=="���Ӿ���"||
        eff_types[i]=="����Ǳ��"
       )
     div=15;
     else
     div=75;
    longs+="��"+eff_types[i]+"����"+lev[m_types[eff_types[i]]/div>sizeof(lev)-1?sizeof(lev)-1:m_types[eff_types[i]]/div]+"��\n";
           
   }
  return longs;
  
}