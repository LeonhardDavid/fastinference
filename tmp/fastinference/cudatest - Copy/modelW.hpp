static int cuda_layer_2_output[4*26*26*32];
static int layer_2_output[4][26][26][32];

static unsigned int cuda_layer_3_output[4*26*26*1*32];
static unsigned int layer_3_output[4][26][26][1];

static unsigned int cuda_layer_4_output[4*13*13*1*32];
static unsigned int layer_4_output[4][13][13][1];

static signed int cuda_layer_5_output[4*11*11*32];
static signed int layer_5_output[4][11][11][32];

static unsigned int cuda_layer_6_output[4*11*11*1*32];
static unsigned int layer_6_output[4][11][11][1];

static unsigned int cuda_layer_7_output[4*5*5*1*32];
static unsigned int layer_7_output[4][5][5][1];

static signed int cuda_layer_9_output[4*32];
static signed int layer_9_output[4][32];

static unsigned int cuda_layer_10_output[4*1*32];
static unsigned int layer_10_output[4][1];

static signed int cuda_layer_11_output[4*10];
static signed int layer_11_output[4][10];


static constexpr signed char layer_2_weight[3][3][1][32] = {{{{-1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, -1, 1}}, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, 1, -1, 1, -1, -1}}, {{1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1}}}, {{{1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1}}, {{1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1}}, {{1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, -1, -1, 1}}}, {{{-1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1}}, {{-1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1}}, {{1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1}}}};
static constexpr signed char layer_2_bias[32] = {1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1};
static constexpr signed int layer_3_threshold[32] = {29060, -7003, 10294, 52813, 28965, 40503, 11442, -48859, -29015, -25889, -27019, 51135, -31505, 6876, -8319, 10310, -27011, -8837, 9297, -11538, -13110, -11860, 6954, -36007, 9608, -9877, 32375, 54826, 57230, -8536, -27075, 9853};
static constexpr unsigned int layer_5_weight[3][3][32][1] = {{{{0x25ec13c0}, {0x9f91823a}, {0x91398e46}, {0x15ecb966}, {0x7e5ab21f}, {0xa06a8442}, {0x741fa9ee}, {0xefee913b}, {0x23e900d0}, {0xf935689d}, {0x714a76ec}, {0xc4cb137b}, {0x21c40909}, {0x33e617fe}, {0x11e23c98}, {0x79615cf2}, {0x79ca8bf8}, {0x18919605}, {0xfefceef7}, {0xcda6e316}, {0xd5c38620}, {0x410c0672}, {0xa357a38}, {0x81ada828}, {0x5c2a613b}, {0xbe7bc46}, {0xd1eac863}, {0x20ada073}, {0xb89d0e0d}, {0xe5203f60}, {0x64e4eee5}, {0xc9ec8760}}, {{0x40a8f4a7}, {0x903226a0}, {0x3de4256f}, {0x3ffcb772}, {0xd5bbbdda}, {0x87132c2a}, {0xd41f305e}, {0x37fe9ff6}, {0xabfd64d7}, {0x7935befe}, {0x79e6dd57}, {0xab06fe5f}, {0xaa1b4cb9}, {0x305a9903}, {0x51c647e6}, {0x4a63dbdb}, {0xc3f6dcab}, {0xf8052150}, {0x4ff6b9da}, {0xbcca99de}, {0x973fd93}, {0xf715844f}, {0x25d5cc56}, {0x7c6259a8}, {0xa7b3c84f}, {0xe5a991bf}, {0xa73bcab1}, {0x272d0e1f}, {0x23c46205}, {0x6d04858a}, {0xc1ea110f}, {0xad64eac7}}, {{0x1e1de23b}, {0xbf15e089}, {0x156d86f5}, {0x8bfea1d6}, {0xdfd1b3ae}, {0xb885eeb9}, {0x396e4654}, {0x99f4efd5}, {0x3baaf182}, {0xbfcadce6}, {0x3deab746}, {0xc9b377b0}, {0xea952823}, {0xe8f94230}, {0x1cfdd46}, {0xcb98d897}, {0xda02109a}, {0x10103439}, {0x4aead51c}, {0xd8436072}, {0xff93d1bb}, {0xd7372ab9}, {0xe3ca15c7}, {0x42efe4cf}, {0x93f1ef6b}, {0x60e692d2}, {0xbed642bb}, {0xdbb5e4bf}, {0x4b0a8d02}, {0x44c97b9f}, {0x86085a22}, {0xaba4afd4}}}, {{{0x1fc230f}, {0x296c0f93}, {0xc3df8196}, {0x93c2f5c2}, {0xc5a4a461}, {0x11ce8942}, {0x39770ebc}, {0x67eb6d5f}, {0x9aebf142}, {0xef102ad4}, {0x6a1877db}, {0xec5f6e71}, {0x59dc1d66}, {0xeffa576d}, {0x3b8b63d3}, {0xbc3100b6}, {0xa9e18e54}, {0xbfb306d2}, {0x2ef576eb}, {0xd064e4d3}, {0x7f2457ce}, {0x11f9a540}, {0xb60c6a5d}, {0x94943aaa}, {0xebef0841}, {0x5fedf498}, {0x53f83943}, {0xfb64b681}, {0x13b4cd16}, {0xbdcfbf4}, {0x2fa367b5}, {0x432ae1d2}}, {{0x81ac96e9}, {0x50e10ec0}, {0x1befe132}, {0xac2c1ca}, {0xa5efe4e6}, {0x557d3dce}, {0x1d716e7e}, {0xafede7f7}, {0xa73fd192}, {0x364c667c}, {0x39a3d5fb}, {0xafe4e4f3}, {0x83e6b716}, {0xc04a9842}, {0x92d8bb8d}, {0x6208c4d1}, {0xd3e8a49b}, {0x287006ec}, {0xeec333e7}, {0xbdf4fadf}, {0xcbbcc4ff}, {0x43f3084d}, {0x72f1cc85}, {0x444e120b}, {0xa3fdcce1}, {0x8e3efb72}, {0x3d5ddef7}, {0xcf25d693}, {0x4a6b4d4e}, {0xd89b7174}, {0x1cb1901}, {0x33c695c2}}, {{0x18d3433f}, {0x3f350e40}, {0x5fcff104}, {0x4b1ed18a}, {0x14bca6d4}, {0x216c85a6}, {0xd8b544d2}, {0xcbeef1d6}, {0x4bc2f012}, {0xfedf76b7}, {0x4333739c}, {0xefd7eeb9}, {0xd1bf4f6a}, {0xa8800a4d}, {0xb259d22b}, {0xcd3090d3}, {0xcf65a6fe}, {0xde20a4bb}, {0xeaeaf6f5}, {0xfe74e2b1}, {0xfe66aae7}, {0x8f994ad8}, {0x5fb5005}, {0x14ae35d8}, {0xc3f0c78f}, {0x9f56e4b5}, {0xc16f78b8}, {0xbc65aeb3}, {0x791106}, {0x96fa497d}, {0x160b588d}, {0xbc6fd4a}}}, {{{0xd208ff0a}, {0xc3fbdc16}, {0x8352b21a}, {0x1f776094}, {0x4bfb9d52}, {0x1506509e}, {0x8c186e6f}, {0xebeabbde}, {0x439a4440}, {0x5686d4b}, {0x3c5fe2b8}, {0x53ee1ce6}, {0xd201f998}, {0x618a9b07}, {0xcc1373d9}, {0xdc906e99}, {0xe367c53d}, {0x3e89c05}, {0xf6d2e8dd}, {0x68e9b6e6}, {0x3b6c9f52}, {0xe36e9567}, {0x3e042ed4}, {0xdc142e9d}, {0x928b6192}, {0x9fd9b780}, {0x413a1f24}, {0x296786c5}, {0x9a5722e2}, {0xb5137637}, {0x47ee8507}, {0x6cc1f834}}, {{0x8bd9e477}, {0xdd82558}, {0xa3f234ba}, {0xba65c13d}, {0x3bbfa576}, {0x4f26758e}, {0x1238462d}, {0x4ea3f1db}, {0xa20280b7}, {0xbd9f3f47}, {0x3a16772c}, {0xb9d440f}, {0x1a9b642}, {0xc2932c13}, {0x8e16f28d}, {0x9c40bab9}, {0xbe50b1bb}, {0x45ed1f4d}, {0x65c2cffd}, {0xe7e7afe6}, {0x4aa3499f}, {0x63db1d06}, {0x55d856f}, {0xb5286f6c}, {0x2bfadaa3}, {0x78f69eed}, {0x776d8f79}, {0x31e4bd67}, {0x17b939b}, {0x828a4919}, {0x448a3b21}, {0xfc7329a3}}, {{0xfe13e9bb}, {0x1481d07}, {0x4928e0d2}, {0xb5c74949}, {0x8dffbd12}, {0x13d8d12}, {0x39df932d}, {0x5babb4d8}, {0xba456184}, {0x896e96e6}, {0x3e546698}, {0xa2d63027}, {0x554391a3}, {0xf638a9b9}, {0xfa534091}, {0xf4e59ecd}, {0x8f75a6d2}, {0x65a89f45}, {0xbdd0eafd}, {0xd3fcabf7}, {0xba316d10}, {0x822a8f6d}, {0x415e4904}, {0x5504f66f}, {0x8eaef18a}, {0x9ef8e56d}, {0xd2a05b39}, {0xe5ed8dd6}, {0x5653701a}, {0xfc5ee2a9}, {0xd57175eb}, {0x67bf4d0e}}}};
static constexpr signed char layer_5_bias[32] = {-1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1};
static constexpr signed char layer_6_threshold[32] = {-2, -8, 11, 16, 26, 4, -4, 45, 3, 12, 5, 8, 4, 7, -4, -6, 0, -9, 22, 14, 11, 10, 6, -6, 17, 12, 10, -1, -5, 0, 13, 23};
static constexpr unsigned int layer_9_weight[32][25] = {{0xf91a0284, 0x408e0629, 0xc9b62af4, 0x13f9a329, 0x814c43a8, 0x529f0c4f, 0x80b7b7f7, 0x31b3a6, 0xd4c6cbc, 0x3d17896c, 0x56065024, 0x42634304, 0x82472210, 0xb99a1019, 0xd21e7c30, 0xcc080e08, 0x247e320, 0x8a214b36, 0xa11d20e6, 0xe14c6022, 0xcc0c0e2e, 0x8644d5c2, 0x833b1398, 0xc12bfc66, 0x298aa0ab}, {0x3a49357a, 0x6fe8c2f7, 0xddbc347, 0x6df32565, 0x34ba3646, 0x6fdef1b3, 0x758805ba, 0x844c4e1e, 0x825f152f, 0x8366052c, 0xb4ff34d2, 0x29ae0ae6, 0xfcac6c8f, 0xc00e462a, 0x8c244422, 0x16072e21, 0xd197208c, 0xc0f1388e, 0x468d0382, 0xfdb9c8bb, 0x8c04253f, 0x11302f0c, 0x954c4e9a, 0xfcc8561a, 0x38939c61}, {0x25a61aee, 0xbbb71e0e, 0xb9904e2f, 0x359caeff, 0xbeffbdf7, 0xfd844b4f, 0xd6440141, 0x14230309, 0xf4bb4e3f, 0x7f51fcb2, 0x398d41a, 0xcc084c00, 0x4e1a5e08, 0xe7b4706, 0x35008eb9, 0x6dbabee7, 0x71fe7fa9, 0x6a9f577c, 0x464c4ea2, 0x6e809ad8, 0xf9ba2e7b, 0xd1ec6eab, 0xcb0c510f, 0x94260712, 0x37ae044f}, {0x13d1b9d0, 0x98c9ed5c, 0x7597dbc, 0x6f33067, 0x33d00a3c, 0x83f1b171, 0xc9e94030, 0x5c9a484c, 0x803f25d6, 0x80275126, 0x1f68a491, 0x8dee1e36, 0xd7dd7dd2, 0x8717358, 0x6bd8f9a2, 0x30c390c6, 0xf5a53c8d, 0xc6445776, 0x3fef281d, 0x30eb2405, 0xabf6169, 0xc087eb56, 0x126b8587, 0x91a3b04c, 0xb133b344}, {0x8aed559b, 0x37af7c6f, 0xb7e4976f, 0xe5bdfcc3, 0xbef6e5, 0x39178b2d, 0xf797b97b, 0xfcb0fa3, 0x92971b6b, 0xc2e3772a, 0x5097a400, 0x62b7830c, 0xedee4419, 0xc216842f, 0x9267a31f, 0xad98555e, 0x5cfc78f9, 0xf88cdeeb, 0x649df38a, 0x2a5cda93, 0xb1a80442, 0xf984068f, 0xf98c76af, 0xc44c45a2, 0xfd8c462b}, {0x3d17bb11, 0xd3edfe16, 0x89a9e9c7, 0x9f0df1c4, 0x9580530d, 0xa261fdd4, 0x8265f975, 0x8bd0f974, 0x4a51f154, 0x9323fb4d, 0x4e466c10, 0x4e1bdf05, 0x814dfd76, 0xb33ba70, 0x6f45f394, 0x856a0819, 0x8b67b4d0, 0x6bd0d8b3, 0x3d86cb5, 0x7ad1623b, 0xbc37c1b9, 0xf9ee4a81, 0xb1f7a087, 0xe336a9af, 0x263e32e}, {0xf8274445, 0x818c0a24, 0xf59f880f, 0xc18d9080, 0xcc285318, 0x55be28eb, 0xc0510c80, 0xcc1cfa30, 0x6ec8e2b0, 0x6cc8ae49, 0xc49ef8ea, 0x84812302, 0xf5ac30ed, 0xe1ce468e, 0xc08d4c2c, 0xd50c5dce, 0xe874a0e0, 0x19e33a8e, 0xc587160f, 0xa58446ce, 0xa21cbfcc, 0x22bb7a6, 0x549a4ac0, 0xcdc5e2b, 0x60dffdf3}, {0x9bde1ff, 0x13e02396, 0x60c25347, 0x32ba266f, 0x36f32e86, 0x6a0e8224, 0x6d88060b, 0x55a04e0b, 0x84894722, 0x473c2aa2, 0x7094d4fb, 0x91e6b2af, 0x2da3a70b, 0x640c032b, 0xf40e062f, 0x724f5513, 0x94b9c920, 0x4e38029e, 0xbcae062d, 0x7ca9c02d, 0x73def9d7, 0x7efb8933, 0x36cc5c3b, 0x2a05de75, 0x433d9f1}, {0x6b8c5fac, 0x23606a8, 0x291c4aaa, 0xc900c6b2, 0x493bfd00, 0x3c84ba4f, 0x40ffc340, 0x6d8e358, 0x6dc8ded1, 0x7ed8f9d5, 0x4c0ec470, 0x40094438, 0x4e18421d, 0xffcc2ef7, 0xed4c5c55, 0x798d44c9, 0x2f322af, 0x11a72328, 0xbfae1e66, 0x2b3928ea, 0x7f83458f, 0x650d0f4, 0x7238b40, 0x28ba9bdd, 0x7824e013}, {0x195b9243, 0xbbbdb9fa, 0x3bc3f357, 0x36f3b14f, 0x34b2bf4f, 0x94206698, 0xb1b0dbbe, 0x6f48cbf4, 0xa709ce0, 0x3733d74, 0x1d0dc616, 0xb70b9d3, 0x2663e151, 0x1733d93c, 0x4f7f6fae, 0x17722924, 0xbb7098f5, 0x2759cc91, 0xdb67b875, 0xd9ef160f, 0x4e4ff110, 0x19f3a970, 0xb5722a7d, 0x2a9bbaef, 0x9272bd44}, {0x86c7fbce, 0x7fbdf94e, 0xf6de51ec, 0x76bfa648, 0xb6eb39d5, 0xf2529b6d, 0xfb3a3682, 0xfdbb8449, 0x38a7819c, 0x72dd669a, 0x4cabff9b, 0x9ef3f7d6, 0x6b9dadca, 0x76238768, 0x7ca70289, 0x2566fadf, 0xed08cdfb, 0xfd8cccfb, 0xe40e4499, 0x4204021b, 0xb9f37d73, 0xf5ff2e0f, 0xf98c746f, 0xf605658a, 0xc8a4460a}, {0xfd9c8daa, 0xbd23646c, 0x91086184, 0xcc8ccd82, 0xc63ffcf6, 0x930f19ef, 0x609bbc59, 0x3fc6a699, 0xed8d8ed5, 0x7ff39edd, 0xe0bec784, 0x2c71c6d2, 0x8f798e7b, 0x7e15a561, 0x7f73034b, 0xafe49dfb, 0xffdd9cf1, 0xfdecdcf9, 0xde56d0f4, 0x49474a99, 0xf9ae6f7a, 0xf5bc2cbb, 0xf9ec74eb, 0xe4cd479a, 0x8088662f}, {0xd0616eb7, 0xc8a9b93e, 0xec40f913, 0x66671250, 0x726d0f2d, 0xfc78d6b1, 0xbffc499a, 0x7d18cc95, 0x7ec1d419, 0x76004ef9, 0xbdfdeafb, 0xbded3cfb, 0x7bb29c5b, 0x77e96fc9, 0x7cbc0ea9, 0x13e7b3ff, 0xfda998fd, 0x7fd8a8f9, 0x56662245, 0x50a21e0c, 0x377fb70, 0x79fbbdcd, 0x78a1ac31, 0xf59e9a90, 0xf652dde0}, {0x6190009b, 0x40201601, 0x339276af, 0x6c76aea7, 0xefff2f6, 0x5f0d5eeb, 0x6518a64a, 0x25a2278b, 0xf5ac06ab, 0x7d8886ab, 0xfd1fb9ef, 0xd3a18226, 0x2a2828b, 0xfdef0f8f, 0x1dae044f, 0xf3b987ed, 0x45258a4, 0x2613a2cb, 0x79e7020a, 0xe83f8256, 0x747197db, 0xca51f974, 0x6a495798, 0x58889e70, 0x73f3ddf5}, {0x35cfe1b6, 0x46fde994, 0xe4b6c90, 0x1904c030, 0x6c44c572, 0x5f41e826, 0x54084112, 0x4e8cc05a, 0xf58c739f, 0xfc8dd6b1, 0x3fb805e8, 0xf98c0cf3, 0xd3b3b84d, 0x3e73a190, 0xfd889ee9, 0xbdff3e6b, 0xfd977ce5, 0x42d3f170, 0x7bcb2211, 0x598a9ee4, 0xa9ab131, 0xca13fbf5, 0x4c618570, 0x823b244, 0x2233da58}, {0xf6b67138, 0x3ce507d1, 0xc45624a5, 0xae1dbcb0, 0xe2ff780, 0xeb4a12d9, 0x7677b2ee, 0xb38fa44f, 0x24b58af0, 0xfec4fa9b, 0x508b4688, 0x42f37305, 0xcd9ddea8, 0x7dd4c641, 0xb6ab90cd, 0x6e4c7bdf, 0x4e48c79e, 0xfd8a0cbf, 0xec9e446f, 0x52774104, 0xb9f069f2, 0xfffca403, 0xfebff56b, 0x6671f9d2, 0xe9cc6399}, {0x8249e71d, 0x8efb7a96, 0x2a3b4a40, 0xc0044a00, 0x4e0fe076, 0x996a4170, 0x779eec58, 0xdad44e53, 0x6ad9fa42, 0x364efe7b, 0xdbef7afa, 0xd7dfed7a, 0x71f9c2b9, 0xb5cce69f, 0xabb55d9b, 0xfdf7b91b, 0xcccaa7de, 0x19aa2088, 0xc4b69466, 0x1f72f950, 0x9123bbf0, 0xaf112d76, 0xf2bb9a50, 0x6793de15, 0xffd877d3}, {0xfed22ba4, 0x6d3ac2cc, 0xc6283220, 0xc72c352c, 0xcc0c52b8, 0x6a7c98e0, 0x71e606da, 0xf9ac0cef, 0xe58606af, 0x7d8a4689, 0xfda6469f, 0xbde735ef, 0x38e3b866, 0x54ef8809, 0x188b0209, 0x43a6f936, 0x4e08dd5c, 0xec189ce5, 0x42e12100, 0x6225719c, 0xb1abfa65, 0x7dfdb99b, 0xfd9c44b3, 0x6edd5eb3, 0xdc415f58}, {0x99d1c129, 0xbf3cab0, 0x1713d70, 0x67b7f56, 0xc854f5b2, 0x457a5ecf, 0x3fe424bd, 0x9bc42eaa, 0x83172fae, 0xf72e22af, 0xb1f338eb, 0x3fb60a0a, 0xb126b0e7, 0x92a79176, 0xcbf46020, 0xcfac05e9, 0x83226820, 0x5ad7d954, 0x23412310, 0xb6aae6ca, 0xd1cdaefd, 0xa7114b9f, 0xce1c45b8, 0x488c8c72, 0x12739d76}, {0x5de30e2f, 0xd90528bc, 0x2b25cd70, 0xb249d208, 0xc7880329, 0x8bf1f9d6, 0xafe5f993, 0x4fb4f871, 0x3407030, 0x82a1834c, 0x33c7a950, 0x69ccea97, 0x9d9e9c57, 0x8117bce8, 0xe044f380, 0x8d842009, 0xf9b17368, 0x50a3d487, 0xad1f3bc, 0x29488373, 0x49ae9899, 0x90840895, 0x181fc4c2, 0x1cac0d87, 0x974031f5}, {0xf0bc20a8, 0xbff6166b, 0xb8c1be7f, 0x3ff7fecf, 0x3bf3bd77, 0x9daed66a, 0x92373be4, 0x627378c, 0x2f7b9ea3, 0x5f58bdf0, 0x8a42c926, 0x2009170, 0x2632340, 0x3dbb9dd5, 0x1f3f8ff1, 0xaf7cfcfa, 0xc337b576, 0x6e51dc38, 0x4e407509, 0x16e3062f, 0x655d5696, 0xbd7446b3, 0x3b676a5a, 0x8b3f715e, 0x9222451a}, {0x804de11a, 0x9acdedd5, 0x9b218995, 0xfc8101cd, 0xfeaa0e4d, 0xa6f9d590, 0xe35df891, 0xea50d8d0, 0x4a417950, 0x72d2094d, 0xfd4abe3c, 0xdd0cfef9, 0xffd88c71, 0x737d2150, 0x7d18d6b8, 0x37f1aaed, 0xbfbdbdf2, 0xb17a71b5, 0xf4f95679, 0x36ee6518, 0xd4ff7c11, 0x7ebeb83c, 0xb1b62f2c, 0x2094d2ae, 0x91624fb7}, {0x799f21ed, 0xf7f1475f, 0x59ba47cf, 0x4c763c6f, 0x7bd7bd37, 0x99ccab26, 0x96c94403, 0x16a2030b, 0xb6b7a72e, 0xca74303a, 0x2138b87d, 0xf1840caa, 0x749ad28f, 0x86bfc56a, 0xfd14f28f, 0x59fe7cf2, 0x51b67eaf, 0x1097f2ce, 0x6cd1dbb0, 0x3fd8feb9, 0xd7864789, 0x548457bc, 0x460457d6, 0x24280432, 0x363b0bf4}, {0xdf4e4835, 0xacbc3453, 0xe6c65900, 0xdeea8188, 0x9a8de0d6, 0x6125a443, 0xe18449b1, 0xf89be865, 0x30634999, 0x7c99ced0, 0x4c41c5de, 0xcff87d7b, 0xd6199950, 0x7a7b4130, 0x3d800a49, 0xbce1f257, 0xff288c4b, 0xfe48cd79, 0xf76c443b, 0xd0a3022c, 0x12fbfd51, 0x7cabedb1, 0xf4f7252f, 0xe024a8ca, 0x636d4224}, {0xdde14078, 0x38851f1a, 0xbbf7f9eb, 0x37fbb37e, 0x979187af, 0xede8948d, 0xf9a610bf, 0x993fc964, 0x22f2564, 0x80277176, 0xf6902307, 0xd3767d26, 0x2454150, 0x284a90, 0xcf5dd4a0, 0x86880016, 0x6c088f13, 0xef0c50b0, 0xe224603b, 0xea8005aa, 0x76638176, 0x63f14b, 0xa1f1f15f, 0x362301e, 0xddac020b}, {0x8869ff8d, 0xfdece317, 0xf28c4f47, 0x60f38c4d, 0x3680066d, 0x1963b9c4, 0xfdccec1b, 0xf98cc049, 0x2477142, 0x8027433a, 0x31ffaef9, 0xf9bf2cff, 0xf18d10bb, 0xc5cc063a, 0x8cace00a, 0x5092b626, 0x7f8aee8f, 0x998e2b8f, 0xfdbe9de2, 0x5c7bbcd4, 0x186780e8, 0x5cb7111b, 0x54a24f96, 0xf0849e21, 0x5d987a50}, {0x4f3783ab, 0x13753358, 0xb75e737c, 0x41547ab7, 0x8b57f9f2, 0x66484408, 0xcc32374f, 0xe7f23dd, 0x8d299a8f, 0xfb9cfcf3, 0xaecc7a86, 0xda9bf5f4, 0x9a719554, 0x3f79bbd1, 0x3fb99fd5, 0xf271f59f, 0xe86cdf77, 0x6619dd11, 0xbe7bbe75, 0x1a631545, 0xbbf9fddf, 0xef73fb75, 0xb263a1d5, 0x2333b965, 0x4124230e}, {0x79084a29, 0xed844421, 0x884dc8b4, 0xcb41c190, 0x4307d3c8, 0x9f373e4b, 0x93c56dbe, 0x4933d8f4, 0x6fc17091, 0x3c50da9d, 0x7507e009, 0xed8c5ffa, 0xf9bfa9f1, 0x73e9b149, 0x74805e21, 0xb2a08978, 0xad89bd4f, 0x69c97579, 0x8240613c, 0x3026024d, 0x9bf2a861, 0xf8bf0cd0, 0xf5df0ca9, 0x19a68ae5, 0xc058eb44}, {0x783c4aa2, 0xb0ae3e0f, 0xb8c612af, 0xbcabb74f, 0xb8a3adef, 0x908702cb, 0x94a3634e, 0x33f30a, 0x76998f7f, 0x5e597b74, 0x42008586, 0x251d310, 0x4648470a, 0xc51c4c2f, 0x523216ea, 0x660afeb5, 0x29240280, 0xfd8cc6cb, 0xe516448a, 0xe5cc677b, 0xddbc3c9e, 0xf9f0040b, 0xd5dca69f, 0xcfa621ce, 0x98ab0352}, {0x4daf06bc, 0xb65d5491, 0xd1848103, 0x2e84c30e, 0xbcaacf6f, 0xb5b0db1e, 0x3cd6cf40, 0xa854dd10, 0x6249d351, 0x4440f844, 0x52ec5b5b, 0x4ccbcc90, 0x6d8956bb, 0x64d46e2f, 0x70a9067f, 0x4155dffb, 0x7f4a0399, 0xb5ae0eaf, 0xd9ae146f, 0x46af4122, 0xc67f91a0, 0xb18f7b45, 0x3aa79c4f, 0xe4de85c2, 0x43f06233}, {0x82d3b556, 0x563f9d3, 0x69f9ed54, 0xd6d8e5c5, 0x15102a20, 0xbb7175b0, 0xeffab9d1, 0xbbecbdf7, 0x8377b144, 0x83a7053e, 0xb1e72649, 0xf9b7bcff, 0xd1e7b935, 0x3a7bbf4, 0x837de3d2, 0x18832a20, 0xcaebb8be, 0xe0707476, 0x4879db70, 0x3af9bb5b, 0x8294228, 0x9c840fc5, 0x8b3c2ec7, 0x5c777916, 0xdd8ecc39}, {0x3d6bbdf6, 0x4c4893d9, 0xab724247, 0x664d2eb0, 0xcb84e4b2, 0xc2f0d974, 0xe5ac004a, 0xffaf24ef, 0x80a741ee, 0xc584c2aa, 0x3df476d9, 0x51de26e8, 0xdd9e5eaf, 0xc0d1e7e7, 0x2088f1c8, 0xbc1962c0, 0x7dc847db, 0x5c8f06af, 0xa3fad180, 0x51d810, 0xb1b23c6d, 0xb5a42ccf, 0xee0d75ea, 0x7ce35da0, 0x4968630a}};
static constexpr signed char layer_9_bias[32] = {-1, 1, 1, 1, 1, -1, -1, 1, -1, 1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, 1};
static constexpr signed char layer_10_threshold[32] = {-20, -36, 23, -49, 48, 28, -19, -43, -30, 39, 41, 80, 17, -7, -35, 20, 1, -3, -2, -20, 66, 39, 22, 3, 30, -13, 28, 4, 5, -7, 33, -25};
static constexpr unsigned int layer_11_weight[10][1] = {{0xc2c480ce}, {0xbb26f3d9}, {0x42def652}, {0x137bf5f6}, {0x69736aca}, {0x23ffcd34}, {0xa297f213}, {0xeeb3d657}, {0xb6c238b2}, {0x8e71fc9a}};
static constexpr signed char layer_11_bias[10] = {-1, 1, 1, 1, 1, -1, 1, 1, -1, -1};