mapping valid_login = ([
       // "forever":      ({ "61.182.251.", "61.159.49.17", "202.99.170." }),
        "yanyan":       ({ "218.8."}),
        "mudsky":       ({"211.150."}),
        "fire":         ({ "210.83." }),
        "fhq":          ({"211.162." }),
        "cool":         ({"218.24."  }),
        "rzy":          ({ "218.8."}),
        "subzero":      ({"61.180.197.178"}),
  //     "baimo":        ({ "202.107.","61.137." }),
	//        "nidenet":      ({ "61.", "218.11.77.", "202.99," }),
   //     "chris":    ({"218.20."}),
]);

int is_valid(string id, string ip)
{
        int i;

        if (ip == "127.0.0.1" || ip == "localhost")
                if (wiz_level(id)) return 1;
                else return 0;
        return 1;
        if (undefinedp(valid_login[id])) return 1;
        i = sizeof(valid_login[id]);
        while (i--) if (sscanf(ip, valid_login[id][i] + "%*s")) return 1;
        return 0;
}
