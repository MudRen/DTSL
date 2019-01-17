inherit F_DBASE;

mapping *city_map=({ /* sizeof() == 21 */
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/beimen.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/tiejiang",
    "count" : 1,
    "dir" : "/d/baling/bingqidian.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing2",
    "count" : 1,
    "dir" : "/d/baling/center.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bldizi",
    "count" : 1,
    "dir" : "/d/baling/center.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/quest/yrs/zhuge-dewei",
    "count" : 1,
    "dir" : "/d/baling/dongjie2.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/dongmen.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/xiaoer",
    "count" : 1,
    "dir" : "/d/baling/jiuguan.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/xiaoer2",
    "count" : 1,
    "dir" : "/d/baling/kezhan.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/nanmen.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/wu",
    "count" : 1,
    "dir" : "/d/baling/qianzhuang.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/boy",
    "count" : 1,
    "dir" : "/d/baling/qingshilu2.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/she",
    "count" : 2,
    "dir" : "/d/baling/xiaoxi.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/liumang2",
    "count" : 1,
    "dir" : "/d/baling/xiaoxiang1.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/liumang",
    "count" : 1,
    "dir" : "/d/baling/xiaoxiang1.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/xiaojie",
    "count" : 1,
    "dir" : "/d/baling/xijie1.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/jiyinong",
    "count" : 1,
    "dir" : "/d/baling/xijie2.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/ximen.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/job/yunyanjob/guanchai",
    "count" : 1,
    "dir" : "/d/baling/yanju.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/yingdi.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/xiaocui",
    "count" : 1,
    "dir" : "/d/baling/yingjunlou.c",
  ]),
  ([ /* sizeof() == 3 */
    "npc" : "/d/baling/npc/bing",
    "count" : 2,
    "dir" : "/d/baling/yingmen.c",
  ])
});

mapping *query_citymap(){
	return city_map;
}

int query_timeout(){
	return sizeof(city_map);
}

string query_mapname(){
	return "baling map";
}