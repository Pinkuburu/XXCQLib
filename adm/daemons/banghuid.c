// banghuid.c 帮会
// By 山猫adx @ CuteRabbit 23:22 99-6-9

#include <ansi.h>

string query_banghui(string banghui, int bhrank)
{
        if ( banghui == "朝廷" )
        {
                switch(bhrank)
                {
                        case 1: return "是"+HIC"当朝一品"+HIW"大元帅。\n"NOR;
                        case 2: return "是"+HIC"当朝二品"+HIW"大将军。\n"NOR;
                        case 3: return "是"+HIC"当朝三品"+HIW"上将军。\n"NOR;
                        case 4: return "是"+HIC"现任朝廷四品"+HIG"将军。\n"NOR;
                        case 5: return "是"+HIC"现任朝廷五品"+HIG"偏将军。\n"NOR;
                        case 6: return "是"+HIC"现任朝廷六品"+HIG"总兵。\n"NOR;
                        case 7: return "是"+HIC"担任官府七品"+HIM"提督。\n"NOR;
                        case 8: return "是"+HIC"担任官府八品"+HIM"牙将。\n"NOR;
                        case 9: return "是"+HIC"担任官府九品"+HIM"捕头。\n"NOR;
                }
        }
}

