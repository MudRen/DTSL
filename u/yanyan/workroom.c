/*
�����(Yanyan)�Ĺ����ҡ�
*/
#include <ansi.h>
inherit ROOM;
string show_paper();
string show_self();
void create()
{
	set("short",HIC"����ӵļ�"NOR);
        set("long", @LONG[1;36m
            .-"''-.  _
          .'       `( \
        @/            ')   ,--,__,-"
        /        /      \ /     /   _/
      __|           ,   |/         /
    .~  `\   / \ ,  |   /
  .~      `\    `  /  _/   _/
.~          `\  ~~`__/    /
~             `--'/
             /   /    /     �滳�����������ǵ����ӡ���
            /  /'    /[2;37;0m
�Աߵ������ϻ���һ������ (pan)��ǽ������һ��ֽ (paper)��
���ϻ�����һ��������(yinxiang)����ͷ������һ������(jing)��
LONG
);
        set("item_desc",([
        "bei":HIW"������\n\n"NOR,
        ]));
        set("objects",([
          __DIR__"box":1,
          ]));
        set("exits",([
	"out" : "/d/wiz/wizroom2",
        ]));
        set("no_quit",1);
        set("no_death",1);
        set("item_desc",([
        "pan":"
         _..,----,.._
      .-;'-.,____,.-';
     (( |            |
      `))            ;   Ҫţ�̡����ȡ����ǲ衭��
       ` |          | 
      .-' `,.____.,' '-.
     (     '------'     )
      `-=..________..--'
      \n",
      "paper":(:show_paper:),
       "yinxiang":"
  �Ĭ�  ��        ��      ��       �� ��     �ܡ�    �ܡ�
�ĬĬģ�����   ����       ������   ����         ����      �� �� 
�ĬĬ� ����    �� ��      ����    �� ��        �� ��       ����\n"+
BLINK+"�Ĭ�=����Ȧ������Ȧ������ŤŤ��ƨ��ŤŤ����Ͳ�����= 
        \n"NOR,
       "jing":(:show_self:),
      ]));
      
        setup();
}

int valid_leave(object ob,string dir)
{
  if(!wizardp(ob))
   return notify_fail("�������˼һ��ǲ�Ҫ�洦�߶��ĺá�\n");
  return ::valid_leave(ob,dir);
}

string show_paper()
{
  write(@LONG
   ���������� _/�� \_
 �������� _/������/\_
 ������ _/������ / / \_
 ���� _/��������/ /����\_
 ����/  __ ____/ /������ \
 �� | (__ ____/_/_()~~~~~|
 ����\_������/ /��������_/
 ������\_�� / /��׼����_/
 ��������\_/ /�� OK! _/
 ����������\/����  _/
LONG);
return "\n";
}
string show_self()
{
  write(@LONG
    @@@@@
   @@. .@@
  @@@\=/@@@
  @.-- --.@
  /(.) (.)\
  \ ) . ( /
  '(  v  )`
    \ | /
    ( | )   ����Ը�
    '- -`
LONG);
return BLINK+HIC"�ٺ�...\n"NOR;
}