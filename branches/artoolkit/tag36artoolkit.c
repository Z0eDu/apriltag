/* Copyright (C) 2013-2016, The Regents of The University of Michigan.
All rights reserved.
This software was developed in the APRIL Robotics Lab under the
direction of Edwin Olson, ebolson@umich.edu. This software may be
available under alternative licensing terms; contact the address above.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the Regents of The University of Michigan.
*/

#include <stdlib.h>
#include "apriltag.h"

apriltag_family_t __attribute__((optimize("O0"))) *tag36artoolkit_create()
{
   apriltag_family_t *tf = calloc(1, sizeof(apriltag_family_t));
   tf->name = strdup("tag36artoolkit");
   tf->h = 10;
   tf->ncodes = 512;
   tf->codes = calloc(512, sizeof(uint64_t));
   tf->codes[0] = 0x0006fd8381c9UL;
   tf->codes[1] = 0x0006dc8185c9UL;
   tf->codes[2] = 0x0006bd9281c1UL;
   tf->codes[3] = 0x00069c9085c1UL;
   tf->codes[4] = 0x0006fd870159UL;
   tf->codes[5] = 0x0006dc850559UL;
   tf->codes[6] = 0x0006bd960151UL;
   tf->codes[7] = 0x00069c940551UL;
   tf->codes[8] = 0x0006f103c1c9UL;
   tf->codes[9] = 0x0006d001c5c9UL;
   tf->codes[10] = 0x0006b112c1c1UL;
   tf->codes[11] = 0x00069010c5c1UL;
   tf->codes[12] = 0x0006f1074159UL;
   tf->codes[13] = 0x0006d0054559UL;
   tf->codes[14] = 0x0006b1164151UL;
   tf->codes[15] = 0x000690144551UL;
   tf->codes[16] = 0x00067d8ba1cbUL;
   tf->codes[17] = 0x00065c89a5cbUL;
   tf->codes[18] = 0x00063d9aa1c3UL;
   tf->codes[19] = 0x00061c98a5c3UL;
   tf->codes[20] = 0x00067d8f215bUL;
   tf->codes[21] = 0x00065c8d255bUL;
   tf->codes[22] = 0x00063d9e2153UL;
   tf->codes[23] = 0x00061c9c2553UL;
   tf->codes[24] = 0x0006710be1cbUL;
   tf->codes[25] = 0x00065009e5cbUL;
   tf->codes[26] = 0x0006311ae1c3UL;
   tf->codes[27] = 0x00061018e5c3UL;
   tf->codes[28] = 0x0006710f615bUL;
   tf->codes[29] = 0x0006500d655bUL;
   tf->codes[30] = 0x0006311e6153UL;
   tf->codes[31] = 0x0006101c6553UL;
   tf->codes[32] = 0x0007fd8382e9UL;
   tf->codes[33] = 0x0007dc8186e9UL;
   tf->codes[34] = 0x0007bd9282e1UL;
   tf->codes[35] = 0x00079c9086e1UL;
   tf->codes[36] = 0x0007fd870279UL;
   tf->codes[37] = 0x0007dc850679UL;
   tf->codes[38] = 0x0007bd960271UL;
   tf->codes[39] = 0x00079c940671UL;
   tf->codes[40] = 0x0007f103c2e9UL;
   tf->codes[41] = 0x0007d001c6e9UL;
   tf->codes[42] = 0x0007b112c2e1UL;
   tf->codes[43] = 0x00079010c6e1UL;
   tf->codes[44] = 0x0007f1074279UL;
   tf->codes[45] = 0x0007d0054679UL;
   tf->codes[46] = 0x0007b1164271UL;
   tf->codes[47] = 0x000790144671UL;
   tf->codes[48] = 0x00077d8ba2ebUL;
   tf->codes[49] = 0x00075c89a6ebUL;
   tf->codes[50] = 0x00073d9aa2e3UL;
   tf->codes[51] = 0x00071c98a6e3UL;
   tf->codes[52] = 0x00077d8f227bUL;
   tf->codes[53] = 0x00075c8d267bUL;
   tf->codes[54] = 0x00073d9e2273UL;
   tf->codes[55] = 0x00071c9c2673UL;
   tf->codes[56] = 0x0007710be2ebUL;
   tf->codes[57] = 0x00075009e6ebUL;
   tf->codes[58] = 0x0007311ae2e3UL;
   tf->codes[59] = 0x00071018e6e3UL;
   tf->codes[60] = 0x0007710f627bUL;
   tf->codes[61] = 0x0007500d667bUL;
   tf->codes[62] = 0x0007311e6273UL;
   tf->codes[63] = 0x0007101c6673UL;
   tf->codes[64] = 0x0004ffc381c8UL;
   tf->codes[65] = 0x0004dec185c8UL;
   tf->codes[66] = 0x0004bfd281c0UL;
   tf->codes[67] = 0x00049ed085c0UL;
   tf->codes[68] = 0x0004ffc70158UL;
   tf->codes[69] = 0x0004dec50558UL;
   tf->codes[70] = 0x0004bfd60150UL;
   tf->codes[71] = 0x00049ed40550UL;
   tf->codes[72] = 0x0004f343c1c8UL;
   tf->codes[73] = 0x0004d241c5c8UL;
   tf->codes[74] = 0x0004b352c1c0UL;
   tf->codes[75] = 0x00049250c5c0UL;
   tf->codes[76] = 0x0004f3474158UL;
   tf->codes[77] = 0x0004d2454558UL;
   tf->codes[78] = 0x0004b3564150UL;
   tf->codes[79] = 0x000492544550UL;
   tf->codes[80] = 0x00047fcba1caUL;
   tf->codes[81] = 0x00045ec9a5caUL;
   tf->codes[82] = 0x00043fdaa1c2UL;
   tf->codes[83] = 0x00041ed8a5c2UL;
   tf->codes[84] = 0x00047fcf215aUL;
   tf->codes[85] = 0x00045ecd255aUL;
   tf->codes[86] = 0x00043fde2152UL;
   tf->codes[87] = 0x00041edc2552UL;
   tf->codes[88] = 0x0004734be1caUL;
   tf->codes[89] = 0x00045249e5caUL;
   tf->codes[90] = 0x0004335ae1c2UL;
   tf->codes[91] = 0x00041258e5c2UL;
   tf->codes[92] = 0x0004734f615aUL;
   tf->codes[93] = 0x0004524d655aUL;
   tf->codes[94] = 0x0004335e6152UL;
   tf->codes[95] = 0x0004125c6552UL;
   tf->codes[96] = 0x0005ffc382e8UL;
   tf->codes[97] = 0x0005dec186e8UL;
   tf->codes[98] = 0x0005bfd282e0UL;
   tf->codes[99] = 0x00059ed086e0UL;
   tf->codes[100] = 0x0005ffc70278UL;
   tf->codes[101] = 0x0005dec50678UL;
   tf->codes[102] = 0x0005bfd60270UL;
   tf->codes[103] = 0x00059ed40670UL;
   tf->codes[104] = 0x0005f343c2e8UL;
   tf->codes[105] = 0x0005d241c6e8UL;
   tf->codes[106] = 0x0005b352c2e0UL;
   tf->codes[107] = 0x00059250c6e0UL;
   tf->codes[108] = 0x0005f3474278UL;
   tf->codes[109] = 0x0005d2454678UL;
   tf->codes[110] = 0x0005b3564270UL;
   tf->codes[111] = 0x000592544670UL;
   tf->codes[112] = 0x00057fcba2eaUL;
   tf->codes[113] = 0x00055ec9a6eaUL;
   tf->codes[114] = 0x00053fdaa2e2UL;
   tf->codes[115] = 0x00051ed8a6e2UL;
   tf->codes[116] = 0x00057fcf227aUL;
   tf->codes[117] = 0x00055ecd267aUL;
   tf->codes[118] = 0x00053fde2272UL;
   tf->codes[119] = 0x00051edc2672UL;
   tf->codes[120] = 0x0005734be2eaUL;
   tf->codes[121] = 0x00055249e6eaUL;
   tf->codes[122] = 0x0005335ae2e2UL;
   tf->codes[123] = 0x00051258e6e2UL;
   tf->codes[124] = 0x0005734f627aUL;
   tf->codes[125] = 0x0005524d667aUL;
   tf->codes[126] = 0x0005335e6272UL;
   tf->codes[127] = 0x0005125c6672UL;
   tf->codes[128] = 0x0002fda391cdUL;
   tf->codes[129] = 0x0002dca195cdUL;
   tf->codes[130] = 0x0002bdb291c5UL;
   tf->codes[131] = 0x00029cb095c5UL;
   tf->codes[132] = 0x0002fda7115dUL;
   tf->codes[133] = 0x0002dca5155dUL;
   tf->codes[134] = 0x0002bdb61155UL;
   tf->codes[135] = 0x00029cb41555UL;
   tf->codes[136] = 0x0002f123d1cdUL;
   tf->codes[137] = 0x0002d021d5cdUL;
   tf->codes[138] = 0x0002b132d1c5UL;
   tf->codes[139] = 0x00029030d5c5UL;
   tf->codes[140] = 0x0002f127515dUL;
   tf->codes[141] = 0x0002d025555dUL;
   tf->codes[142] = 0x0002b1365155UL;
   tf->codes[143] = 0x000290345555UL;
   tf->codes[144] = 0x00027dabb1cfUL;
   tf->codes[145] = 0x00025ca9b5cfUL;
   tf->codes[146] = 0x00023dbab1c7UL;
   tf->codes[147] = 0x00021cb8b5c7UL;
   tf->codes[148] = 0x00027daf315fUL;
   tf->codes[149] = 0x00025cad355fUL;
   tf->codes[150] = 0x00023dbe3157UL;
   tf->codes[151] = 0x00021cbc3557UL;
   tf->codes[152] = 0x0002712bf1cfUL;
   tf->codes[153] = 0x00025029f5cfUL;
   tf->codes[154] = 0x0002313af1c7UL;
   tf->codes[155] = 0x00021038f5c7UL;
   tf->codes[156] = 0x0002712f715fUL;
   tf->codes[157] = 0x0002502d755fUL;
   tf->codes[158] = 0x0002313e7157UL;
   tf->codes[159] = 0x0002103c7557UL;
   tf->codes[160] = 0x0003fda392edUL;
   tf->codes[161] = 0x0003dca196edUL;
   tf->codes[162] = 0x0003bdb292e5UL;
   tf->codes[163] = 0x00039cb096e5UL;
   tf->codes[164] = 0x0003fda7127dUL;
   tf->codes[165] = 0x0003dca5167dUL;
   tf->codes[166] = 0x0003bdb61275UL;
   tf->codes[167] = 0x00039cb41675UL;
   tf->codes[168] = 0x0003f123d2edUL;
   tf->codes[169] = 0x0003d021d6edUL;
   tf->codes[170] = 0x0003b132d2e5UL;
   tf->codes[171] = 0x00039030d6e5UL;
   tf->codes[172] = 0x0003f127527dUL;
   tf->codes[173] = 0x0003d025567dUL;
   tf->codes[174] = 0x0003b1365275UL;
   tf->codes[175] = 0x000390345675UL;
   tf->codes[176] = 0x00037dabb2efUL;
   tf->codes[177] = 0x00035ca9b6efUL;
   tf->codes[178] = 0x00033dbab2e7UL;
   tf->codes[179] = 0x00031cb8b6e7UL;
   tf->codes[180] = 0x00037daf327fUL;
   tf->codes[181] = 0x00035cad367fUL;
   tf->codes[182] = 0x00033dbe3277UL;
   tf->codes[183] = 0x00031cbc3677UL;
   tf->codes[184] = 0x0003712bf2efUL;
   tf->codes[185] = 0x00035029f6efUL;
   tf->codes[186] = 0x0003313af2e7UL;
   tf->codes[187] = 0x00031038f6e7UL;
   tf->codes[188] = 0x0003712f727fUL;
   tf->codes[189] = 0x0003502d767fUL;
   tf->codes[190] = 0x0003313e7277UL;
   tf->codes[191] = 0x0003103c7677UL;
   tf->codes[192] = 0x0000ffe391ccUL;
   tf->codes[193] = 0x0000dee195ccUL;
   tf->codes[194] = 0x0000bff291c4UL;
   tf->codes[195] = 0x00009ef095c4UL;
   tf->codes[196] = 0x0000ffe7115cUL;
   tf->codes[197] = 0x0000dee5155cUL;
   tf->codes[198] = 0x0000bff61154UL;
   tf->codes[199] = 0x00009ef41554UL;
   tf->codes[200] = 0x0000f363d1ccUL;
   tf->codes[201] = 0x0000d261d5ccUL;
   tf->codes[202] = 0x0000b372d1c4UL;
   tf->codes[203] = 0x00009270d5c4UL;
   tf->codes[204] = 0x0000f367515cUL;
   tf->codes[205] = 0x0000d265555cUL;
   tf->codes[206] = 0x0000b3765154UL;
   tf->codes[207] = 0x000092745554UL;
   tf->codes[208] = 0x00007febb1ceUL;
   tf->codes[209] = 0x00005ee9b5ceUL;
   tf->codes[210] = 0x00003ffab1c6UL;
   tf->codes[211] = 0x00001ef8b5c6UL;
   tf->codes[212] = 0x00007fef315eUL;
   tf->codes[213] = 0x00005eed355eUL;
   tf->codes[214] = 0x00003ffe3156UL;
   tf->codes[215] = 0x00001efc3556UL;
   tf->codes[216] = 0x0000736bf1ceUL;
   tf->codes[217] = 0x00005269f5ceUL;
   tf->codes[218] = 0x0000337af1c6UL;
   tf->codes[219] = 0x00001278f5c6UL;
   tf->codes[220] = 0x0000736f715eUL;
   tf->codes[221] = 0x0000526d755eUL;
   tf->codes[222] = 0x0000337e7156UL;
   tf->codes[223] = 0x0000127c7556UL;
   tf->codes[224] = 0x0001ffe392ecUL;
   tf->codes[225] = 0x0001dee196ecUL;
   tf->codes[226] = 0x0001bff292e4UL;
   tf->codes[227] = 0x00019ef096e4UL;
   tf->codes[228] = 0x0001ffe7127cUL;
   tf->codes[229] = 0x0001dee5167cUL;
   tf->codes[230] = 0x0001bff61274UL;
   tf->codes[231] = 0x00019ef41674UL;
   tf->codes[232] = 0x0001f363d2ecUL;
   tf->codes[233] = 0x0001d261d6ecUL;
   tf->codes[234] = 0x0001b372d2e4UL;
   tf->codes[235] = 0x00019270d6e4UL;
   tf->codes[236] = 0x0001f367527cUL;
   tf->codes[237] = 0x0001d265567cUL;
   tf->codes[238] = 0x0001b3765274UL;
   tf->codes[239] = 0x000192745674UL;
   tf->codes[240] = 0x00017febb2eeUL;
   tf->codes[241] = 0x00015ee9b6eeUL;
   tf->codes[242] = 0x00013ffab2e6UL;
   tf->codes[243] = 0x00011ef8b6e6UL;
   tf->codes[244] = 0x00017fef327eUL;
   tf->codes[245] = 0x00015eed367eUL;
   tf->codes[246] = 0x00013ffe3276UL;
   tf->codes[247] = 0x00011efc3676UL;
   tf->codes[248] = 0x0001736bf2eeUL;
   tf->codes[249] = 0x00015269f6eeUL;
   tf->codes[250] = 0x0001337af2e6UL;
   tf->codes[251] = 0x00011278f6e6UL;
   tf->codes[252] = 0x0001736f727eUL;
   tf->codes[253] = 0x0001526d767eUL;
   tf->codes[254] = 0x0001337e7276UL;
   tf->codes[255] = 0x0001127c7676UL;
   tf->codes[256] = 0x000eed838989UL;
   tf->codes[257] = 0x000ecc818d89UL;
   tf->codes[258] = 0x000ead928981UL;
   tf->codes[259] = 0x000e8c908d81UL;
   tf->codes[260] = 0x000eed870919UL;
   tf->codes[261] = 0x000ecc850d19UL;
   tf->codes[262] = 0x000ead960911UL;
   tf->codes[263] = 0x000e8c940d11UL;
   tf->codes[264] = 0x000ee103c989UL;
   tf->codes[265] = 0x000ec001cd89UL;
   tf->codes[266] = 0x000ea112c981UL;
   tf->codes[267] = 0x000e8010cd81UL;
   tf->codes[268] = 0x000ee1074919UL;
   tf->codes[269] = 0x000ec0054d19UL;
   tf->codes[270] = 0x000ea1164911UL;
   tf->codes[271] = 0x000e80144d11UL;
   tf->codes[272] = 0x000e6d8ba98bUL;
   tf->codes[273] = 0x000e4c89ad8bUL;
   tf->codes[274] = 0x000e2d9aa983UL;
   tf->codes[275] = 0x000e0c98ad83UL;
   tf->codes[276] = 0x000e6d8f291bUL;
   tf->codes[277] = 0x000e4c8d2d1bUL;
   tf->codes[278] = 0x000e2d9e2913UL;
   tf->codes[279] = 0x000e0c9c2d13UL;
   tf->codes[280] = 0x000e610be98bUL;
   tf->codes[281] = 0x000e4009ed8bUL;
   tf->codes[282] = 0x000e211ae983UL;
   tf->codes[283] = 0x000e0018ed83UL;
   tf->codes[284] = 0x000e610f691bUL;
   tf->codes[285] = 0x000e400d6d1bUL;
   tf->codes[286] = 0x000e211e6913UL;
   tf->codes[287] = 0x000e001c6d13UL;
   tf->codes[288] = 0x000fed838aa9UL;
   tf->codes[289] = 0x000fcc818ea9UL;
   tf->codes[290] = 0x000fad928aa1UL;
   tf->codes[291] = 0x000f8c908ea1UL;
   tf->codes[292] = 0x000fed870a39UL;
   tf->codes[293] = 0x000fcc850e39UL;
   tf->codes[294] = 0x000fad960a31UL;
   tf->codes[295] = 0x000f8c940e31UL;
   tf->codes[296] = 0x000fe103caa9UL;
   tf->codes[297] = 0x000fc001cea9UL;
   tf->codes[298] = 0x000fa112caa1UL;
   tf->codes[299] = 0x000f8010cea1UL;
   tf->codes[300] = 0x000fe1074a39UL;
   tf->codes[301] = 0x000fc0054e39UL;
   tf->codes[302] = 0x000fa1164a31UL;
   tf->codes[303] = 0x000f80144e31UL;
   tf->codes[304] = 0x000f6d8baaabUL;
   tf->codes[305] = 0x000f4c89aeabUL;
   tf->codes[306] = 0x000f2d9aaaa3UL;
   tf->codes[307] = 0x000f0c98aea3UL;
   tf->codes[308] = 0x000f6d8f2a3bUL;
   tf->codes[309] = 0x000f4c8d2e3bUL;
   tf->codes[310] = 0x000f2d9e2a33UL;
   tf->codes[311] = 0x000f0c9c2e33UL;
   tf->codes[312] = 0x000f610beaabUL;
   tf->codes[313] = 0x000f4009eeabUL;
   tf->codes[314] = 0x000f211aeaa3UL;
   tf->codes[315] = 0x000f0018eea3UL;
   tf->codes[316] = 0x000f610f6a3bUL;
   tf->codes[317] = 0x000f400d6e3bUL;
   tf->codes[318] = 0x000f211e6a33UL;
   tf->codes[319] = 0x000f001c6e33UL;
   tf->codes[320] = 0x000cefc38988UL;
   tf->codes[321] = 0x000ccec18d88UL;
   tf->codes[322] = 0x000cafd28980UL;
   tf->codes[323] = 0x000c8ed08d80UL;
   tf->codes[324] = 0x000cefc70918UL;
   tf->codes[325] = 0x000ccec50d18UL;
   tf->codes[326] = 0x000cafd60910UL;
   tf->codes[327] = 0x000c8ed40d10UL;
   tf->codes[328] = 0x000ce343c988UL;
   tf->codes[329] = 0x000cc241cd88UL;
   tf->codes[330] = 0x000ca352c980UL;
   tf->codes[331] = 0x000c8250cd80UL;
   tf->codes[332] = 0x000ce3474918UL;
   tf->codes[333] = 0x000cc2454d18UL;
   tf->codes[334] = 0x000ca3564910UL;
   tf->codes[335] = 0x000c82544d10UL;
   tf->codes[336] = 0x000c6fcba98aUL;
   tf->codes[337] = 0x000c4ec9ad8aUL;
   tf->codes[338] = 0x000c2fdaa982UL;
   tf->codes[339] = 0x000c0ed8ad82UL;
   tf->codes[340] = 0x000c6fcf291aUL;
   tf->codes[341] = 0x000c4ecd2d1aUL;
   tf->codes[342] = 0x000c2fde2912UL;
   tf->codes[343] = 0x000c0edc2d12UL;
   tf->codes[344] = 0x000c634be98aUL;
   tf->codes[345] = 0x000c4249ed8aUL;
   tf->codes[346] = 0x000c235ae982UL;
   tf->codes[347] = 0x000c0258ed82UL;
   tf->codes[348] = 0x000c634f691aUL;
   tf->codes[349] = 0x000c424d6d1aUL;
   tf->codes[350] = 0x000c235e6912UL;
   tf->codes[351] = 0x000c025c6d12UL;
   tf->codes[352] = 0x000defc38aa8UL;
   tf->codes[353] = 0x000dcec18ea8UL;
   tf->codes[354] = 0x000dafd28aa0UL;
   tf->codes[355] = 0x000d8ed08ea0UL;
   tf->codes[356] = 0x000defc70a38UL;
   tf->codes[357] = 0x000dcec50e38UL;
   tf->codes[358] = 0x000dafd60a30UL;
   tf->codes[359] = 0x000d8ed40e30UL;
   tf->codes[360] = 0x000de343caa8UL;
   tf->codes[361] = 0x000dc241cea8UL;
   tf->codes[362] = 0x000da352caa0UL;
   tf->codes[363] = 0x000d8250cea0UL;
   tf->codes[364] = 0x000de3474a38UL;
   tf->codes[365] = 0x000dc2454e38UL;
   tf->codes[366] = 0x000da3564a30UL;
   tf->codes[367] = 0x000d82544e30UL;
   tf->codes[368] = 0x000d6fcbaaaaUL;
   tf->codes[369] = 0x000d4ec9aeaaUL;
   tf->codes[370] = 0x000d2fdaaaa2UL;
   tf->codes[371] = 0x000d0ed8aea2UL;
   tf->codes[372] = 0x000d6fcf2a3aUL;
   tf->codes[373] = 0x000d4ecd2e3aUL;
   tf->codes[374] = 0x000d2fde2a32UL;
   tf->codes[375] = 0x000d0edc2e32UL;
   tf->codes[376] = 0x000d634beaaaUL;
   tf->codes[377] = 0x000d4249eeaaUL;
   tf->codes[378] = 0x000d235aeaa2UL;
   tf->codes[379] = 0x000d0258eea2UL;
   tf->codes[380] = 0x000d634f6a3aUL;
   tf->codes[381] = 0x000d424d6e3aUL;
   tf->codes[382] = 0x000d235e6a32UL;
   tf->codes[383] = 0x000d025c6e32UL;
   tf->codes[384] = 0x000aeda3998dUL;
   tf->codes[385] = 0x000acca19d8dUL;
   tf->codes[386] = 0x000aadb29985UL;
   tf->codes[387] = 0x000a8cb09d85UL;
   tf->codes[388] = 0x000aeda7191dUL;
   tf->codes[389] = 0x000acca51d1dUL;
   tf->codes[390] = 0x000aadb61915UL;
   tf->codes[391] = 0x000a8cb41d15UL;
   tf->codes[392] = 0x000ae123d98dUL;
   tf->codes[393] = 0x000ac021dd8dUL;
   tf->codes[394] = 0x000aa132d985UL;
   tf->codes[395] = 0x000a8030dd85UL;
   tf->codes[396] = 0x000ae127591dUL;
   tf->codes[397] = 0x000ac0255d1dUL;
   tf->codes[398] = 0x000aa1365915UL;
   tf->codes[399] = 0x000a80345d15UL;
   tf->codes[400] = 0x000a6dabb98fUL;
   tf->codes[401] = 0x000a4ca9bd8fUL;
   tf->codes[402] = 0x000a2dbab987UL;
   tf->codes[403] = 0x000a0cb8bd87UL;
   tf->codes[404] = 0x000a6daf391fUL;
   tf->codes[405] = 0x000a4cad3d1fUL;
   tf->codes[406] = 0x000a2dbe3917UL;
   tf->codes[407] = 0x000a0cbc3d17UL;
   tf->codes[408] = 0x000a612bf98fUL;
   tf->codes[409] = 0x000a4029fd8fUL;
   tf->codes[410] = 0x000a213af987UL;
   tf->codes[411] = 0x000a0038fd87UL;
   tf->codes[412] = 0x000a612f791fUL;
   tf->codes[413] = 0x000a402d7d1fUL;
   tf->codes[414] = 0x000a213e7917UL;
   tf->codes[415] = 0x000a003c7d17UL;
   tf->codes[416] = 0x000beda39aadUL;
   tf->codes[417] = 0x000bcca19eadUL;
   tf->codes[418] = 0x000badb29aa5UL;
   tf->codes[419] = 0x000b8cb09ea5UL;
   tf->codes[420] = 0x000beda71a3dUL;
   tf->codes[421] = 0x000bcca51e3dUL;
   tf->codes[422] = 0x000badb61a35UL;
   tf->codes[423] = 0x000b8cb41e35UL;
   tf->codes[424] = 0x000be123daadUL;
   tf->codes[425] = 0x000bc021deadUL;
   tf->codes[426] = 0x000ba132daa5UL;
   tf->codes[427] = 0x000b8030dea5UL;
   tf->codes[428] = 0x000be1275a3dUL;
   tf->codes[429] = 0x000bc0255e3dUL;
   tf->codes[430] = 0x000ba1365a35UL;
   tf->codes[431] = 0x000b80345e35UL;
   tf->codes[432] = 0x000b6dabbaafUL;
   tf->codes[433] = 0x000b4ca9beafUL;
   tf->codes[434] = 0x000b2dbabaa7UL;
   tf->codes[435] = 0x000b0cb8bea7UL;
   tf->codes[436] = 0x000b6daf3a3fUL;
   tf->codes[437] = 0x000b4cad3e3fUL;
   tf->codes[438] = 0x000b2dbe3a37UL;
   tf->codes[439] = 0x000b0cbc3e37UL;
   tf->codes[440] = 0x000b612bfaafUL;
   tf->codes[441] = 0x000b4029feafUL;
   tf->codes[442] = 0x000b213afaa7UL;
   tf->codes[443] = 0x000b0038fea7UL;
   tf->codes[444] = 0x000b612f7a3fUL;
   tf->codes[445] = 0x000b402d7e3fUL;
   tf->codes[446] = 0x000b213e7a37UL;
   tf->codes[447] = 0x000b003c7e37UL;
   tf->codes[448] = 0x0008efe3998cUL;
   tf->codes[449] = 0x0008cee19d8cUL;
   tf->codes[450] = 0x0008aff29984UL;
   tf->codes[451] = 0x00088ef09d84UL;
   tf->codes[452] = 0x0008efe7191cUL;
   tf->codes[453] = 0x0008cee51d1cUL;
   tf->codes[454] = 0x0008aff61914UL;
   tf->codes[455] = 0x00088ef41d14UL;
   tf->codes[456] = 0x0008e363d98cUL;
   tf->codes[457] = 0x0008c261dd8cUL;
   tf->codes[458] = 0x0008a372d984UL;
   tf->codes[459] = 0x00088270dd84UL;
   tf->codes[460] = 0x0008e367591cUL;
   tf->codes[461] = 0x0008c2655d1cUL;
   tf->codes[462] = 0x0008a3765914UL;
   tf->codes[463] = 0x000882745d14UL;
   tf->codes[464] = 0x00086febb98eUL;
   tf->codes[465] = 0x00084ee9bd8eUL;
   tf->codes[466] = 0x00082ffab986UL;
   tf->codes[467] = 0x00080ef8bd86UL;
   tf->codes[468] = 0x00086fef391eUL;
   tf->codes[469] = 0x00084eed3d1eUL;
   tf->codes[470] = 0x00082ffe3916UL;
   tf->codes[471] = 0x00080efc3d16UL;
   tf->codes[472] = 0x0008636bf98eUL;
   tf->codes[473] = 0x00084269fd8eUL;
   tf->codes[474] = 0x0008237af986UL;
   tf->codes[475] = 0x00080278fd86UL;
   tf->codes[476] = 0x0008636f791eUL;
   tf->codes[477] = 0x0008426d7d1eUL;
   tf->codes[478] = 0x0008237e7916UL;
   tf->codes[479] = 0x0008027c7d16UL;
   tf->codes[480] = 0x0009efe39aacUL;
   tf->codes[481] = 0x0009cee19eacUL;
   tf->codes[482] = 0x0009aff29aa4UL;
   tf->codes[483] = 0x00098ef09ea4UL;
   tf->codes[484] = 0x0009efe71a3cUL;
   tf->codes[485] = 0x0009cee51e3cUL;
   tf->codes[486] = 0x0009aff61a34UL;
   tf->codes[487] = 0x00098ef41e34UL;
   tf->codes[488] = 0x0009e363daacUL;
   tf->codes[489] = 0x0009c261deacUL;
   tf->codes[490] = 0x0009a372daa4UL;
   tf->codes[491] = 0x00098270dea4UL;
   tf->codes[492] = 0x0009e3675a3cUL;
   tf->codes[493] = 0x0009c2655e3cUL;
   tf->codes[494] = 0x0009a3765a34UL;
   tf->codes[495] = 0x000982745e34UL;
   tf->codes[496] = 0x00096febbaaeUL;
   tf->codes[497] = 0x00094ee9beaeUL;
   tf->codes[498] = 0x00092ffabaa6UL;
   tf->codes[499] = 0x00090ef8bea6UL;
   tf->codes[500] = 0x00096fef3a3eUL;
   tf->codes[501] = 0x00094eed3e3eUL;
   tf->codes[502] = 0x00092ffe3a36UL;
   tf->codes[503] = 0x00090efc3e36UL;
   tf->codes[504] = 0x0009636bfaaeUL;
   tf->codes[505] = 0x00094269feaeUL;
   tf->codes[506] = 0x0009237afaa6UL;
   tf->codes[507] = 0x00090278fea6UL;
   tf->codes[508] = 0x0009636f7a3eUL;
   tf->codes[509] = 0x0009426d7e3eUL;
   tf->codes[510] = 0x0009237e7a36UL;
   tf->codes[511] = 0x0009027c7e36UL;
   tf->nbits = 36;
   tf->bit_x = calloc(36, sizeof(uint32_t));
   tf->bit_y = calloc(36, sizeof(uint32_t));
   tf->bit_x[0] = 1;
   tf->bit_y[0] = 1;
   tf->bit_x[1] = 2;
   tf->bit_y[1] = 1;
   tf->bit_x[2] = 3;
   tf->bit_y[2] = 1;
   tf->bit_x[3] = 4;
   tf->bit_y[3] = 1;
   tf->bit_x[4] = 5;
   tf->bit_y[4] = 1;
   tf->bit_x[5] = 2;
   tf->bit_y[5] = 2;
   tf->bit_x[6] = 3;
   tf->bit_y[6] = 2;
   tf->bit_x[7] = 4;
   tf->bit_y[7] = 2;
   tf->bit_x[8] = 3;
   tf->bit_y[8] = 3;
   tf->bit_x[9] = 6;
   tf->bit_y[9] = 1;
   tf->bit_x[10] = 6;
   tf->bit_y[10] = 2;
   tf->bit_x[11] = 6;
   tf->bit_y[11] = 3;
   tf->bit_x[12] = 6;
   tf->bit_y[12] = 4;
   tf->bit_x[13] = 6;
   tf->bit_y[13] = 5;
   tf->bit_x[14] = 5;
   tf->bit_y[14] = 2;
   tf->bit_x[15] = 5;
   tf->bit_y[15] = 3;
   tf->bit_x[16] = 5;
   tf->bit_y[16] = 4;
   tf->bit_x[17] = 4;
   tf->bit_y[17] = 3;
   tf->bit_x[18] = 6;
   tf->bit_y[18] = 6;
   tf->bit_x[19] = 5;
   tf->bit_y[19] = 6;
   tf->bit_x[20] = 4;
   tf->bit_y[20] = 6;
   tf->bit_x[21] = 3;
   tf->bit_y[21] = 6;
   tf->bit_x[22] = 2;
   tf->bit_y[22] = 6;
   tf->bit_x[23] = 5;
   tf->bit_y[23] = 5;
   tf->bit_x[24] = 4;
   tf->bit_y[24] = 5;
   tf->bit_x[25] = 3;
   tf->bit_y[25] = 5;
   tf->bit_x[26] = 4;
   tf->bit_y[26] = 4;
   tf->bit_x[27] = 1;
   tf->bit_y[27] = 6;
   tf->bit_x[28] = 1;
   tf->bit_y[28] = 5;
   tf->bit_x[29] = 1;
   tf->bit_y[29] = 4;
   tf->bit_x[30] = 1;
   tf->bit_y[30] = 3;
   tf->bit_x[31] = 1;
   tf->bit_y[31] = 2;
   tf->bit_x[32] = 2;
   tf->bit_y[32] = 5;
   tf->bit_x[33] = 2;
   tf->bit_y[33] = 4;
   tf->bit_x[34] = 2;
   tf->bit_y[34] = 3;
   tf->bit_x[35] = 3;
   tf->bit_y[35] = 4;
   tf->width_at_border = 8;
   tf->total_width = 10;
   tf->reversed_border = false;
   return tf;
}

void tag36artoolkit_destroy(apriltag_family_t *tf)
{
   free(tf->codes);
   free(tf->bit_x);
   free(tf->bit_y);
   free(tf->name);
   free(tf);
}
