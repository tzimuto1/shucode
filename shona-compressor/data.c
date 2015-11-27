#include "data.h"
#include <stddef.h>

/**
 This a Shona regex that works with any type of Shona text (e.g mixture of Shona and English/Numbers)
*/
const char shona_regex[] = "((B|Bh|Bv|Bw|b|bh|bv|bw|Ch|Chw|ch|chw|D|Dh|Dy|Dz|Dzv|Dzw|d|dh|dy|dz|dzv|dzw|F|f|G|Gw|g|gw|H|Hw|h|hw|J|j|K|Kw|k|kw|M|Mb|Mbw|Mh|Mv|Mw|m|mb|mbw|mh|mv|mw|N'|N|Nd|Ndw|Ng|Ngw|Nh|Nj|Nw|Ny|Nz|Nzw|Nzv|n'|n|nd|ndw|ng|ngw|nh|nj|nw|ny|nz|nzw|nzv|P|Pf|Pw|p|pf|pw|R|Rw|r|rw|S|Sh|Shw|Sv|Sw|s|sh|shw|sv|sw|T|Ts|Tsw|Tsv|Tw|t|ts|tsw|tsv|tw|V|Vh|v|vh|W|w|Y|y|Z|Zh|Zhw|Zv|Zw|z|zh|zhw|zv|zw)[aeiou])|([\t\n\r -~])";

/**
 This is a list of all the syllables that exist in the Shona language. In this case we treat all the characters starting from chr(33) to chr(126) as Shona syllables. This means that we can compress any typy of a Shona document (e.g mixture of Shona and English).
*/
node node_list[] = {
    {"\t", 0, 0, 0, NULL, NULL},//0
    {"\n", 0, 0, 0, NULL, NULL},//1
    {"\r", 0, 0, 0, NULL, NULL},//2
    {" ", 0, 0, 0, NULL, NULL},//3
    {"!", 0, 0, 0, NULL, NULL},//4
    {"\"", 0, 0, 0, NULL, NULL},//5
    {"#", 0, 0, 0, NULL, NULL},//6
    {"$", 0, 0, 0, NULL, NULL},//7
    {"%", 0, 0, 0, NULL, NULL},//8
    {"&", 0, 0, 0, NULL, NULL},//9
    {"'", 0, 0, 0, NULL, NULL},//10
    {"(", 0, 0, 0, NULL, NULL},//11
    {")", 0, 0, 0, NULL, NULL},//12
    {"*", 0, 0, 0, NULL, NULL},//13
    {"+", 0, 0, 0, NULL, NULL},//14
    {",", 0, 0, 0, NULL, NULL},//15
    {"-", 0, 0, 0, NULL, NULL},//16
    {".", 0, 0, 0, NULL, NULL},//17
    {"/", 0, 0, 0, NULL, NULL},//18
    {"0", 0, 0, 0, NULL, NULL},//19
    {"1", 0, 0, 0, NULL, NULL},//20
    {"2", 0, 0, 0, NULL, NULL},//21
    {"3", 0, 0, 0, NULL, NULL},//22
    {"4", 0, 0, 0, NULL, NULL},//23
    {"5", 0, 0, 0, NULL, NULL},//24
    {"6", 0, 0, 0, NULL, NULL},//25
    {"7", 0, 0, 0, NULL, NULL},//26
    {"8", 0, 0, 0, NULL, NULL},//27
    {"9", 0, 0, 0, NULL, NULL},//28
    {":", 0, 0, 0, NULL, NULL},//29
    {";", 0, 0, 0, NULL, NULL},//30
    {"<", 0, 0, 0, NULL, NULL},//31
    {"=", 0, 0, 0, NULL, NULL},//32
    {">", 0, 0, 0, NULL, NULL},//33
    {"?", 0, 0, 0, NULL, NULL},//34
    {"@", 0, 0, 0, NULL, NULL},//35
    {"A", 0, 0, 0, NULL, NULL},//36
    {"B", 0, 0, 0, NULL, NULL},//37
    {"Ba", 0, 0, 0, NULL, NULL},//38
    {"Be", 0, 0, 0, NULL, NULL},//39
    {"Bha", 0, 0, 0, NULL, NULL},//40
    {"Bhe", 0, 0, 0, NULL, NULL},//41
    {"Bhi", 0, 0, 0, NULL, NULL},//42
    {"Bho", 0, 0, 0, NULL, NULL},//43
    {"Bhu", 0, 0, 0, NULL, NULL},//44
    {"Bi", 0, 0, 0, NULL, NULL},//45
    {"Bo", 0, 0, 0, NULL, NULL},//46
    {"Bu", 0, 0, 0, NULL, NULL},//47
    {"Bva", 0, 0, 0, NULL, NULL},//48
    {"Bve", 0, 0, 0, NULL, NULL},//49
    {"Bvi", 0, 0, 0, NULL, NULL},//50
    {"Bvo", 0, 0, 0, NULL, NULL},//51
    {"Bvu", 0, 0, 0, NULL, NULL},//52
    {"Bwa", 0, 0, 0, NULL, NULL},//53
    {"Bwe", 0, 0, 0, NULL, NULL},//54
    {"Bwi", 0, 0, 0, NULL, NULL},//55
    {"Bwo", 0, 0, 0, NULL, NULL},//56
    {"Bwu", 0, 0, 0, NULL, NULL},//57
    {"C", 0, 0, 0, NULL, NULL},//58
    {"Cha", 0, 0, 0, NULL, NULL},//59
    {"Che", 0, 0, 0, NULL, NULL},//60
    {"Chi", 0, 0, 0, NULL, NULL},//61
    {"Cho", 0, 0, 0, NULL, NULL},//62
    {"Chu", 0, 0, 0, NULL, NULL},//63
    {"Chwa", 0, 0, 0, NULL, NULL},//64
    {"Chwe", 0, 0, 0, NULL, NULL},//65
    {"Chwi", 0, 0, 0, NULL, NULL},//66
    {"Chwo", 0, 0, 0, NULL, NULL},//67
    {"Chwu", 0, 0, 0, NULL, NULL},//68
    {"D", 0, 0, 0, NULL, NULL},//69
    {"Da", 0, 0, 0, NULL, NULL},//70
    {"De", 0, 0, 0, NULL, NULL},//71
    {"Dha", 0, 0, 0, NULL, NULL},//72
    {"Dhe", 0, 0, 0, NULL, NULL},//73
    {"Dhi", 0, 0, 0, NULL, NULL},//74
    {"Dho", 0, 0, 0, NULL, NULL},//75
    {"Dhu", 0, 0, 0, NULL, NULL},//76
    {"Di", 0, 0, 0, NULL, NULL},//77
    {"Do", 0, 0, 0, NULL, NULL},//78
    {"Du", 0, 0, 0, NULL, NULL},//79
    {"Dya", 0, 0, 0, NULL, NULL},//80
    {"Dye", 0, 0, 0, NULL, NULL},//81
    {"Dyi", 0, 0, 0, NULL, NULL},//82
    {"Dyo", 0, 0, 0, NULL, NULL},//83
    {"Dyu", 0, 0, 0, NULL, NULL},//84
    {"Dza", 0, 0, 0, NULL, NULL},//85
    {"Dze", 0, 0, 0, NULL, NULL},//86
    {"Dzi", 0, 0, 0, NULL, NULL},//87
    {"Dzo", 0, 0, 0, NULL, NULL},//88
    {"Dzu", 0, 0, 0, NULL, NULL},//89
    {"Dzva", 0, 0, 0, NULL, NULL},//90
    {"Dzve", 0, 0, 0, NULL, NULL},//91
    {"Dzvi", 0, 0, 0, NULL, NULL},//92
    {"Dzvo", 0, 0, 0, NULL, NULL},//93
    {"Dzvu", 0, 0, 0, NULL, NULL},//94
    {"Dzwa", 0, 0, 0, NULL, NULL},//95
    {"Dzwe", 0, 0, 0, NULL, NULL},//96
    {"Dzwi", 0, 0, 0, NULL, NULL},//97
    {"Dzwo", 0, 0, 0, NULL, NULL},//98
    {"Dzwu", 0, 0, 0, NULL, NULL},//99
    {"E", 0, 0, 0, NULL, NULL},//100
    {"F", 0, 0, 0, NULL, NULL},//101
    {"Fa", 0, 0, 0, NULL, NULL},//102
    {"Fe", 0, 0, 0, NULL, NULL},//103
    {"Fi", 0, 0, 0, NULL, NULL},//104
    {"Fo", 0, 0, 0, NULL, NULL},//105
    {"Fu", 0, 0, 0, NULL, NULL},//106
    {"G", 0, 0, 0, NULL, NULL},//107
    {"Ga", 0, 0, 0, NULL, NULL},//108
    {"Ge", 0, 0, 0, NULL, NULL},//109
    {"Gi", 0, 0, 0, NULL, NULL},//110
    {"Go", 0, 0, 0, NULL, NULL},//111
    {"Gu", 0, 0, 0, NULL, NULL},//112
    {"Gwa", 0, 0, 0, NULL, NULL},//113
    {"Gwe", 0, 0, 0, NULL, NULL},//114
    {"Gwi", 0, 0, 0, NULL, NULL},//115
    {"Gwo", 0, 0, 0, NULL, NULL},//116
    {"Gwu", 0, 0, 0, NULL, NULL},//117
    {"H", 0, 0, 0, NULL, NULL},//118
    {"Ha", 0, 0, 0, NULL, NULL},//119
    {"He", 0, 0, 0, NULL, NULL},//120
    {"Hi", 0, 0, 0, NULL, NULL},//121
    {"Ho", 0, 0, 0, NULL, NULL},//122
    {"Hu", 0, 0, 0, NULL, NULL},//123
    {"Hwa", 0, 0, 0, NULL, NULL},//124
    {"Hwe", 0, 0, 0, NULL, NULL},//125
    {"Hwi", 0, 0, 0, NULL, NULL},//126
    {"Hwo", 0, 0, 0, NULL, NULL},//127
    {"Hwu", 0, 0, 0, NULL, NULL},//128
    {"I", 0, 0, 0, NULL, NULL},//129
    {"J", 0, 0, 0, NULL, NULL},//130
    {"Ja", 0, 0, 0, NULL, NULL},//131
    {"Je", 0, 0, 0, NULL, NULL},//132
    {"Ji", 0, 0, 0, NULL, NULL},//133
    {"Jo", 0, 0, 0, NULL, NULL},//134
    {"Ju", 0, 0, 0, NULL, NULL},//135
    {"K", 0, 0, 0, NULL, NULL},//136
    {"Ka", 0, 0, 0, NULL, NULL},//137
    {"Ke", 0, 0, 0, NULL, NULL},//138
    {"Ki", 0, 0, 0, NULL, NULL},//139
    {"Ko", 0, 0, 0, NULL, NULL},//140
    {"Ku", 0, 0, 0, NULL, NULL},//141
    {"Kwa", 0, 0, 0, NULL, NULL},//142
    {"Kwe", 0, 0, 0, NULL, NULL},//143
    {"Kwi", 0, 0, 0, NULL, NULL},//144
    {"Kwo", 0, 0, 0, NULL, NULL},//145
    {"Kwu", 0, 0, 0, NULL, NULL},//146
    {"L", 0, 0, 0, NULL, NULL},//147
    {"M", 0, 0, 0, NULL, NULL},//148
    {"Ma", 0, 0, 0, NULL, NULL},//149
    {"Mba", 0, 0, 0, NULL, NULL},//150
    {"Mbe", 0, 0, 0, NULL, NULL},//151
    {"Mbi", 0, 0, 0, NULL, NULL},//152
    {"Mbo", 0, 0, 0, NULL, NULL},//153
    {"Mbu", 0, 0, 0, NULL, NULL},//154
    {"Mbwa", 0, 0, 0, NULL, NULL},//155
    {"Mbwe", 0, 0, 0, NULL, NULL},//156
    {"Mbwi", 0, 0, 0, NULL, NULL},//157
    {"Mbwo", 0, 0, 0, NULL, NULL},//158
    {"Mbwu", 0, 0, 0, NULL, NULL},//159
    {"Me", 0, 0, 0, NULL, NULL},//160
    {"Mha", 0, 0, 0, NULL, NULL},//161
    {"Mhe", 0, 0, 0, NULL, NULL},//162
    {"Mhi", 0, 0, 0, NULL, NULL},//163
    {"Mho", 0, 0, 0, NULL, NULL},//164
    {"Mhu", 0, 0, 0, NULL, NULL},//165
    {"Mi", 0, 0, 0, NULL, NULL},//166
    {"Mo", 0, 0, 0, NULL, NULL},//167
    {"Mu", 0, 0, 0, NULL, NULL},//168
    {"Mva", 0, 0, 0, NULL, NULL},//169
    {"Mve", 0, 0, 0, NULL, NULL},//170
    {"Mvi", 0, 0, 0, NULL, NULL},//171
    {"Mvo", 0, 0, 0, NULL, NULL},//172
    {"Mvu", 0, 0, 0, NULL, NULL},//173
    {"Mwa", 0, 0, 0, NULL, NULL},//174
    {"Mwe", 0, 0, 0, NULL, NULL},//175
    {"Mwi", 0, 0, 0, NULL, NULL},//176
    {"Mwo", 0, 0, 0, NULL, NULL},//177
    {"Mwu", 0, 0, 0, NULL, NULL},//178
    {"N", 0, 0, 0, NULL, NULL},//179
    {"N'a", 0, 0, 0, NULL, NULL},//180
    {"N'e", 0, 0, 0, NULL, NULL},//181
    {"N'i", 0, 0, 0, NULL, NULL},//182
    {"N'o", 0, 0, 0, NULL, NULL},//183
    {"N'u", 0, 0, 0, NULL, NULL},//184
    {"Na", 0, 0, 0, NULL, NULL},//185
    {"Nda", 0, 0, 0, NULL, NULL},//186
    {"Nde", 0, 0, 0, NULL, NULL},//187
    {"Ndi", 0, 0, 0, NULL, NULL},//188
    {"Ndo", 0, 0, 0, NULL, NULL},//189
    {"Ndu", 0, 0, 0, NULL, NULL},//190
    {"Ndwa", 0, 0, 0, NULL, NULL},//191
    {"Ndwe", 0, 0, 0, NULL, NULL},//192
    {"Ndwi", 0, 0, 0, NULL, NULL},//193
    {"Ndwo", 0, 0, 0, NULL, NULL},//194
    {"Ndwu", 0, 0, 0, NULL, NULL},//195
    {"Ne", 0, 0, 0, NULL, NULL},//196
    {"Nga", 0, 0, 0, NULL, NULL},//197
    {"Nge", 0, 0, 0, NULL, NULL},//198
    {"Ngi", 0, 0, 0, NULL, NULL},//199
    {"Ngo", 0, 0, 0, NULL, NULL},//200
    {"Ngu", 0, 0, 0, NULL, NULL},//201
    {"Ngwa", 0, 0, 0, NULL, NULL},//202
    {"Ngwe", 0, 0, 0, NULL, NULL},//203
    {"Ngwi", 0, 0, 0, NULL, NULL},//204
    {"Ngwo", 0, 0, 0, NULL, NULL},//205
    {"Ngwu", 0, 0, 0, NULL, NULL},//206
    {"Nha", 0, 0, 0, NULL, NULL},//207
    {"Nhe", 0, 0, 0, NULL, NULL},//208
    {"Nhi", 0, 0, 0, NULL, NULL},//209
    {"Nho", 0, 0, 0, NULL, NULL},//210
    {"Nhu", 0, 0, 0, NULL, NULL},//211
    {"Ni", 0, 0, 0, NULL, NULL},//212
    {"Nja", 0, 0, 0, NULL, NULL},//213
    {"Nje", 0, 0, 0, NULL, NULL},//214
    {"Nji", 0, 0, 0, NULL, NULL},//215
    {"Njo", 0, 0, 0, NULL, NULL},//216
    {"Nju", 0, 0, 0, NULL, NULL},//217
    {"No", 0, 0, 0, NULL, NULL},//218
    {"Nu", 0, 0, 0, NULL, NULL},//219
    {"Nwa", 0, 0, 0, NULL, NULL},//220
    {"Nwe", 0, 0, 0, NULL, NULL},//221
    {"Nwi", 0, 0, 0, NULL, NULL},//222
    {"Nwo", 0, 0, 0, NULL, NULL},//223
    {"Nwu", 0, 0, 0, NULL, NULL},//224
    {"Nya", 0, 0, 0, NULL, NULL},//225
    {"Nye", 0, 0, 0, NULL, NULL},//226
    {"Nyi", 0, 0, 0, NULL, NULL},//227
    {"Nyo", 0, 0, 0, NULL, NULL},//228
    {"Nyu", 0, 0, 0, NULL, NULL},//229
    {"Nza", 0, 0, 0, NULL, NULL},//230
    {"Nze", 0, 0, 0, NULL, NULL},//231
    {"Nzi", 0, 0, 0, NULL, NULL},//232
    {"Nzo", 0, 0, 0, NULL, NULL},//233
    {"Nzu", 0, 0, 0, NULL, NULL},//234
    {"Nzva", 0, 0, 0, NULL, NULL},//235
    {"Nzve", 0, 0, 0, NULL, NULL},//236
    {"Nzvi", 0, 0, 0, NULL, NULL},//237
    {"Nzvo", 0, 0, 0, NULL, NULL},//238
    {"Nzvu", 0, 0, 0, NULL, NULL},//239
    {"Nzwa", 0, 0, 0, NULL, NULL},//240
    {"Nzwe", 0, 0, 0, NULL, NULL},//241
    {"Nzwi", 0, 0, 0, NULL, NULL},//242
    {"Nzwo", 0, 0, 0, NULL, NULL},//243
    {"Nzwu", 0, 0, 0, NULL, NULL},//244
    {"O", 0, 0, 0, NULL, NULL},//245
    {"P", 0, 0, 0, NULL, NULL},//246
    {"Pa", 0, 0, 0, NULL, NULL},//247
    {"Pe", 0, 0, 0, NULL, NULL},//248
    {"Pfa", 0, 0, 0, NULL, NULL},//249
    {"Pfe", 0, 0, 0, NULL, NULL},//250
    {"Pfi", 0, 0, 0, NULL, NULL},//251
    {"Pfo", 0, 0, 0, NULL, NULL},//252
    {"Pfu", 0, 0, 0, NULL, NULL},//253
    {"Pi", 0, 0, 0, NULL, NULL},//254
    {"Po", 0, 0, 0, NULL, NULL},//255
    {"Pu", 0, 0, 0, NULL, NULL},//256
    {"Pwa", 0, 0, 0, NULL, NULL},//257
    {"Pwe", 0, 0, 0, NULL, NULL},//258
    {"Pwi", 0, 0, 0, NULL, NULL},//259
    {"Pwo", 0, 0, 0, NULL, NULL},//260
    {"Pwu", 0, 0, 0, NULL, NULL},//261
    {"Q", 0, 0, 0, NULL, NULL},//262
    {"R", 0, 0, 0, NULL, NULL},//263
    {"Ra", 0, 0, 0, NULL, NULL},//264
    {"Re", 0, 0, 0, NULL, NULL},//265
    {"Ri", 0, 0, 0, NULL, NULL},//266
    {"Ro", 0, 0, 0, NULL, NULL},//267
    {"Ru", 0, 0, 0, NULL, NULL},//268
    {"Rwa", 0, 0, 0, NULL, NULL},//269
    {"Rwe", 0, 0, 0, NULL, NULL},//270
    {"Rwi", 0, 0, 0, NULL, NULL},//271
    {"Rwo", 0, 0, 0, NULL, NULL},//272
    {"Rwu", 0, 0, 0, NULL, NULL},//273
    {"S", 0, 0, 0, NULL, NULL},//274
    {"Sa", 0, 0, 0, NULL, NULL},//275
    {"Se", 0, 0, 0, NULL, NULL},//276
    {"Sha", 0, 0, 0, NULL, NULL},//277
    {"She", 0, 0, 0, NULL, NULL},//278
    {"Shi", 0, 0, 0, NULL, NULL},//279
    {"Sho", 0, 0, 0, NULL, NULL},//280
    {"Shu", 0, 0, 0, NULL, NULL},//281
    {"Shwa", 0, 0, 0, NULL, NULL},//282
    {"Shwe", 0, 0, 0, NULL, NULL},//283
    {"Shwi", 0, 0, 0, NULL, NULL},//284
    {"Shwo", 0, 0, 0, NULL, NULL},//285
    {"Shwu", 0, 0, 0, NULL, NULL},//286
    {"Si", 0, 0, 0, NULL, NULL},//287
    {"So", 0, 0, 0, NULL, NULL},//288
    {"Su", 0, 0, 0, NULL, NULL},//289
    {"Sva", 0, 0, 0, NULL, NULL},//290
    {"Sve", 0, 0, 0, NULL, NULL},//291
    {"Svi", 0, 0, 0, NULL, NULL},//292
    {"Svo", 0, 0, 0, NULL, NULL},//293
    {"Svu", 0, 0, 0, NULL, NULL},//294
    {"Swa", 0, 0, 0, NULL, NULL},//295
    {"Swe", 0, 0, 0, NULL, NULL},//296
    {"Swi", 0, 0, 0, NULL, NULL},//297
    {"Swo", 0, 0, 0, NULL, NULL},//298
    {"Swu", 0, 0, 0, NULL, NULL},//299
    {"T", 0, 0, 0, NULL, NULL},//300
    {"Ta", 0, 0, 0, NULL, NULL},//301
    {"Te", 0, 0, 0, NULL, NULL},//302
    {"Ti", 0, 0, 0, NULL, NULL},//303
    {"To", 0, 0, 0, NULL, NULL},//304
    {"Tsa", 0, 0, 0, NULL, NULL},//305
    {"Tse", 0, 0, 0, NULL, NULL},//306
    {"Tsi", 0, 0, 0, NULL, NULL},//307
    {"Tso", 0, 0, 0, NULL, NULL},//308
    {"Tsu", 0, 0, 0, NULL, NULL},//309
    {"Tsva", 0, 0, 0, NULL, NULL},//310
    {"Tsve", 0, 0, 0, NULL, NULL},//311
    {"Tsvi", 0, 0, 0, NULL, NULL},//312
    {"Tsvo", 0, 0, 0, NULL, NULL},//313
    {"Tsvu", 0, 0, 0, NULL, NULL},//314
    {"Tswa", 0, 0, 0, NULL, NULL},//315
    {"Tswe", 0, 0, 0, NULL, NULL},//316
    {"Tswi", 0, 0, 0, NULL, NULL},//317
    {"Tswo", 0, 0, 0, NULL, NULL},//318
    {"Tswu", 0, 0, 0, NULL, NULL},//319
    {"Tu", 0, 0, 0, NULL, NULL},//320
    {"Twa", 0, 0, 0, NULL, NULL},//321
    {"Twe", 0, 0, 0, NULL, NULL},//322
    {"Twi", 0, 0, 0, NULL, NULL},//323
    {"Two", 0, 0, 0, NULL, NULL},//324
    {"Twu", 0, 0, 0, NULL, NULL},//325
    {"U", 0, 0, 0, NULL, NULL},//326
    {"V", 0, 0, 0, NULL, NULL},//327
    {"Va", 0, 0, 0, NULL, NULL},//328
    {"Ve", 0, 0, 0, NULL, NULL},//329
    {"Vha", 0, 0, 0, NULL, NULL},//330
    {"Vhe", 0, 0, 0, NULL, NULL},//331
    {"Vhi", 0, 0, 0, NULL, NULL},//332
    {"Vho", 0, 0, 0, NULL, NULL},//333
    {"Vhu", 0, 0, 0, NULL, NULL},//334
    {"Vi", 0, 0, 0, NULL, NULL},//335
    {"Vo", 0, 0, 0, NULL, NULL},//336
    {"Vu", 0, 0, 0, NULL, NULL},//337
    {"W", 0, 0, 0, NULL, NULL},//338
    {"Wa", 0, 0, 0, NULL, NULL},//339
    {"We", 0, 0, 0, NULL, NULL},//340
    {"Wi", 0, 0, 0, NULL, NULL},//341
    {"Wo", 0, 0, 0, NULL, NULL},//342
    {"Wu", 0, 0, 0, NULL, NULL},//343
    {"X", 0, 0, 0, NULL, NULL},//344
    {"Y", 0, 0, 0, NULL, NULL},//345
    {"Ya", 0, 0, 0, NULL, NULL},//346
    {"Ye", 0, 0, 0, NULL, NULL},//347
    {"Yi", 0, 0, 0, NULL, NULL},//348
    {"Yo", 0, 0, 0, NULL, NULL},//349
    {"Yu", 0, 0, 0, NULL, NULL},//350
    {"Z", 0, 0, 0, NULL, NULL},//351
    {"Za", 0, 0, 0, NULL, NULL},//352
    {"Ze", 0, 0, 0, NULL, NULL},//353
    {"Zha", 0, 0, 0, NULL, NULL},//354
    {"Zhe", 0, 0, 0, NULL, NULL},//355
    {"Zhi", 0, 0, 0, NULL, NULL},//356
    {"Zho", 0, 0, 0, NULL, NULL},//357
    {"Zhu", 0, 0, 0, NULL, NULL},//358
    {"Zhwa", 0, 0, 0, NULL, NULL},//359
    {"Zhwe", 0, 0, 0, NULL, NULL},//360
    {"Zhwi", 0, 0, 0, NULL, NULL},//361
    {"Zhwo", 0, 0, 0, NULL, NULL},//362
    {"Zhwu", 0, 0, 0, NULL, NULL},//363
    {"Zi", 0, 0, 0, NULL, NULL},//364
    {"Zo", 0, 0, 0, NULL, NULL},//365
    {"Zu", 0, 0, 0, NULL, NULL},//366
    {"Zva", 0, 0, 0, NULL, NULL},//367
    {"Zve", 0, 0, 0, NULL, NULL},//368
    {"Zvi", 0, 0, 0, NULL, NULL},//369
    {"Zvo", 0, 0, 0, NULL, NULL},//370
    {"Zvu", 0, 0, 0, NULL, NULL},//371
    {"Zwa", 0, 0, 0, NULL, NULL},//372
    {"Zwe", 0, 0, 0, NULL, NULL},//373
    {"Zwi", 0, 0, 0, NULL, NULL},//374
    {"Zwo", 0, 0, 0, NULL, NULL},//375
    {"Zwu", 0, 0, 0, NULL, NULL},//376
    {"[", 0, 0, 0, NULL, NULL},//377
    {"\\", 0, 0, 0, NULL, NULL},//378
    {"]", 0, 0, 0, NULL, NULL},//379
    {"^", 0, 0, 0, NULL, NULL},//380
    {"_", 0, 0, 0, NULL, NULL},//381
    {"`", 0, 0, 0, NULL, NULL},//382
    {"a", 0, 0, 0, NULL, NULL},//383
    {"b", 0, 0, 0, NULL, NULL},//384
    {"ba", 0, 0, 0, NULL, NULL},//385
    {"be", 0, 0, 0, NULL, NULL},//386
    {"bha", 0, 0, 0, NULL, NULL},//387
    {"bhe", 0, 0, 0, NULL, NULL},//388
    {"bhi", 0, 0, 0, NULL, NULL},//389
    {"bho", 0, 0, 0, NULL, NULL},//390
    {"bhu", 0, 0, 0, NULL, NULL},//391
    {"bi", 0, 0, 0, NULL, NULL},//392
    {"bo", 0, 0, 0, NULL, NULL},//393
    {"bu", 0, 0, 0, NULL, NULL},//394
    {"bva", 0, 0, 0, NULL, NULL},//395
    {"bve", 0, 0, 0, NULL, NULL},//396
    {"bvi", 0, 0, 0, NULL, NULL},//397
    {"bvo", 0, 0, 0, NULL, NULL},//398
    {"bvu", 0, 0, 0, NULL, NULL},//399
    {"bwa", 0, 0, 0, NULL, NULL},//400
    {"bwe", 0, 0, 0, NULL, NULL},//401
    {"bwi", 0, 0, 0, NULL, NULL},//402
    {"bwo", 0, 0, 0, NULL, NULL},//403
    {"bwu", 0, 0, 0, NULL, NULL},//404
    {"c", 0, 0, 0, NULL, NULL},//405
    {"cha", 0, 0, 0, NULL, NULL},//406
    {"che", 0, 0, 0, NULL, NULL},//407
    {"chi", 0, 0, 0, NULL, NULL},//408
    {"cho", 0, 0, 0, NULL, NULL},//409
    {"chu", 0, 0, 0, NULL, NULL},//410
    {"chwa", 0, 0, 0, NULL, NULL},//411
    {"chwe", 0, 0, 0, NULL, NULL},//412
    {"chwi", 0, 0, 0, NULL, NULL},//413
    {"chwo", 0, 0, 0, NULL, NULL},//414
    {"chwu", 0, 0, 0, NULL, NULL},//415
    {"d", 0, 0, 0, NULL, NULL},//416
    {"da", 0, 0, 0, NULL, NULL},//417
    {"de", 0, 0, 0, NULL, NULL},//418
    {"dha", 0, 0, 0, NULL, NULL},//419
    {"dhe", 0, 0, 0, NULL, NULL},//420
    {"dhi", 0, 0, 0, NULL, NULL},//421
    {"dho", 0, 0, 0, NULL, NULL},//422
    {"dhu", 0, 0, 0, NULL, NULL},//423
    {"di", 0, 0, 0, NULL, NULL},//424
    {"do", 0, 0, 0, NULL, NULL},//425
    {"du", 0, 0, 0, NULL, NULL},//426
    {"dya", 0, 0, 0, NULL, NULL},//427
    {"dye", 0, 0, 0, NULL, NULL},//428
    {"dyi", 0, 0, 0, NULL, NULL},//429
    {"dyo", 0, 0, 0, NULL, NULL},//430
    {"dyu", 0, 0, 0, NULL, NULL},//431
    {"dza", 0, 0, 0, NULL, NULL},//432
    {"dze", 0, 0, 0, NULL, NULL},//433
    {"dzi", 0, 0, 0, NULL, NULL},//434
    {"dzo", 0, 0, 0, NULL, NULL},//435
    {"dzu", 0, 0, 0, NULL, NULL},//436
    {"dzva", 0, 0, 0, NULL, NULL},//437
    {"dzve", 0, 0, 0, NULL, NULL},//438
    {"dzvi", 0, 0, 0, NULL, NULL},//439
    {"dzvo", 0, 0, 0, NULL, NULL},//440
    {"dzvu", 0, 0, 0, NULL, NULL},//441
    {"dzwa", 0, 0, 0, NULL, NULL},//442
    {"dzwe", 0, 0, 0, NULL, NULL},//443
    {"dzwi", 0, 0, 0, NULL, NULL},//444
    {"dzwo", 0, 0, 0, NULL, NULL},//445
    {"dzwu", 0, 0, 0, NULL, NULL},//446
    {"e", 0, 0, 0, NULL, NULL},//447
    {"f", 0, 0, 0, NULL, NULL},//448
    {"fa", 0, 0, 0, NULL, NULL},//449
    {"fe", 0, 0, 0, NULL, NULL},//450
    {"fi", 0, 0, 0, NULL, NULL},//451
    {"fo", 0, 0, 0, NULL, NULL},//452
    {"fu", 0, 0, 0, NULL, NULL},//453
    {"g", 0, 0, 0, NULL, NULL},//454
    {"ga", 0, 0, 0, NULL, NULL},//455
    {"ge", 0, 0, 0, NULL, NULL},//456
    {"gi", 0, 0, 0, NULL, NULL},//457
    {"go", 0, 0, 0, NULL, NULL},//458
    {"gu", 0, 0, 0, NULL, NULL},//459
    {"gwa", 0, 0, 0, NULL, NULL},//460
    {"gwe", 0, 0, 0, NULL, NULL},//461
    {"gwi", 0, 0, 0, NULL, NULL},//462
    {"gwo", 0, 0, 0, NULL, NULL},//463
    {"gwu", 0, 0, 0, NULL, NULL},//464
    {"h", 0, 0, 0, NULL, NULL},//465
    {"ha", 0, 0, 0, NULL, NULL},//466
    {"he", 0, 0, 0, NULL, NULL},//467
    {"hi", 0, 0, 0, NULL, NULL},//468
    {"ho", 0, 0, 0, NULL, NULL},//469
    {"hu", 0, 0, 0, NULL, NULL},//470
    {"hwa", 0, 0, 0, NULL, NULL},//471
    {"hwe", 0, 0, 0, NULL, NULL},//472
    {"hwi", 0, 0, 0, NULL, NULL},//473
    {"hwo", 0, 0, 0, NULL, NULL},//474
    {"hwu", 0, 0, 0, NULL, NULL},//475
    {"i", 0, 0, 0, NULL, NULL},//476
    {"j", 0, 0, 0, NULL, NULL},//477
    {"ja", 0, 0, 0, NULL, NULL},//478
    {"je", 0, 0, 0, NULL, NULL},//479
    {"ji", 0, 0, 0, NULL, NULL},//480
    {"jo", 0, 0, 0, NULL, NULL},//481
    {"ju", 0, 0, 0, NULL, NULL},//482
    {"k", 0, 0, 0, NULL, NULL},//483
    {"ka", 0, 0, 0, NULL, NULL},//484
    {"ke", 0, 0, 0, NULL, NULL},//485
    {"ki", 0, 0, 0, NULL, NULL},//486
    {"ko", 0, 0, 0, NULL, NULL},//487
    {"ku", 0, 0, 0, NULL, NULL},//488
    {"kwa", 0, 0, 0, NULL, NULL},//489
    {"kwe", 0, 0, 0, NULL, NULL},//490
    {"kwi", 0, 0, 0, NULL, NULL},//491
    {"kwo", 0, 0, 0, NULL, NULL},//492
    {"kwu", 0, 0, 0, NULL, NULL},//493
    {"l", 0, 0, 0, NULL, NULL},//494
    {"m", 0, 0, 0, NULL, NULL},//495
    {"ma", 0, 0, 0, NULL, NULL},//496
    {"mba", 0, 0, 0, NULL, NULL},//497
    {"mbe", 0, 0, 0, NULL, NULL},//498
    {"mbi", 0, 0, 0, NULL, NULL},//499
    {"mbo", 0, 0, 0, NULL, NULL},//500
    {"mbu", 0, 0, 0, NULL, NULL},//501
    {"mbwa", 0, 0, 0, NULL, NULL},//502
    {"mbwe", 0, 0, 0, NULL, NULL},//503
    {"mbwi", 0, 0, 0, NULL, NULL},//504
    {"mbwo", 0, 0, 0, NULL, NULL},//505
    {"mbwu", 0, 0, 0, NULL, NULL},//506
    {"me", 0, 0, 0, NULL, NULL},//507
    {"mha", 0, 0, 0, NULL, NULL},//508
    {"mhe", 0, 0, 0, NULL, NULL},//509
    {"mhi", 0, 0, 0, NULL, NULL},//510
    {"mho", 0, 0, 0, NULL, NULL},//511
    {"mhu", 0, 0, 0, NULL, NULL},//512
    {"mi", 0, 0, 0, NULL, NULL},//513
    {"mo", 0, 0, 0, NULL, NULL},//514
    {"mu", 0, 0, 0, NULL, NULL},//515
    {"mva", 0, 0, 0, NULL, NULL},//516
    {"mve", 0, 0, 0, NULL, NULL},//517
    {"mvi", 0, 0, 0, NULL, NULL},//518
    {"mvo", 0, 0, 0, NULL, NULL},//519
    {"mvu", 0, 0, 0, NULL, NULL},//520
    {"mwa", 0, 0, 0, NULL, NULL},//521
    {"mwe", 0, 0, 0, NULL, NULL},//522
    {"mwi", 0, 0, 0, NULL, NULL},//523
    {"mwo", 0, 0, 0, NULL, NULL},//524
    {"mwu", 0, 0, 0, NULL, NULL},//525
    {"n", 0, 0, 0, NULL, NULL},//526
    {"n'a", 0, 0, 0, NULL, NULL},//527
    {"n'e", 0, 0, 0, NULL, NULL},//528
    {"n'i", 0, 0, 0, NULL, NULL},//529
    {"n'o", 0, 0, 0, NULL, NULL},//530
    {"n'u", 0, 0, 0, NULL, NULL},//531
    {"na", 0, 0, 0, NULL, NULL},//532
    {"nda", 0, 0, 0, NULL, NULL},//533
    {"nde", 0, 0, 0, NULL, NULL},//534
    {"ndi", 0, 0, 0, NULL, NULL},//535
    {"ndo", 0, 0, 0, NULL, NULL},//536
    {"ndu", 0, 0, 0, NULL, NULL},//537
    {"ndwa", 0, 0, 0, NULL, NULL},//538
    {"ndwe", 0, 0, 0, NULL, NULL},//539
    {"ndwi", 0, 0, 0, NULL, NULL},//540
    {"ndwo", 0, 0, 0, NULL, NULL},//541
    {"ndwu", 0, 0, 0, NULL, NULL},//542
    {"ne", 0, 0, 0, NULL, NULL},//543
    {"nga", 0, 0, 0, NULL, NULL},//544
    {"nge", 0, 0, 0, NULL, NULL},//545
    {"ngi", 0, 0, 0, NULL, NULL},//546
    {"ngo", 0, 0, 0, NULL, NULL},//547
    {"ngu", 0, 0, 0, NULL, NULL},//548
    {"ngwa", 0, 0, 0, NULL, NULL},//549
    {"ngwe", 0, 0, 0, NULL, NULL},//550
    {"ngwi", 0, 0, 0, NULL, NULL},//551
    {"ngwo", 0, 0, 0, NULL, NULL},//552
    {"ngwu", 0, 0, 0, NULL, NULL},//553
    {"nha", 0, 0, 0, NULL, NULL},//554
    {"nhe", 0, 0, 0, NULL, NULL},//555
    {"nhi", 0, 0, 0, NULL, NULL},//556
    {"nho", 0, 0, 0, NULL, NULL},//557
    {"nhu", 0, 0, 0, NULL, NULL},//558
    {"ni", 0, 0, 0, NULL, NULL},//559
    {"nja", 0, 0, 0, NULL, NULL},//560
    {"nje", 0, 0, 0, NULL, NULL},//561
    {"nji", 0, 0, 0, NULL, NULL},//562
    {"njo", 0, 0, 0, NULL, NULL},//563
    {"nju", 0, 0, 0, NULL, NULL},//564
    {"no", 0, 0, 0, NULL, NULL},//565
    {"nu", 0, 0, 0, NULL, NULL},//566
    {"nwa", 0, 0, 0, NULL, NULL},//567
    {"nwe", 0, 0, 0, NULL, NULL},//568
    {"nwi", 0, 0, 0, NULL, NULL},//569
    {"nwo", 0, 0, 0, NULL, NULL},//570
    {"nwu", 0, 0, 0, NULL, NULL},//571
    {"nya", 0, 0, 0, NULL, NULL},//572
    {"nye", 0, 0, 0, NULL, NULL},//573
    {"nyi", 0, 0, 0, NULL, NULL},//574
    {"nyo", 0, 0, 0, NULL, NULL},//575
    {"nyu", 0, 0, 0, NULL, NULL},//576
    {"nza", 0, 0, 0, NULL, NULL},//577
    {"nze", 0, 0, 0, NULL, NULL},//578
    {"nzi", 0, 0, 0, NULL, NULL},//579
    {"nzo", 0, 0, 0, NULL, NULL},//580
    {"nzu", 0, 0, 0, NULL, NULL},//581
    {"nzva", 0, 0, 0, NULL, NULL},//582
    {"nzve", 0, 0, 0, NULL, NULL},//583
    {"nzvi", 0, 0, 0, NULL, NULL},//584
    {"nzvo", 0, 0, 0, NULL, NULL},//585
    {"nzvu", 0, 0, 0, NULL, NULL},//586
    {"nzwa", 0, 0, 0, NULL, NULL},//587
    {"nzwe", 0, 0, 0, NULL, NULL},//588
    {"nzwi", 0, 0, 0, NULL, NULL},//589
    {"nzwo", 0, 0, 0, NULL, NULL},//590
    {"nzwu", 0, 0, 0, NULL, NULL},//591
    {"o", 0, 0, 0, NULL, NULL},//592
    {"p", 0, 0, 0, NULL, NULL},//593
    {"pa", 0, 0, 0, NULL, NULL},//594
    {"pe", 0, 0, 0, NULL, NULL},//595
    {"pfa", 0, 0, 0, NULL, NULL},//596
    {"pfe", 0, 0, 0, NULL, NULL},//597
    {"pfi", 0, 0, 0, NULL, NULL},//598
    {"pfo", 0, 0, 0, NULL, NULL},//599
    {"pfu", 0, 0, 0, NULL, NULL},//600
    {"pi", 0, 0, 0, NULL, NULL},//601
    {"po", 0, 0, 0, NULL, NULL},//602
    {"pu", 0, 0, 0, NULL, NULL},//603
    {"pwa", 0, 0, 0, NULL, NULL},//604
    {"pwe", 0, 0, 0, NULL, NULL},//605
    {"pwi", 0, 0, 0, NULL, NULL},//606
    {"pwo", 0, 0, 0, NULL, NULL},//607
    {"pwu", 0, 0, 0, NULL, NULL},//608
    {"q", 0, 0, 0, NULL, NULL},//609
    {"r", 0, 0, 0, NULL, NULL},//610
    {"ra", 0, 0, 0, NULL, NULL},//611
    {"re", 0, 0, 0, NULL, NULL},//612
    {"ri", 0, 0, 0, NULL, NULL},//613
    {"ro", 0, 0, 0, NULL, NULL},//614
    {"ru", 0, 0, 0, NULL, NULL},//615
    {"rwa", 0, 0, 0, NULL, NULL},//616
    {"rwe", 0, 0, 0, NULL, NULL},//617
    {"rwi", 0, 0, 0, NULL, NULL},//618
    {"rwo", 0, 0, 0, NULL, NULL},//619
    {"rwu", 0, 0, 0, NULL, NULL},//620
    {"s", 0, 0, 0, NULL, NULL},//621
    {"sa", 0, 0, 0, NULL, NULL},//622
    {"se", 0, 0, 0, NULL, NULL},//623
    {"sha", 0, 0, 0, NULL, NULL},//624
    {"she", 0, 0, 0, NULL, NULL},//625
    {"shi", 0, 0, 0, NULL, NULL},//626
    {"sho", 0, 0, 0, NULL, NULL},//627
    {"shu", 0, 0, 0, NULL, NULL},//628
    {"shwa", 0, 0, 0, NULL, NULL},//629
    {"shwe", 0, 0, 0, NULL, NULL},//630
    {"shwi", 0, 0, 0, NULL, NULL},//631
    {"shwo", 0, 0, 0, NULL, NULL},//632
    {"shwu", 0, 0, 0, NULL, NULL},//633
    {"si", 0, 0, 0, NULL, NULL},//634
    {"so", 0, 0, 0, NULL, NULL},//635
    {"su", 0, 0, 0, NULL, NULL},//636
    {"sva", 0, 0, 0, NULL, NULL},//637
    {"sve", 0, 0, 0, NULL, NULL},//638
    {"svi", 0, 0, 0, NULL, NULL},//639
    {"svo", 0, 0, 0, NULL, NULL},//640
    {"svu", 0, 0, 0, NULL, NULL},//641
    {"swa", 0, 0, 0, NULL, NULL},//642
    {"swe", 0, 0, 0, NULL, NULL},//643
    {"swi", 0, 0, 0, NULL, NULL},//644
    {"swo", 0, 0, 0, NULL, NULL},//645
    {"swu", 0, 0, 0, NULL, NULL},//646
    {"t", 0, 0, 0, NULL, NULL},//647
    {"ta", 0, 0, 0, NULL, NULL},//648
    {"te", 0, 0, 0, NULL, NULL},//649
    {"ti", 0, 0, 0, NULL, NULL},//650
    {"to", 0, 0, 0, NULL, NULL},//651
    {"tsa", 0, 0, 0, NULL, NULL},//652
    {"tse", 0, 0, 0, NULL, NULL},//653
    {"tsi", 0, 0, 0, NULL, NULL},//654
    {"tso", 0, 0, 0, NULL, NULL},//655
    {"tsu", 0, 0, 0, NULL, NULL},//656
    {"tsva", 0, 0, 0, NULL, NULL},//657
    {"tsve", 0, 0, 0, NULL, NULL},//658
    {"tsvi", 0, 0, 0, NULL, NULL},//659
    {"tsvo", 0, 0, 0, NULL, NULL},//660
    {"tsvu", 0, 0, 0, NULL, NULL},//661
    {"tswa", 0, 0, 0, NULL, NULL},//662
    {"tswe", 0, 0, 0, NULL, NULL},//663
    {"tswi", 0, 0, 0, NULL, NULL},//664
    {"tswo", 0, 0, 0, NULL, NULL},//665
    {"tswu", 0, 0, 0, NULL, NULL},//666
    {"tu", 0, 0, 0, NULL, NULL},//667
    {"twa", 0, 0, 0, NULL, NULL},//668
    {"twe", 0, 0, 0, NULL, NULL},//669
    {"twi", 0, 0, 0, NULL, NULL},//670
    {"two", 0, 0, 0, NULL, NULL},//671
    {"twu", 0, 0, 0, NULL, NULL},//672
    {"u", 0, 0, 0, NULL, NULL},//673
    {"v", 0, 0, 0, NULL, NULL},//674
    {"va", 0, 0, 0, NULL, NULL},//675
    {"ve", 0, 0, 0, NULL, NULL},//676
    {"vha", 0, 0, 0, NULL, NULL},//677
    {"vhe", 0, 0, 0, NULL, NULL},//678
    {"vhi", 0, 0, 0, NULL, NULL},//679
    {"vho", 0, 0, 0, NULL, NULL},//680
    {"vhu", 0, 0, 0, NULL, NULL},//681
    {"vi", 0, 0, 0, NULL, NULL},//682
    {"vo", 0, 0, 0, NULL, NULL},//683
    {"vu", 0, 0, 0, NULL, NULL},//684
    {"w", 0, 0, 0, NULL, NULL},//685
    {"wa", 0, 0, 0, NULL, NULL},//686
    {"we", 0, 0, 0, NULL, NULL},//687
    {"wi", 0, 0, 0, NULL, NULL},//688
    {"wo", 0, 0, 0, NULL, NULL},//689
    {"wu", 0, 0, 0, NULL, NULL},//690
    {"x", 0, 0, 0, NULL, NULL},//691
    {"y", 0, 0, 0, NULL, NULL},//692
    {"ya", 0, 0, 0, NULL, NULL},//693
    {"ye", 0, 0, 0, NULL, NULL},//694
    {"yi", 0, 0, 0, NULL, NULL},//695
    {"yo", 0, 0, 0, NULL, NULL},//696
    {"yu", 0, 0, 0, NULL, NULL},//697
    {"z", 0, 0, 0, NULL, NULL},//698
    {"za", 0, 0, 0, NULL, NULL},//699
    {"ze", 0, 0, 0, NULL, NULL},//700
    {"zha", 0, 0, 0, NULL, NULL},//701
    {"zhe", 0, 0, 0, NULL, NULL},//702
    {"zhi", 0, 0, 0, NULL, NULL},//703
    {"zho", 0, 0, 0, NULL, NULL},//704
    {"zhu", 0, 0, 0, NULL, NULL},//705
    {"zhwa", 0, 0, 0, NULL, NULL},//706
    {"zhwe", 0, 0, 0, NULL, NULL},//707
    {"zhwi", 0, 0, 0, NULL, NULL},//708
    {"zhwo", 0, 0, 0, NULL, NULL},//709
    {"zhwu", 0, 0, 0, NULL, NULL},//710
    {"zi", 0, 0, 0, NULL, NULL},//711
    {"zo", 0, 0, 0, NULL, NULL},//712
    {"zu", 0, 0, 0, NULL, NULL},//713
    {"zva", 0, 0, 0, NULL, NULL},//714
    {"zve", 0, 0, 0, NULL, NULL},//715
    {"zvi", 0, 0, 0, NULL, NULL},//716
    {"zvo", 0, 0, 0, NULL, NULL},//717
    {"zvu", 0, 0, 0, NULL, NULL},//718
    {"zwa", 0, 0, 0, NULL, NULL},//719
    {"zwe", 0, 0, 0, NULL, NULL},//720
    {"zwi", 0, 0, 0, NULL, NULL},//721
    {"zwo", 0, 0, 0, NULL, NULL},//722
    {"zwu", 0, 0, 0, NULL, NULL},//723
    {"{", 0, 0, 0, NULL, NULL},//724
    {"|", 0, 0, 0, NULL, NULL},//725
    {"}", 0, 0, 0, NULL, NULL},//726
    {"~", 0, 0, 0, NULL, NULL},//727
};

const int NODE_COUNT = 728;

/**
 This is the list of index pairs corresponding to each of the printable characters. The range specifies the indexes over which the syllables starting with the character occur in the node_list above.
*/
const int printable_char_ranges[98][2] = {
    {0, 0}, //\t 0
    {1, 1}, //\n 1
    {2, 2}, //\r 2
    {3, 3}, //  3
    {4, 4}, //! 4
    {5, 5}, //" 5
    {6, 6}, //# 6
    {7, 7}, //$ 7
    {8, 8}, //% 8
    {9, 9}, //& 9
    {10, 10}, //' 10
    {11, 11}, //( 11
    {12, 12}, //) 12
    {13, 13}, //* 13
    {14, 14}, //+ 14
    {15, 15}, //, 15
    {16, 16}, //- 16
    {17, 17}, //. 17
    {18, 18}, /// 18
    {19, 19}, //0 19
    {20, 20}, //1 20
    {21, 21}, //2 21
    {22, 22}, //3 22
    {23, 23}, //4 23
    {24, 24}, //5 24
    {25, 25}, //6 25
    {26, 26}, //7 26
    {27, 27}, //8 27
    {28, 28}, //9 28
    {29, 29}, //: 29
    {30, 30}, //; 30
    {31, 31}, //< 31
    {32, 32}, //= 32
    {33, 33}, //> 33
    {34, 34}, //? 34
    {35, 35}, //@ 35
    {36, 36}, //A 36
    {37, 57}, //B 37
    {58, 68}, //C 38
    {69, 99}, //D 39
    {100, 100}, //E 40
    {101, 106}, //F 41
    {107, 117}, //G 42
    {118, 128}, //H 43
    {129, 129}, //I 44
    {130, 135}, //J 45
    {136, 146}, //K 46
    {147, 147}, //L 47
    {148, 178}, //M 48
    {179, 244}, //N 49
    {245, 245}, //O 50
    {246, 261}, //P 51
    {262, 262}, //Q 52
    {263, 273}, //R 53
    {274, 299}, //S 54
    {300, 325}, //T 55
    {326, 326}, //U 56
    {327, 337}, //V 57
    {338, 343}, //W 58
    {344, 344}, //X 59
    {345, 350}, //Y 60
    {351, 376}, //Z 61
    {377, 377}, //[ 62
    {378, 378}, //backslash 63
    {379, 379}, //] 64
    {380, 380}, //^ 65
    {381, 381}, //_ 66
    {382, 382}, //` 67
    {383, 383}, //a 68
    {384, 404}, //b 69
    {405, 415}, //c 70
    {416, 446}, //d 71
    {447, 447}, //e 72
    {448, 453}, //f 73
    {454, 464}, //g 74
    {465, 475}, //h 75
    {476, 476}, //i 76
    {477, 482}, //j 77
    {483, 493}, //k 78
    {494, 494}, //l 79
    {495, 525}, //m 80
    {526, 591}, //n 81
    {592, 592}, //o 82
    {593, 608}, //p 83
    {609, 609}, //q 84
    {610, 620}, //r 85
    {621, 646}, //s 86
    {647, 672}, //t 87
    {673, 673}, //u 88
    {674, 684}, //v 89
    {685, 690}, //w 90
    {691, 691}, //x 91
    {692, 697}, //y 92
    {698, 723}, //z 93
    {724, 724}, //{ 94
    {725, 725}, //| 95
    {726, 726}, //} 96
    {727, 727}, //~ 97
};

