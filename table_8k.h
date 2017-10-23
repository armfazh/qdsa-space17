/**
 * Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
 * Institute of Computing.
 * University of Campinas, Brazil.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/
#ifndef CREF_TABLE_8K_H
#define CREF_TABLE_8K_H

#include <stdint.h>

static const uint64_t Table_Ladder_8k [256 * 4] = {
/*   0 */ 0xfffffffffffffff3, 0xffffffffffffffff, 0xffffffffffffffff, 0x5fffffffffffffff,
/*   1 */ 0x6b8220f416aafe96, 0x82ebeb2b4f566a34, 0xd5a9a5b075a5950f, 0x5142b2cf4b2488f4,
/*   2 */ 0x6aaebc750069680c, 0x89cf7820a0f99c41, 0x2a58d9183b56d0f4, 0x4b5aca80e36011a4,
/*   3 */ 0x329132348c29745d, 0xf4a2e616e1642fd7, 0x1e45bb03ff67bc34, 0x306912d0f42a9b4a,
/*   4 */ 0xff886507e6af7154, 0x04f50e13dfeec82f, 0xaa512fe82abab5ce, 0x174e251a68d5f222,
/*   5 */ 0xcf96700d82028898, 0x1743e3370a2c02c5, 0x379eec98b4e86eaa, 0x0c59888a51e0482e,
/*   6 */ 0xfbcbf1d699b5d189, 0xacaef0d58e9fdc84, 0xc1c20d06231f7614, 0x2938218da274f972,
/*   7 */ 0xf6af49beff1d7f18, 0xcc541c22387ac9c2, 0x96fcc9ef4015c56b, 0x69c1627c690913a9,
/*   8 */ 0x7a86fd2f4733db0e, 0xfdb8c4f29e087de9, 0x095e4b1a8ea2a229, 0x1ad7a7c829b37a79,
/*   9 */ 0x342d89cad17ea0c0, 0x67bedda6cced2051, 0x19ca31bf2bb42f74, 0x3df7b4c84980acbb,
/*  10 */ 0xa8c6444dc80ad883, 0xb91e440366e3ab85, 0xc215cda00164f6d8, 0x3d867c6ef247e668,
/*  11 */ 0xc7dd582bcc3e658c, 0xfd2c4748ee0e5528, 0xa0fd9b95cc9f4f71, 0x7529d871b0675ddf,
/*  12 */ 0xb8f568b42d3cbd78, 0x1233011b91f3da82, 0x2dce6ccd4a7c3b62, 0x75e7fc8e9e498603,
/*  13 */ 0x2f4f13f1fcd0b6ec, 0xf1a8ca1f29ff7a45, 0xc249c1a72981e29b, 0x6ebe0dbb8c83b56a,
/*  14 */ 0x7114fa8d170bb222, 0x65a2dcd5bf93935f, 0xbdc41f68b59c979a, 0x2f0eef79a2ce9289,
/*  15 */ 0x42ecbf0c083c37ce, 0x2930bc09ec496322, 0xf294b0c19cfeac0d, 0x3780aa4bedfabb80,
/*  16 */ 0x56c17d3e7cead929, 0xe7cb4beb2e5722c5, 0x0ce931732dbfe15a, 0x41b883c7621052f8,
/*  17 */ 0xdbf75ca0c3d25350, 0x2936be086eb1e351, 0xc936e03cb4a9b212, 0x1d45bf82322225aa,
/*  18 */ 0xe81ab1036a024cc5, 0xe212201c304c9a72, 0xc5d73fba6832b1fc, 0x20ffdb5a4d839581,
/*  19 */ 0xa283d367be5d0fad, 0x6c2b25ca8b164475, 0x9d4935467caaf22e, 0x5166408eee85ff49,
/*  20 */ 0x3c67baa2fab4e361, 0xb3e433c67ef35cef, 0x5259729241159b1c, 0x6a621892d5b0ab33,
/*  21 */ 0x20b74a387555cdcb, 0x532aa10e1208923f, 0xeaa17b7762281dd1, 0x61ab3443f05c44bf,
/*  22 */ 0x257a6c422324def8, 0x131c6c1017e3cf7f, 0x23758739f630a257, 0x295a407a01a78580,
/*  23 */ 0xf8c443246d5da8d9, 0x19d775450c52fa5d, 0x2afcfc92731bf83d, 0x7d10c8e81b2b4700,
/*  24 */ 0xc8e0271f70baa20b, 0x993748867ca63957, 0x5412efb3cb7ed4bb, 0x3196d36173e62975,
/*  25 */ 0xde5bcad141c7dffc, 0x47cc8cd2b395c848, 0xa34cd942e11af3cb, 0x0256dbf2d04ecec2,
/*  26 */ 0x875ab7e94b0e667f, 0xcad4dd83c0850d10, 0x47f12e8f4e72c79f, 0x5f1a87bb8c85b19b,
/*  27 */ 0x7ae9d0b6437f51b8, 0x12c7ce5518879065, 0x2ade09fe5cf77aee, 0x23a05a2f7d2c5627,
/*  28 */ 0x5908e128f17c169a, 0xf77498dd8ad0852d, 0x74b4c4ceab102f64, 0x183abadd10139845,
/*  29 */ 0xb165ba8daa92aaac, 0xd5c5ef9599386705, 0xbe2f8f0cf8fc40d1, 0x2701e635ee204514,
/*  30 */ 0x629fa80020156514, 0xf223868764a8c1ce, 0x5b894fff0b3f060e, 0x60d9944cf708a3fa,
/*  31 */ 0xaeea001a1c7a201f, 0xebf16a633ee2ce63, 0x6f7709594c7a07e1, 0x79b958150d0208cb,
/*  32 */ 0x24b55e5301d410e7, 0xe3a34edff3fdc84d, 0xd88768e4904032d8, 0x131384427b3aaeec,
/*  33 */ 0x8405e51286234f14, 0x14dc4739adb4c529, 0xb8a2b5b250634ffd, 0x2fe2a94ad8a7ff93,
/*  34 */ 0xec5c57efe843fadd, 0x2843ce40f0bb9918, 0xa4b561d6cf3d6305, 0x743629bde8fb777e,
/*  35 */ 0x343edd46bbaf738f, 0xed981828b101a651, 0xa401760b882c797a, 0x1fc223e28dc88730,
/*  36 */ 0x48604e91fc0fba0e, 0xb637f78f052c6fa4, 0x91ccac3d09e9239c, 0x23f7eed4437a687c,
/*  37 */ 0x5173b1118d9bd800, 0x29d641b63189d4a7, 0xfdbf177988bbc586, 0x2959894fcad81df5,
/*  38 */ 0xaebc8ef3b4bbc899, 0x4148995ab26992b9, 0x24e20b0134f92cfb, 0x40d158894a05dee8,
/*  39 */ 0x46b00b1185af76f6, 0x26bac77873187a79, 0x3dc0bf95ab8fff5f, 0x2a608bd8945524d7,
/*  40 */ 0x26449588bd446302, 0x7c4bc21c0388439c, 0x8e98a4f383bd11b2, 0x26218d7bc9d876b9,
/*  41 */ 0xe3081542997c178a, 0x3c2d29a86fb6606f, 0x5c217736fa279374, 0x7dde05734afeb1fa,
/*  42 */ 0x3bf10e3906d42bab, 0xe4f7803e1980649c, 0xe6053bf89595bf7a, 0x394faf38da245530,
/*  43 */ 0x7a8efb58896928f4, 0xfbc778e9cc6a113c, 0x72670ce330af596f, 0x48f222a81d3d6cf7,
/*  44 */ 0xf01fce410d72caa7, 0x5a20ecc7213b5595, 0x7bc21165c1fa1483, 0x07f89ae31da8a741,
/*  45 */ 0x05d2c2b4c6830ff9, 0xd43e330fc6316293, 0xa5a5590a96d3a904, 0x705edb91a65333b6,
/*  46 */ 0x048ee15e0bb9a5f7, 0x3240cfca9e0aaf5d, 0x8f4b71ceedc4a40b, 0x621c0da3de544a6d,
/*  47 */ 0x92872836a08c4091, 0xce8375b010c91445, 0x8a72eb524f276394, 0x2667fcfa7ec83635,
/*  48 */ 0x7f4c173345e8752a, 0x061b47feee7079a5, 0x25dd9afa9f86ff34, 0x3780cef5425dc89c,
/*  49 */ 0x1a46035a513bb4e9, 0x3e1ef379ac575ada, 0xc78c5f1c5fa24b50, 0x321a967634fd9f22,
/*  50 */ 0x946707b8826e27fa, 0x3dca84d64c506fd0, 0xc189218075e91436, 0x6d9284169b3b8484,
/*  51 */ 0x3a67e840383f2ddf, 0x33eec9a30c4f9b75, 0x3ec7c86fa783ef47, 0x26ec449fbac9fbc4,
/*  52 */ 0x5c0f38cba09b9e7d, 0x81168cc762a3478c, 0x3e23b0d306fc121c, 0x5a238aa0a5efdcdd,
/*  53 */ 0x1ba26121c4ea43ff, 0x36f8c77f7c8832b5, 0x88fbea0b0adcf99a, 0x5ca9938ec25bebf9,
/*  54 */ 0xd5436a5e51fccda0, 0x1dbc4797c2cd893b, 0x19346a65d3224a08, 0x0f5034e49b9af466,
/*  55 */ 0xf23c3967a1e0b96e, 0xe58b08fa867a4d88, 0xfb2fabc6a7341679, 0x2a75381eb6026946,
/*  56 */ 0xc80a3be4c19420ac, 0x66b1f6c681f2b6dc, 0x7cf7036761e93388, 0x25abbbd8a660a4c4,
/*  57 */ 0x91ea12ba14fd5198, 0x684950fc4a3cffa9, 0xf826842130f5ad28, 0x3ea988f75301a441,
/*  58 */ 0xc978109a695f8c6f, 0x1746eb4a0530c3f3, 0x444d6d77b4459995, 0x75952b8c054e5cc7,
/*  59 */ 0xa3703f7915f4d6aa, 0x66c346202f2647d8, 0xd01469df811d644b, 0x77fea47d81a5d71f,
/*  60 */ 0xc5e9529ef57ca381, 0x6eeeb4b9ce2f881a, 0xb6e91a28e8009bd6, 0x4b80be3e9afc3fec,
/*  61 */ 0x7e3773c526aed2c5, 0x1b4afcb453c9a49d, 0xa920bdd7baffb24d, 0x7c54699f122d400e,
/*  62 */ 0xef46c8e14fa94bc8, 0xe0b074ce2952ed5e, 0xbea450e1dbd885d5, 0x61b68649320f712c,
/*  63 */ 0x8a485f7309ccbdd1, 0xbd06320d7d4d1a2d, 0x25232973322dbef4, 0x445dc4758c17f770,
/*  64 */ 0xdb0434177cc8933c, 0xed6fe82175ea059f, 0x1efebefdc053db34, 0x4adbe867c65daf99,
/*  65 */ 0x3acd71a2a90609df, 0xe5e991856dd04050, 0x1ec69b688157c23c, 0x697427f6885cfe4d,
/*  66 */ 0xd7be7b9b65e1a851, 0xa03d28d522c536dd, 0x28399d658fd2b645, 0x49e5b7e17c2641e1,
/*  67 */ 0x6f8c3a98700457a4, 0x5078f0a25ebb6778, 0xd13c3ccbc382960f, 0x2e003258a7df84b1,
/*  68 */ 0x8ad1f39be6296a1c, 0xc1eeaa652a5fbfb2, 0x33ee0673fd26f3cb, 0x59256173a69d2ccc,
/*  69 */ 0x41ea07aa4e18fc41, 0xd9fc19527c87a51e, 0xbdaacb805831ca6f, 0x445b652dc916694f,
/*  70 */ 0xce92a3a7f2172315, 0x1edc282de11b9964, 0xa1823aafe04c314a, 0x790a2d94437cf586,
/*  71 */ 0x71c447fb93f6e009, 0x8922a56722845276, 0xbf70903b204f5169, 0x2f7a89891ba319fe,
/*  72 */ 0x02a08eb577e2140c, 0xed9a4ed4427bdcf4, 0x5253ec44e4323cd1, 0x3e88363c14e9355b,
/*  73 */ 0xaa66c14277110b8c, 0x1ae0391610a23390, 0x2030bd12c93fc2a2, 0x3ee141579555c7ab,
/*  74 */ 0x9214de3a6d6e7d41, 0x3ccdd88607f17efe, 0x674f1288f8e11217, 0x5682250f329f93d0,
/*  75 */ 0x6cf00b136d2e396e, 0x6e4cf86f1014debf, 0x5930b1b5bfcc4e83, 0x047069b48aba16b6,
/*  76 */ 0x0d4ce4ab69b20793, 0xb24db91a97d0fb9e, 0xcdfa50f54e00d01d, 0x221b1085368bddb5,
/*  77 */ 0xe7e59468b1e3d8d2, 0x53c56563bd122f93, 0xeee8a903e0663f09, 0x61efa662cbbe3d42,
/*  78 */ 0x2cf8ddddde6eab2a, 0x9bf80ad51435f231, 0x5deadacec9f04973, 0x29275b5d41d29b27,
/*  79 */ 0xcfde0f0895ebf14f, 0xb9aab96b054905a7, 0xcae80dd9a1c420fd, 0x0a63bf2f1673bbc7,
/*  80 */ 0x092f6e11958fbc8c, 0x672a81e804822fad, 0xcac8351560d52517, 0x6f3f7722c8f192f8,
/*  81 */ 0xf8ba90ccc2e894b7, 0x2c7557a438ff9f0d, 0x894d1d855ae52359, 0x68e122157b743d69,
/*  82 */ 0xd87e5570cfb919f3, 0x3f2cdecd95798db9, 0x2121154710c0a2ce, 0x3c66a115246dc5b2,
/*  83 */ 0xcbedc562294ecb72, 0xba7143c36a280b16, 0x9610c2efd4078b67, 0x6144735d946a4b1e,
/*  84 */ 0x536f111ed75b3350, 0x0211db8c2041d81b, 0xf93cb1000e10413c, 0x149dfd3c039e8876,
/*  85 */ 0xd479dde46b63155b, 0xb66e15e93c837976, 0xdafde43b1f13e038, 0x5fafda1a2e4b0b35,
/*  86 */ 0x3600bbdf17197581, 0x3972050bbe3cd2c2, 0x5938906dbdd5be86, 0x34fce5e43f9b860f,
/*  87 */ 0x75a8a4cd42d14d02, 0x828dabc53441df65, 0x33dcabedd2e131d3, 0x3ebad76fb814d25f,
/*  88 */ 0xd4906f566f70e10f, 0x5d12f7aa51690f5a, 0x45adb16e76cefcf2, 0x01f768aead232999,
/*  89 */ 0x2b6cc77b6248febd, 0x3cd30628ec3aaffd, 0xce1c0b80d4ef486a, 0x4c3bff2ea6f66c23,
/*  90 */ 0x3f2ec4094aeaeb5f, 0x61b19b286e372ca7, 0x5eefa966de2a701d, 0x23b20565de55e3ef,
/*  91 */ 0xe301ca5279d58557, 0x07b2d4ce27c2874f, 0xa532cd8a9dcf1d67, 0x2a52fee23f2bff56,
/*  92 */ 0x8624efb37cd8663d, 0xbbc7ac20ffbd7594, 0x57b85e9c82d37445, 0x7b3052cb86a6ec66,
/*  93 */ 0x3482f0ad2525e91e, 0x2cb68043d28edca0, 0xaf4f6d052e1b003a, 0x185f8c2529781b0a,
/*  94 */ 0xaa41de5bd80ce0d6, 0x9407b2416853e9d6, 0x563ec36e357f4c3a, 0x4cc4b8dd0e297bce,
/*  95 */ 0xa2fc1a52ffb8730e, 0x1811f16e67058e37, 0x10f9a366cddf4ee1, 0x72f4a0c4a0b9f099,
/*  96 */ 0x8c16c06f663f4ea7, 0x693b3af74e970fba, 0x2102e7f1d69ec345, 0x0ba53cbc968a8089,
/*  97 */ 0xca3d9dc7fea15537, 0x4c6824bb51536493, 0xb9886314844006b1, 0x40d2a72ab454cc60,
/*  98 */ 0x5936a1b712570975, 0x91b9d648debda657, 0x3344094bb64330ea, 0x006ba10d12ee51d0,
/*  99 */ 0x19228468f5de5d58, 0x0eb12f4c38cc05b0, 0xa1039f9dd5601990, 0x4502d4ce4fff0e0b,
/* 100 */ 0xeb2054106837c189, 0xd0f6544c6dd3b93c, 0x40727064c416d74f, 0x6e15c6114b502ef0,
/* 101 */ 0x4df2a398cfb1a76b, 0x11256c7419f2f6b1, 0x4a497962066e6043, 0x705b3aab41355b44,
/* 102 */ 0x365ef536d797b1d8, 0x00076bd622ddf0db, 0x3bbf33b0e0575a88, 0x3777aa05c8e4ca4d,
/* 103 */ 0x392745c85578db5f, 0x6fda4149dbae5ae2, 0xb1f0b00b8adc9867, 0x09963437d36f1da3,
/* 104 */ 0x7e824e90a5dc3853, 0xccb5f6641f135cbd, 0x6736d86c87ce8fcc, 0x625f3ce26604249f,
/* 105 */ 0xaf8ac8059502f63f, 0x0c05e70a2e351469, 0x35292e9c764b6305, 0x1a394360c7e23ac3,
/* 106 */ 0xd5c6d53251183264, 0x62065abd43c2b74f, 0xb5fbf5d03b973f9b, 0x13a3da3661206e5e,
/* 107 */ 0xc6bd5837725d94e5, 0x18e30912205016c5, 0x2088ce1570033c68, 0x7fba1f495c837987,
/* 108 */ 0x5a8c7423f2f9079d, 0x1735157b34023fc5, 0xe4f9b49ad2fab351, 0x6691ff72c878e33c,
/* 109 */ 0x122c2adedc5eff3e, 0xf8dd4bf1d8956cf4, 0xeb86205d9e9e5bda, 0x049b92b9d975c743,
/* 110 */ 0xa5379730b0f6c05a, 0x72a0ffacc6f3a553, 0xb0032c34b20dcd6d, 0x470e9dbc88d5164a,
/* 111 */ 0xb19cf10ca237c047, 0xb65466711f6c81a2, 0xb3321bd16dd80b43, 0x48c14f600c5fbe8e,
/* 112 */ 0x66451c264aa6c803, 0xb66e3904a4fa7da6, 0xd45f19b0b3128395, 0x31602627c3c9bc10,
/* 113 */ 0x3120dc4832e4e10d, 0xeb20c46756c717f7, 0x00f52e3f67280294, 0x566d4fc14730c509,
/* 114 */ 0x7e3a5d40fd837206, 0xc1e926dc7159547a, 0x216730fba68d6095, 0x22e8c3843f69cea7,
/* 115 */ 0x33d074e8930e4b2b, 0xb6e4350e84d15816, 0x5534c26ad6ba2365, 0x7773c12f89f1f3f3,
/* 116 */ 0x8cba404da57962aa, 0x5b9897a81999ce56, 0x508e862f121692fc, 0x3a81907fa093c291,
/* 117 */ 0x0dded0ff4725a510, 0x10d8cc10673fc503, 0x5b9d151c9f1f4e89, 0x32a5c1d5cb09a44c,
/* 118 */ 0x1e0aa442b90541fb, 0x5f85eb7cc1b485db, 0xbee595ce8a9df2e5, 0x25e496c722422236,
/* 119 */ 0x5edf3c46cd0fe5b9, 0x34e75a7ed2a43388, 0xe488de11d761e352, 0x0e878a01a085545c,
/* 120 */ 0xba493c77e021bb04, 0x2b4d1843c7df899a, 0x9ea37a487ae80d67, 0x67a9958011e41794,
/* 121 */ 0x4b58051a6697b065, 0x47e33f7d8d6ba6d4, 0xbb4da8d483ca46c1, 0x68becaa181c2db0d,
/* 122 */ 0x8d8980e90b989aa5, 0xf95eb14a2c93c99b, 0x51c6c7c4796e73a2, 0x6e228363b5efb569,
/* 123 */ 0xc6bbc0b02dd624c8, 0x777eb47dec8170ee, 0x3cde15a004cfafa9, 0x1dc6bc087160bf9b,
/* 124 */ 0x2e07e043eec34002, 0x18e9fc677a68dc7f, 0xd8da03188bd15b9a, 0x48fbc3bb00568253,
/* 125 */ 0x57547d4cfb654ce1, 0xd3565b82a058e2ad, 0xf63eaf0bbf154478, 0x47531ef114dfbb18,
/* 126 */ 0xe1ec630a4278c587, 0x5507d546ca8e83f3, 0x85e135c63adc0c2b, 0x0aa7efa85682844e,
/* 127 */ 0x72691ba8b3e1f615, 0x32b4e9701fbe3ffa, 0x97b6d92e39bb7868, 0x2cfe53dea02e39e8,
/* 128 */ 0x687392cd85cd52b0, 0x27ff66c910e29831, 0x97134556a9832d06, 0x269bb0360a84f8a0,
/* 129 */ 0x706e55457643f85c, 0x3734a48c9b597d1b, 0x7aee91e8c6efa472, 0x5cd6abc198a9d9e0,
/* 130 */ 0x0e04de06cb3ce41a, 0xd8c6eb893402e138, 0x904659bb686e3772, 0x7215c371746ba8c8,
/* 131 */ 0xfd12a97eeae4a2d9, 0x9514b7516394f2c5, 0x266fd5809208f294, 0x5c847085619a26b9,
/* 132 */ 0x52985410fed694ea, 0x3c905b934a2ed254, 0x10bb47692d3be467, 0x063b3d2d69e5e9e1,
/* 133 */ 0x472726eedda57deb, 0xefb6c4ae10f41891, 0x2b1641917b307614, 0x117c554fc4f45b7c,
/* 134 */ 0xc07cf3118f9d8812, 0x01dbd82050017939, 0xd7e803f4171b2827, 0x1015e87487d225ea,
/* 135 */ 0xc58de3fed23acc4d, 0x50db91c294a7be2d, 0x0b94d43d1c9cf457, 0x6b1640fa6e37524a,
/* 136 */ 0x692f346c5fda0d09, 0x200b1c59fa4d3151, 0xb8c46f760777a296, 0x4b38395f3ffdfbcf,
/* 137 */ 0x18d25e00be54d671, 0x60d50582bec8aba6, 0x87ad8f263b78b982, 0x50fdf64e9cda0432,
/* 138 */ 0x90f567aac578dcf0, 0xef1e9b0ef2a3133b, 0x0eebba9242d9de71, 0x15473c9bf03101c7,
/* 139 */ 0x7c77e8ae56b78095, 0xb678e7666e6f078e, 0x2da0b9615348ba1f, 0x7cf931c1ff733f0b,
/* 140 */ 0x26b357f50a0a366c, 0xe9708cf42b87d732, 0xc13aeea5f91cb2c0, 0x35d90c991143bb4c,
/* 141 */ 0x47c1c404a9a0d9dc, 0x659e58451972d251, 0x3875a8c473b38c31, 0x1fbd9ed379561f24,
/* 142 */ 0x11fabc6fd41ec28d, 0x7ef8dfe3cd2a2dca, 0x72e73b5d8c404595, 0x6135fa4954b72f27,
/* 143 */ 0xccfc32a2de24b69c, 0x3f55698c1f095d88, 0xbe3350ed5ac3f929, 0x5e9bf806ca477eeb,
/* 144 */ 0xe9ce8fb63c309f68, 0x5376f63565e1f9f4, 0xd1afcfb35a6393f1, 0x6632a1ede5623506,
/* 145 */ 0x0b7d6c390c2ded4c, 0x56cb3281df04cb1f, 0x66305a1249ecc3c7, 0x5d588b60a38ca72a,
/* 146 */ 0xa6ecbf78e8e5f42d, 0x86eeb44b3c8a3eec, 0xec219c48fbd21604, 0x1aaf1af517c36731,
/* 147 */ 0xc306a2836769bde7, 0x208280622b1e2adb, 0x8027f51ffbff94a6, 0x76cfa1ce1124f26b,
/* 148 */ 0x18eb00562422abb6, 0xf377c4d58f8c29c3, 0x4dbbc207f531561a, 0x0253b7f082128a27,
/* 149 */ 0x3d1f091cb62c17e0, 0x4860e1abd64628a9, 0x52d17436309d4253, 0x356f97e13efae576,
/* 150 */ 0xd351e11aa150535b, 0x3e6b45bb1dd878cc, 0x0c776128bed92c98, 0x1d34ae93032885b8,
/* 151 */ 0x4ba0488ca85ba4c3, 0x985348c33c9ce6ce, 0x66124c6f97bda770, 0x0f81a0290654124a,
/* 152 */ 0x9ed09ca6569b86fd, 0x811009fd18af9a2d, 0xff08d03f93d8c20a, 0x52a148199faef26b,
/* 153 */ 0x3e03f9dc2d8d1b73, 0x4205801873961a70, 0xc0d987f041a35970, 0x07aa1f15a1c0d549,
/* 154 */ 0xdfd46ce08cd27224, 0x6d0a024f934e4239, 0x808a7a6399897b59, 0x0a4556e9e13d95a2,
/* 155 */ 0xd21a991fe9c13045, 0x9b0e8548fe7751b8, 0x5da643cb4bf30035, 0x77db28d63940f721,
/* 156 */ 0xfc5eeb614adc9011, 0x5229419ae8c411eb, 0x9ec3e7787d1dcf74, 0x340d053e216e4cb5,
/* 157 */ 0xcac7af39b48df2b4, 0xc0faec2871a10a94, 0x140a69245ca575ed, 0x0cf1c37134273a4c,
/* 158 */ 0xc8ee306ac224b8a5, 0x57eaee7ccb4930b0, 0xa1e806bdaacbe74f, 0x7d9a62742eeb657d,
/* 159 */ 0x9eb6b6ef546c4830, 0x885cca1fddb36e2e, 0xe6b9f383ef0d7105, 0x58654fef9d2e0412,
/* 160 */ 0xa905c4ffbe0e8e26, 0x942de5df9b31816e, 0x497d723f802e88e1, 0x30684dea602f408d,
/* 161 */ 0x21e5a278a3e6cb34, 0xaefb6e6f5b151dc4, 0xb30b8e049d77ca15, 0x28c3c9cf53b98981,
/* 162 */ 0x287fb721556cdd2a, 0x0d317ca897022274, 0x7468c7423a543258, 0x4a7f11464eb5642f,
/* 163 */ 0xa237a4774d193aa6, 0xd865986ea92129a1, 0x24c515ecf87c1a88, 0x604003575f39f5eb,
/* 164 */ 0x47b9f189570a9b27, 0x2b98cede465e4b78, 0x026df551dbb85c20, 0x74fcd91047e21901,
/* 165 */ 0x13e2a90a23c1bfa3, 0x0cb0074e478519f6, 0x5ff1cbbe3af6cf44, 0x67fe5438be812dbe,
/* 166 */ 0xd13cf64fa40f05b0, 0x054dfb2f32283787, 0x4173915b7f0d2aea, 0x482f144f1f610d4e,
/* 167 */ 0xf6210201b47f8234, 0x5d0ae1929e70b990, 0xdcd7f455b049567c, 0x7e93d0f1f0916f01,
/* 168 */ 0xdd79cbf18a7db4fa, 0xbe8391bf6f74c62f, 0x027145d14b8291bd, 0x585a73ea2cbf1705,
/* 169 */ 0x485ca03e928a0db2, 0x10fc01a5742857e7, 0x2f482edbd6d551a7, 0x0f0433b5048fdb8a,
/* 170 */ 0x60da2e8dd7dc6247, 0x88b4c9d38cd4819a, 0x13033ac001f66697, 0x273b24fe3b367d75,
/* 171 */ 0xc6e8f66a31b3b9d4, 0x281514a494df49d5, 0xd1726fdfc8b23da7, 0x4b3ae7d103dee548,
/* 172 */ 0xc6256e19ce4b9d7e, 0xff5c5cf186e3c61c, 0xacc63ca34b8ec145, 0x74621888fee66574,
/* 173 */ 0x956f409645290a1e, 0xef0bf8e3263a962e, 0xed6a50eb5ec2647b, 0x0694283a9dca7502,
/* 174 */ 0x769b963643a2dcd1, 0x42b7c8ea09fc5353, 0x4f002aee13397eab, 0x63005e2c19b7d63a,
/* 175 */ 0xca6736da63023bea, 0x966c7f6db12a99b7, 0xace09390c537c5e1, 0x0b696063a1aa89ee,
/* 176 */ 0xebb03e97288c56e5, 0x432a9f9f938c8be8, 0xa6a5a93d5b717f71, 0x1a5fb4c3e18f9d97,
/* 177 */ 0x1c94e7ad1c60cdce, 0xee202a43fc02c4a0, 0x8dafe4d867c46a20, 0x0a10263c8ac27b58,
/* 178 */ 0xd0dea9dfe4432a4a, 0x856af87bbe9277c5, 0xce8472acc212c71a, 0x6f151b6d9bbb1e91,
/* 179 */ 0x26776c527ceed56a, 0x7d211cb7fbf8faec, 0x37ae66a6fd4609cc, 0x1f81b702d2770c42,
/* 180 */ 0x2fb0b057eac58392, 0xe1dd89fe29744e9d, 0xc964f8eb17beb4f8, 0x29571073c9a2d41e,
/* 181 */ 0xa948a18981c0e254, 0x2df6369b65b22830, 0xa33eb2d75fcfd3c6, 0x078cd6ec4199a01f,
/* 182 */ 0x4a584a41ad900d2f, 0x32142b78e2c74c52, 0x68c4e8338431c978, 0x7f69ea9008689fc2,
/* 183 */ 0x52f2c81e46a38265, 0xfd78072d04a832fd, 0x8cd7d5fa25359e94, 0x4de71b7454cc29d2,
/* 184 */ 0x42eb60ad1eda6ac9, 0x0aad37dfdbc09c3a, 0x81004b71e33cc191, 0x44e6be345122803c,
/* 185 */ 0x03fe8388ba1920db, 0xf5d57c32150db008, 0x49c8c4281af60c29, 0x21edb518de701aee,
/* 186 */ 0x7fb63e418f06dc99, 0xa4460d99c166d7b8, 0x24dd5248ce520a83, 0x5ec3ad712b928358,
/* 187 */ 0x15022a5fbd17930f, 0xa4f64a77d82570e3, 0x12bc8d6915783712, 0x498194c0fc620abb,
/* 188 */ 0x38a2d9d255686c82, 0x785c6bd9193e21f0, 0xe4d5c81ab24a5484, 0x56307860b2e20989,
/* 189 */ 0x429d55f78b4d74c4, 0x22f1834643350131, 0x1e60c24598c71fff, 0x59f2f014979983ef,
/* 190 */ 0x46a47d56eb494a44, 0x3e22a854d636a18e, 0xb346e15274491c3b, 0x2ceafd4e5390cde7,
/* 191 */ 0xba8a8538be0d6675, 0x4b9074bb50818e23, 0xcbdab89085d304c3, 0x61a24fe0e56192c4,
/* 192 */ 0xcb7615e6db525bcb, 0xdd7d8c35a567e4ca, 0xe6b4153acafcdd69, 0x2d668e097f3c9766,
/* 193 */ 0xa57e7e265ce55ef0, 0x5d9f4e527cd4b967, 0xfbc83606492fd1e5, 0x090d52beb7c3f7ae,
/* 194 */ 0x09b9515a1e7b4d7c, 0x1f266a2599da44c0, 0xa1c49548e2c55504, 0x7ef04287126f15cc,
/* 195 */ 0xfed1659dbd30ef15, 0x8b4ab9eec4e0277b, 0x884d6236a5df3291, 0x1fd96ea6bf5cf788,
/* 196 */ 0x42a161981f190d9a, 0x61d849507e6052c1, 0x9fe113bf285a2cd5, 0x7c22d676dbad85d8,
/* 197 */ 0x82e770ed2bfbd27d, 0x4c05b2ece996f5a5, 0xcd40a9c2b0900150, 0x5895319213d9bf64,
/* 198 */ 0xe7cc5d703fea2e08, 0xb50c491258e2188c, 0xcce30baa48205bf0, 0x537c659ccfa32d62,
/* 199 */ 0x37b6623a98cfc088, 0xfe9bed1fa4d6aca4, 0x04d29b8e56a8d1b0, 0x725f71c40b519575,
/* 200 */ 0x28c7f89cd0339ce6, 0x8367b14469ddc18b, 0x883ada83a6a1652c, 0x585f1974034d6c17,
/* 201 */ 0x89cfb266f1b19188, 0xe63b4863e7c35217, 0xd88c9da6b4c0526a, 0x3e035c9df0954635,
/* 202 */ 0xdd9d5412fb45de9d, 0xdd684532e4cff40d, 0x4b5c999b151d671c, 0x2d8c2cc811e7f690,
/* 203 */ 0x7f54be1d90055d40, 0xa464c5df464aaf40, 0x33979624f0e917be, 0x2c018dc527356b30,
/* 204 */ 0xa5415024e330b3d4, 0x73ff3d96691652d3, 0x94ec42c4ef9b59f1, 0x0747201618d08e5a,
/* 205 */ 0x4d6ca48aca411c53, 0x66415f2fcfa66119, 0x9c4dd40051e227ff, 0x59810bc09a02f7eb,
/* 206 */ 0x2a7eb171b3dc101d, 0x441c5ab99ffef68e, 0x32025c9b93b359ea, 0x5e8ce0a71e9d112f,
/* 207 */ 0xbfcccb92429503fd, 0xd271ba752f095d55, 0x345ead5e972d091e, 0x18c8df11a83103ba,
/* 208 */ 0x90cd949a9aed0f4c, 0xc5d1f4cb6660e37e, 0xb8cac52d56c52e0b, 0x6e42e400c5808e0d,
/* 209 */ 0xa3b46966eeaefd23, 0x0c4f1f0be39ecdca, 0x189dc8c9d683a51d, 0x51f27f054c09351b,
/* 210 */ 0x4c487ccd2a320682, 0x587ea95bb3df1c96, 0xc8ccf79e555cb8e8, 0x547dc829a206d73d,
/* 211 */ 0xb822a6cd80c39b06, 0xe96d54732000d4c6, 0x28535b6f91463b4d, 0x228f4660e2486e1d,
/* 212 */ 0x98799538de8d3abf, 0x8cd8330045ebca6e, 0x79952a008221e738, 0x4322e1a7535cd2bb,
/* 213 */ 0xb114c11819d1801c, 0x2016e4d84f3f5ec7, 0xdd0e2df409260f4c, 0x5ec362c0ae5f7266,
/* 214 */ 0xc0462b18b8b2b4ee, 0x7cc8d950274d1afb, 0xf25f7105436b02d2, 0x43bbf8dcbff9ccd3,
/* 215 */ 0xb6ad1767a039e9df, 0xb0714da8f69d3583, 0x5e55fa18b42931f5, 0x4ed5558f33c60961,
/* 216 */ 0x1fe37901c647a5dd, 0x593ddf1f8081d357, 0x0249a4fd813fd7a6, 0x69acca274e9caf61,
/* 217 */ 0x047ba3ea330721c9, 0x83423fc20e7e1ea0, 0x1df4c0af01314a60, 0x09a62dab89289527,
/* 218 */ 0xa5b325a49cc6cb00, 0xe94b5dc654b56cb6, 0x3be28779adc994a0, 0x4296e8f8ba3a4aad,
/* 219 */ 0x328689761e451eab, 0x2e4d598bff59594a, 0x49b96853d7a7084a, 0x4980a319601420a8,
/* 220 */ 0x9565b9e12f552c42, 0x8a5318db7100fe96, 0x05c90b4d43add0d7, 0x538b4cd66a5d4eda,
/* 221 */ 0xf4e94fc3e89f039f, 0x592c9af26f618045, 0x08a36eb5fd4b9550, 0x25fffaf6c2ed1419,
/* 222 */ 0x34434459cc79d354, 0xeeecbfb4b1d5476b, 0xddeb34a061615d99, 0x5129cecceb64b773,
/* 223 */ 0xee43215894993520, 0x772f9c7cf14c0b3b, 0xd2e2fce306bedad5, 0x715f42b546f06a97,
/* 224 */ 0x434ecdceda5b5f1a, 0x0da17115a49741a9, 0x680bd77c73edad2e, 0x487c02354edd9041,
/* 225 */ 0xb8efeff3a70ed9c4, 0x56a32aa3e857e302, 0xdf3a68bd48a2a5a0, 0x07f650b73176c444,
/* 226 */ 0xe38b9b1626e0ccb1, 0x79e053c18b09fb36, 0x56d90319c9f94964, 0x1ca941e7ac9ff5c4,
/* 227 */ 0x49c4df29162fa0bb, 0x8488cf3282b33305, 0x95dfda14cabb437d, 0x3391f78264d5ad86,
/* 228 */ 0x729ae06ae2b5095d, 0xd58a58d73259a946, 0xe9834262d13921ed, 0x27fedafaa54bb592,
/* 229 */ 0xa99dc5b829ad48bb, 0x5f025742499ee260, 0x802c8ecd5d7513fd, 0x78ceb3ef3f6dd938,
/* 230 */ 0xc342f44f8a135d94, 0x7b9edb44828cdda3, 0x9436d11a0537cfe7, 0x5064b164ec1ab4c8,
/* 231 */ 0x7020eccfd37eb2fc, 0x1f31ea3ed90d25fc, 0x1b930d7bdfa1bb34, 0x5344467a48113044,
/* 232 */ 0x70073170f25e6dfb, 0xe385dc1a50114cc8, 0x2348698ac8fc4f00, 0x2a77a55284dd40d8,
/* 233 */ 0xfe06afe0c98c6ce4, 0xc235df96dddfd6e4, 0x1428d01e33bf1ed3, 0x785768ec9300bdaf,
/* 234 */ 0x9702e57a91deb63b, 0x61bdb8bfe5ce8b80, 0x645b426f3d1d58ac, 0x4804a82227a557bc,
/* 235 */ 0x8e57048ab44d2601, 0x68d6501a4b3a6935, 0xc39c9ec3f9e1c293, 0x4172f257d4de63e2,
/* 236 */ 0xd368b450330c6401, 0x040d3017418f2391, 0x2c34bb6090b7d90d, 0x16f649228fdfd51f,
/* 237 */ 0xbea6818e2b928ef5, 0xe28ccf91cdc11e72, 0x594aaa68e77a36cd, 0x313034806c7ffd0f,
/* 238 */ 0x8a9d27ac2249bd65, 0x19a3b464018e9512, 0xc26ccff352b37ec7, 0x056f68341d797b21,
/* 239 */ 0x5e79d6757efd2327, 0xfabdbcb6553afe15, 0xd3e7222c6eaf5a60, 0x7046c76d4dae743b,
/* 240 */ 0x660be872b18d4a55, 0x19992518574e1496, 0xc103053a302bdcbb, 0x3ed8e9800b218e8e,
/* 241 */ 0x7b0b9239fa75e03e, 0xefe9fb684633c083, 0x98a35fbe391a7793, 0x6065510fe2d0fe34,
/* 242 */ 0x55cb668548abad0c, 0xb4584548da87e527, 0x2c43ecea0107c1dd, 0x526028809372de35,
/* 243 */ 0x3415c56af9213b1f, 0x5bee1a4d017e98db, 0x13f6b105b5cf709b, 0x5ff20e3482b29ab6,
/* 244 */ 0x0aa29c75cc2e6c90, 0xfc7d73ca3a70e206, 0x899fc38fc4b5c515, 0x250386b124ffc207,
/* 245 */ 0x54ea28d5ae3d2b56, 0x9913149dd6de60ce, 0x16694fc58f06d6c1, 0x46b23975eb018fc7,
/* 246 */ 0x470a6a0fb4b7b4e2, 0x5d92475a8f7253de, 0xabeee5b52fbd3adb, 0x7fa20801a0806968,
/* 247 */ 0x76f3faf19f7714d2, 0xb3e840c12f4660c3, 0x0fb4cd8df212744e, 0x4b065a251d3a2dd2,
/* 248 */ 0x5cebde383d77cd4a, 0x6adf39df882c9cb1, 0xa2dd242eb09af759, 0x3147c0e50e5f6422,
/* 249 */ 0x164ca5101d1350db, 0xf8d13479c33fc962, 0xe640ce4d13e5da08, 0x4bdee0c45061f8ba,
/* 250 */ 0xd7c46dc1a4edb1c9, 0x5514d7b6437fd98a, 0x58942f6bb2a1c00b, 0x2dffb2ab1d70710e,
/* 251 */ 0xccdfcf2fc18b6d68, 0xa8ebcba8b7806167, 0x980697f95e2937e3, 0x02fbba1cd0126e8c,
/* 252 */ 0xcb98c360adff4565, 0x447101d24bdb1519, 0x98c4c87475fb15d5, 0x05f8c76d6e22a27d,
/* 253 */ 0xab69e5dffeb9f494, 0xae09c79d18406b75, 0x199b45fb94a42d1d, 0x79710aebae2afa84,
/* 254 */ 0xa6adeda7f334d2df, 0x7bde9c51af2a57b4, 0xa98fc64f86dceaa8, 0x6bbe0335c20ed07b,
/* 255 */ 0x667fdcbe53984344, 0x0772bc1c005949a8, 0xba07a49f4ebed68e, 0x1fa7b085badf30bf
};
#endif /* CREF_TABLE_8K_H */
