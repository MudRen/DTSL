
string help()
{
  return "ʹ����������������ı��Լ�
  �����ɣ��� chparty �μұ�.
  ʹ��chorg none �򲻳�Ϊ�κ����ɵĳ�Ա��
  \n";
}

int main(object ob,string arg)
{
  
  if(!arg){
  tell_object(ob,help());
  return 1;}
  if(arg=="none"){
  ob->delete("family");
  tell_object(ob,"�������κ�����.\n");
  return 1;}
  ob->set("family/family_name",arg);
  tell_object(ob,"���ɸ�����ϡ�\n");
  return 1;
   
}

