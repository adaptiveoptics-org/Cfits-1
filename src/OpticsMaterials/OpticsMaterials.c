#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//
//
// phase offset as function of mask thickness and lambda
// 
// materials:
// 1: SiO2
// 2: Si
// 3: PMGI
// 4: PMMA
//
double OPTICSMATERIALS_pha_lambda( int material, double z, double lambda )
{
  double pha;
  double n;
  long i, i1, i2;
  double ifrac;

  double PressureRatio = 0.0; // Vacuum
  double nair = 1.0;
  
  // SiO2
  double SiO2_n0 = 1.28604141;
  double SiO2_B1 = 1.07044083;
  double SiO2_C1 = 1.00585997e-2;
  double SiO2_B2 = 1.10202242;
  double SiO2_C2 = 100.0;

  // Si
  double Si_B1 = 10.6684293;
  double Si_C1 = 0.301516485;
  double Si_B2 = 0.003043475;
  double Si_C2 = 1.13475115;
  double Si_B3 = 1.54133408;
  double Si_C3 = 1104.0;

  // PMGI 
  double pmgi_n[1000];
  double pmma_n[1001];

  double lambdaum, lambdanm;

  lambdaum = lambda*1.0e6;
  lambdanm = lambda*1.0e9;

  nair = 1.0 + PressureRatio * ( (5792105.0e-8/(238.0185-1.0/(lambdaum*lambdaum))) + (167917.0e-8/(57.362-1.0/(lambdaum*lambdaum))) );

  n = 1.0;

  if(material==1) // SiO2
    n = sqrt(SiO2_n0 + (SiO2_B1*lambdaum*lambdaum)/(lambdaum*lambdaum-SiO2_C1) +(SiO2_B2*lambdaum*lambdaum)/(lambdaum*lambdaum-SiO2_C2));

  if(material==2) // Si
    n = sqrt(1.0 + (Si_B1*lambdaum*lambdaum)/(lambdaum*lambdaum-Si_C1*Si_C1) + (Si_B2*lambdaum*lambdaum)/(lambdaum*lambdaum-Si_C2*Si_C2) + (Si_B3*lambdaum*lambdaum)/(lambdaum*lambdaum-Si_C3*Si_C3));

  if(material==3) // PMGI resist
    {                  
      if(lambdanm>1000)
	{
	  printf("ERROR : PMGI refractive index data does not exist past 1000nm\n");
	  exit(0);
	}

      for(i=0;i<400;i++)
	pmgi_n[i] = 1.5651066510;
      pmgi_n[400] = 1.5651066510;
      pmgi_n[401] = 1.5649120312;
      pmgi_n[402] = 1.5647181723;
      pmgi_n[403] = 1.5645250731;
      pmgi_n[404] = 1.5643327324;
      pmgi_n[405] = 1.5641411491;
      pmgi_n[406] = 1.5639503218;
      pmgi_n[407] = 1.5637602495;
      pmgi_n[408] = 1.5635709307;
      pmgi_n[409] = 1.5633823643;
      pmgi_n[410] = 1.5631945489;
      pmgi_n[411] = 1.5630074831;
      pmgi_n[412] = 1.5628211656;
      pmgi_n[413] = 1.5626355950;
      pmgi_n[414] = 1.5624507699;
      pmgi_n[415] = 1.5622666888;
      pmgi_n[416] = 1.5620833502;
      pmgi_n[417] = 1.5619007527;
      pmgi_n[418] = 1.5617188948;
      pmgi_n[419] = 1.5615377750;
      pmgi_n[420] = 1.5613573916;
      pmgi_n[421] = 1.5611777431;
      pmgi_n[422] = 1.5609988279;
      pmgi_n[423] = 1.5608206445;
      pmgi_n[424] = 1.5606431910;
      pmgi_n[425] = 1.5604664660;
      pmgi_n[426] = 1.5602904677;
      pmgi_n[427] = 1.5601151944;
      pmgi_n[428] = 1.5599406443;
      pmgi_n[429] = 1.5597668159;
      pmgi_n[430] = 1.5595937073;
      pmgi_n[431] = 1.5594213166;
      pmgi_n[432] = 1.5592496423;
      pmgi_n[433] = 1.5590786823;
      pmgi_n[434] = 1.5589084350;
      pmgi_n[435] = 1.5587388984;
      pmgi_n[436] = 1.5585700707;
      pmgi_n[437] = 1.5584019500;
      pmgi_n[438] = 1.5582345344;
      pmgi_n[439] = 1.5580678221;
      pmgi_n[440] = 1.5579018110;
      pmgi_n[441] = 1.5577364993;
      pmgi_n[442] = 1.5575718849;
      pmgi_n[443] = 1.5574079660;
      pmgi_n[444] = 1.5572447405;
      pmgi_n[445] = 1.5570822064;
      pmgi_n[446] = 1.5569203617;
      pmgi_n[447] = 1.5567592044;
      pmgi_n[448] = 1.5565987325;
      pmgi_n[449] = 1.5564389438;
      pmgi_n[450] = 1.5562798363;
      pmgi_n[451] = 1.5561214080;
      pmgi_n[452] = 1.5559636567;
      pmgi_n[453] = 1.5558065804;
      pmgi_n[454] = 1.5556501768;
      pmgi_n[455] = 1.5554944440;
      pmgi_n[456] = 1.5553393797;
      pmgi_n[457] = 1.5551849818;
      pmgi_n[458] = 1.5550312481;
      pmgi_n[459] = 1.5548781765;
      pmgi_n[460] = 1.5547257648;
      pmgi_n[461] = 1.5545740108;
      pmgi_n[462] = 1.5544229123;
      pmgi_n[463] = 1.5542724670;
      pmgi_n[464] = 1.5541226728;
      pmgi_n[465] = 1.5539735275;
      pmgi_n[466] = 1.5538250287;
      pmgi_n[467] = 1.5536771742;
      pmgi_n[468] = 1.5535299619;
      pmgi_n[469] = 1.5533833893;
      pmgi_n[470] = 1.5532374543;
      pmgi_n[471] = 1.5530921546;
      pmgi_n[472] = 1.5529474879;
      pmgi_n[473] = 1.5528034519;
      pmgi_n[474] = 1.5526600442;
      pmgi_n[475] = 1.5525172627;
      pmgi_n[476] = 1.5523751049;
      pmgi_n[477] = 1.5522335686;
      pmgi_n[478] = 1.5520926515;
      pmgi_n[479] = 1.5519523511;
      pmgi_n[480] = 1.5518126652;
      pmgi_n[481] = 1.5516735914;
      pmgi_n[482] = 1.5515351275;
      pmgi_n[483] = 1.5513972709;
      pmgi_n[484] = 1.5512600195;
      pmgi_n[485] = 1.5511233708;
      pmgi_n[486] = 1.5509873224;
      pmgi_n[487] = 1.5508518720;
      pmgi_n[488] = 1.5507170173;
      pmgi_n[489] = 1.5505827558;
      pmgi_n[490] = 1.5504490852;
      pmgi_n[491] = 1.5503160031;
      pmgi_n[492] = 1.5501835071;
      pmgi_n[493] = 1.5500515948;
      pmgi_n[494] = 1.5499202639;
      pmgi_n[495] = 1.5497895119;
      pmgi_n[496] = 1.5496593365;
      pmgi_n[497] = 1.5495297353;
      pmgi_n[498] = 1.5494007058;
      pmgi_n[499] = 1.5492722457;
      pmgi_n[500] = 1.5491443526;
      pmgi_n[501] = 1.5490170241;
      pmgi_n[502] = 1.5488902578;
      pmgi_n[503] = 1.5487640512;
      pmgi_n[504] = 1.5486384021;
      pmgi_n[505] = 1.5485133079;
      pmgi_n[506] = 1.5483887663;
      pmgi_n[507] = 1.5482647749;
      pmgi_n[508] = 1.5481413312;
      pmgi_n[509] = 1.5480184330;
      pmgi_n[510] = 1.5478960777;
      pmgi_n[511] = 1.5477742631;
      pmgi_n[512] = 1.5476529866;
      pmgi_n[513] = 1.5475322459;
      pmgi_n[514] = 1.5474120387;
      pmgi_n[515] = 1.5472923624;
      pmgi_n[516] = 1.5471732148;
      pmgi_n[517] = 1.5470545933;
      pmgi_n[518] = 1.5469364958;
      pmgi_n[519] = 1.5468189197;
      pmgi_n[520] = 1.5467018626;
      pmgi_n[521] = 1.5465853223;
      pmgi_n[522] = 1.5464692963;
      pmgi_n[523] = 1.5463537822;
      pmgi_n[524] = 1.5462387777;
      pmgi_n[525] = 1.5461242804;
      pmgi_n[526] = 1.5460102880;
      pmgi_n[527] = 1.5458967980;
      pmgi_n[528] = 1.5457838082;
      pmgi_n[529] = 1.5456713161;
      pmgi_n[530] = 1.5455593194;
      pmgi_n[531] = 1.5454478158;
      pmgi_n[532] = 1.5453368030;
      pmgi_n[533] = 1.5452262785;
      pmgi_n[534] = 1.5451162401;
      pmgi_n[535] = 1.5450066854;
      pmgi_n[536] = 1.5448976121;
      pmgi_n[537] = 1.5447890179;
      pmgi_n[538] = 1.5446809005;
      pmgi_n[539] = 1.5445732575;
      pmgi_n[540] = 1.5444660867;
      pmgi_n[541] = 1.5443593858;
      pmgi_n[542] = 1.5442531524;
      pmgi_n[543] = 1.5441473843;
      pmgi_n[544] = 1.5440420792;
      pmgi_n[545] = 1.5439372348;
      pmgi_n[546] = 1.5438328489;
      pmgi_n[547] = 1.5437289191;
      pmgi_n[548] = 1.5436254433;
      pmgi_n[549] = 1.5435224192;
      pmgi_n[550] = 1.5434198445;
      pmgi_n[551] = 1.5433177170;
      pmgi_n[552] = 1.5432160345;
      pmgi_n[553] = 1.5431147947;
      pmgi_n[554] = 1.5430139955;
      pmgi_n[555] = 1.5429136345;
      pmgi_n[556] = 1.5428137097;
      pmgi_n[557] = 1.5427142187;
      pmgi_n[558] = 1.5426151595;
      pmgi_n[559] = 1.5425165299;
      pmgi_n[560] = 1.5424183276;
      pmgi_n[561] = 1.5423205504;
      pmgi_n[562] = 1.5422231964;
      pmgi_n[563] = 1.5421262632;
      pmgi_n[564] = 1.5420297488;
      pmgi_n[565] = 1.5419336509;
      pmgi_n[566] = 1.5418379676;
      pmgi_n[567] = 1.5417426966;
      pmgi_n[568] = 1.5416478359;
      pmgi_n[569] = 1.5415533833;
      pmgi_n[570] = 1.5414593367;
      pmgi_n[571] = 1.5413656941;
      pmgi_n[572] = 1.5412724534;
      pmgi_n[573] = 1.5411796125;
      pmgi_n[574] = 1.5410871694;
      pmgi_n[575] = 1.5409951220;
      pmgi_n[576] = 1.5409034682;
      pmgi_n[577] = 1.5408122060;
      pmgi_n[578] = 1.5407213334;
      pmgi_n[579] = 1.5406308485;
      pmgi_n[580] = 1.5405407490;
      pmgi_n[581] = 1.5404510332;
      pmgi_n[582] = 1.5403616989;
      pmgi_n[583] = 1.5402727443;
      pmgi_n[584] = 1.5401841672;
      pmgi_n[585] = 1.5400959659;
      pmgi_n[586] = 1.5400081382;
      pmgi_n[587] = 1.5399206824;
      pmgi_n[588] = 1.5398335963;
      pmgi_n[589] = 1.5397468782;
      pmgi_n[590] = 1.5396605261;
      pmgi_n[591] = 1.5395745380;
      pmgi_n[592] = 1.5394889122;
      pmgi_n[593] = 1.5394036467;
      pmgi_n[594] = 1.5393187396;
      pmgi_n[595] = 1.5392341891;
      pmgi_n[596] = 1.5391499932;
      pmgi_n[597] = 1.5390661503;
      pmgi_n[598] = 1.5389826584;
      pmgi_n[599] = 1.5388995157;
      pmgi_n[600] = 1.5388167203;
      pmgi_n[601] = 1.5387342706;
      pmgi_n[602] = 1.5386521646;
      pmgi_n[603] = 1.5385704006;
      pmgi_n[604] = 1.5384889769;
      pmgi_n[605] = 1.5384078915;
      pmgi_n[606] = 1.5383271429;
      pmgi_n[607] = 1.5382467292;
      pmgi_n[608] = 1.5381666487;
      pmgi_n[609] = 1.5380868997;
      pmgi_n[610] = 1.5380074805;
      pmgi_n[611] = 1.5379283893;
      pmgi_n[612] = 1.5378496245;
      pmgi_n[613] = 1.5377711843;
      pmgi_n[614] = 1.5376930672;
      pmgi_n[615] = 1.5376152714;
      pmgi_n[616] = 1.5375377952;
      pmgi_n[617] = 1.5374606371;
      pmgi_n[618] = 1.5373837954;
      pmgi_n[619] = 1.5373072684;
      pmgi_n[620] = 1.5372310546;
      pmgi_n[621] = 1.5371551523;
      pmgi_n[622] = 1.5370795600;
      pmgi_n[623] = 1.5370042761;
      pmgi_n[624] = 1.5369292989;
      pmgi_n[625] = 1.5368546270;
      pmgi_n[626] = 1.5367802587;
      pmgi_n[627] = 1.5367061926;
      pmgi_n[628] = 1.5366324271;
      pmgi_n[629] = 1.5365589606;
      pmgi_n[630] = 1.5364857917;
      pmgi_n[631] = 1.5364129188;
      pmgi_n[632] = 1.5363403405;
      pmgi_n[633] = 1.5362680553;
      pmgi_n[634] = 1.5361960616;
      pmgi_n[635] = 1.5361243581;
      pmgi_n[636] = 1.5360529433;
      pmgi_n[637] = 1.5359818157;
      pmgi_n[638] = 1.5359109739;
      pmgi_n[639] = 1.5358404165;
      pmgi_n[640] = 1.5357701420;
      pmgi_n[641] = 1.5357001491;
      pmgi_n[642] = 1.5356304363;
      pmgi_n[643] = 1.5355610023;
      pmgi_n[644] = 1.5354918457;
      pmgi_n[645] = 1.5354229651;
      pmgi_n[646] = 1.5353543592;
      pmgi_n[647] = 1.5352860266;
      pmgi_n[648] = 1.5352179659;
      pmgi_n[649] = 1.5351501759;
      pmgi_n[650] = 1.5350826553;
      pmgi_n[651] = 1.5350154026;
      pmgi_n[652] = 1.5349484167;
      pmgi_n[653] = 1.5348816961;
      pmgi_n[654] = 1.5348152398;
      pmgi_n[655] = 1.5347490462;
      pmgi_n[656] = 1.5346831143;
      pmgi_n[657] = 1.5346174427;
      pmgi_n[658] = 1.5345520302;
      pmgi_n[659] = 1.5344868755;
      pmgi_n[660] = 1.5344219774;
      pmgi_n[661] = 1.5343573347;
      pmgi_n[662] = 1.5342929462;
      pmgi_n[663] = 1.5342288107;
      pmgi_n[664] = 1.5341649270;
      pmgi_n[665] = 1.5341012938;
      pmgi_n[666] = 1.5340379101;
      pmgi_n[667] = 1.5339747745;
      pmgi_n[668] = 1.5339118861;
      pmgi_n[669] = 1.5338492435;
      pmgi_n[670] = 1.5337868457;
      pmgi_n[671] = 1.5337246915;
      pmgi_n[672] = 1.5336627798;
      pmgi_n[673] = 1.5336011095;
      pmgi_n[674] = 1.5335396794;
      pmgi_n[675] = 1.5334784884;
      pmgi_n[676] = 1.5334175355;
      pmgi_n[677] = 1.5333568195;
      pmgi_n[678] = 1.5332963393;
      pmgi_n[679] = 1.5332360939;
      pmgi_n[680] = 1.5331760822;
      pmgi_n[681] = 1.5331163031;
      pmgi_n[682] = 1.5330567555;
      pmgi_n[683] = 1.5329974384;
      pmgi_n[684] = 1.5329383508;
      pmgi_n[685] = 1.5328794915;
      pmgi_n[686] = 1.5328208597;
      pmgi_n[687] = 1.5327624542;
      pmgi_n[688] = 1.5327042739;
      pmgi_n[689] = 1.5326463180;
      pmgi_n[690] = 1.5325885854;
      pmgi_n[691] = 1.5325310750;
      pmgi_n[692] = 1.5324737859;
      pmgi_n[693] = 1.5324167171;
      pmgi_n[694] = 1.5323598676;
      pmgi_n[695] = 1.5323032364;
      pmgi_n[696] = 1.5322468225;
      pmgi_n[697] = 1.5321906249;
      pmgi_n[698] = 1.5321346427;
      pmgi_n[699] = 1.5320788749;
      pmgi_n[700] = 1.5320233206;
      pmgi_n[701] = 1.5319679788;
      pmgi_n[702] = 1.5319128484;
      pmgi_n[703] = 1.5318579287;
      pmgi_n[704] = 1.5318032186;
      pmgi_n[705] = 1.5317487173;
      pmgi_n[706] = 1.5316944237;
      pmgi_n[707] = 1.5316403369;
      pmgi_n[708] = 1.5315864560;
      pmgi_n[709] = 1.5315327801;
      pmgi_n[710] = 1.5314793082;
      pmgi_n[711] = 1.5314260395;
      pmgi_n[712] = 1.5313729729;
      pmgi_n[713] = 1.5313201077;
      pmgi_n[714] = 1.5312674428;
      pmgi_n[715] = 1.5312149775;
      pmgi_n[716] = 1.5311627106;
      pmgi_n[717] = 1.5311106414;
      pmgi_n[718] = 1.5310587690;
      pmgi_n[719] = 1.5310070924;
      pmgi_n[720] = 1.5309556107;
      pmgi_n[721] = 1.5309043231;
      pmgi_n[722] = 1.5308532286;
      pmgi_n[723] = 1.5308023263;
      pmgi_n[724] = 1.5307516154;
      pmgi_n[725] = 1.5307010949;
      pmgi_n[726] = 1.5306507640;
      pmgi_n[727] = 1.5306006217;
      pmgi_n[728] = 1.5305506671;
      pmgi_n[729] = 1.5305008994;
      pmgi_n[730] = 1.5304513177;
      pmgi_n[731] = 1.5304019210;
      pmgi_n[732] = 1.5303527085;
      pmgi_n[733] = 1.5303036792;
      pmgi_n[734] = 1.5302548322;
      pmgi_n[735] = 1.5302061668;
      pmgi_n[736] = 1.5301576819;
      pmgi_n[737] = 1.5301093766;
      pmgi_n[738] = 1.5300612500;
      pmgi_n[739] = 1.5300133013;
      pmgi_n[740] = 1.5299655295;
      pmgi_n[741] = 1.5299179337;
      pmgi_n[742] = 1.5298705130;
      pmgi_n[743] = 1.5298232665;
      pmgi_n[744] = 1.5297761931;
      pmgi_n[745] = 1.5297292922;
      pmgi_n[746] = 1.5296825625;
      pmgi_n[747] = 1.5296360034;
      pmgi_n[748] = 1.5295896138;
      pmgi_n[749] = 1.5295433927;
      pmgi_n[750] = 1.5294973393;
      pmgi_n[751] = 1.5294514525;
      pmgi_n[752] = 1.5294057315;
      pmgi_n[753] = 1.5293601752;
      pmgi_n[754] = 1.5293147827;
      pmgi_n[755] = 1.5292695530;
      pmgi_n[756] = 1.5292244852;
      pmgi_n[757] = 1.5291795783;
      pmgi_n[758] = 1.5291348312;
      pmgi_n[759] = 1.5290902430;
      pmgi_n[760] = 1.5290458127;
      pmgi_n[761] = 1.5290015393;
      pmgi_n[762] = 1.5289574217;
      pmgi_n[763] = 1.5289134590;
      pmgi_n[764] = 1.5288696500;
      pmgi_n[765] = 1.5288259938;
      pmgi_n[766] = 1.5287824894;
      pmgi_n[767] = 1.5287391355;
      pmgi_n[768] = 1.5286959313;
      pmgi_n[769] = 1.5286528756;
      pmgi_n[770] = 1.5286099674;
      pmgi_n[771] = 1.5285672054;
      pmgi_n[772] = 1.5285245888;
      pmgi_n[773] = 1.5284821162;
      pmgi_n[774] = 1.5284397867;
      pmgi_n[775] = 1.5283975991;
      pmgi_n[776] = 1.5283555522;
      pmgi_n[777] = 1.5283136449;
      pmgi_n[778] = 1.5282718760;
      pmgi_n[779] = 1.5282302444;
      pmgi_n[780] = 1.5281887488;
      pmgi_n[781] = 1.5281473881;
      pmgi_n[782] = 1.5281061611;
      pmgi_n[783] = 1.5280650665;
      pmgi_n[784] = 1.5280241030;
      pmgi_n[785] = 1.5279832696;
      pmgi_n[786] = 1.5279425648;
      pmgi_n[787] = 1.5279019874;
      pmgi_n[788] = 1.5278615361;
      pmgi_n[789] = 1.5278212096;
      pmgi_n[790] = 1.5277810066;
      pmgi_n[791] = 1.5277409258;
      pmgi_n[792] = 1.5277009658;
      pmgi_n[793] = 1.5276611252;
      pmgi_n[794] = 1.5276214027;
      pmgi_n[795] = 1.5275817968;
      pmgi_n[796] = 1.5275423062;
      pmgi_n[797] = 1.5275029294;
      pmgi_n[798] = 1.5274636650;
      pmgi_n[799] = 1.5274245116;
      pmgi_n[800] = 1.5273854675;
      pmgi_n[801] = 1.5273465314;
      pmgi_n[802] = 1.5273077018;
      pmgi_n[803] = 1.5272689770;
      pmgi_n[804] = 1.5272303555;
      pmgi_n[805] = 1.5271918359;
      pmgi_n[806] = 1.5271534164;
      pmgi_n[807] = 1.5271150955;
      pmgi_n[808] = 1.5270768715;
      pmgi_n[809] = 1.5270387428;
      pmgi_n[810] = 1.5270007077;
      pmgi_n[811] = 1.5269627645;
      pmgi_n[812] = 1.5269249116;
      pmgi_n[813] = 1.5268871471;
      pmgi_n[814] = 1.5268494694;
      pmgi_n[815] = 1.5268118765;
      pmgi_n[816] = 1.5267743669;
      pmgi_n[817] = 1.5267369386;
      pmgi_n[818] = 1.5266995897;
      pmgi_n[819] = 1.5266623184;
      pmgi_n[820] = 1.5266251229;
      pmgi_n[821] = 1.5265880011;
      pmgi_n[822] = 1.5265509512;
      pmgi_n[823] = 1.5265139712;
      pmgi_n[824] = 1.5264770591;
      pmgi_n[825] = 1.5264402128;
      pmgi_n[826] = 1.5264034304;
      pmgi_n[827] = 1.5263667098;
      pmgi_n[828] = 1.5263300488;
      pmgi_n[829] = 1.5262934453;
      pmgi_n[830] = 1.5262568973;
      pmgi_n[831] = 1.5262204025;
      pmgi_n[832] = 1.5261839587;
      pmgi_n[833] = 1.5261475636;
      pmgi_n[834] = 1.5261112151;
      pmgi_n[835] = 1.5260749108;
      pmgi_n[836] = 1.5260386485;
      pmgi_n[837] = 1.5260024256;
      pmgi_n[838] = 1.5259662400;
      pmgi_n[839] = 1.5259300891;
      pmgi_n[840] = 1.5258939706;
      pmgi_n[841] = 1.5258578819;
      pmgi_n[842] = 1.5258218205;
      pmgi_n[843] = 1.5257857840;
      pmgi_n[844] = 1.5257497697;
      pmgi_n[845] = 1.5257137750;
      pmgi_n[846] = 1.5256777974;
      pmgi_n[847] = 1.5256418341;
      pmgi_n[848] = 1.5256058824;
      pmgi_n[849] = 1.5255699397;
      pmgi_n[850] = 1.5255340031;
      pmgi_n[851] = 1.5254980698;
      pmgi_n[852] = 1.5254621370;
      pmgi_n[853] = 1.5254262018;
      pmgi_n[854] = 1.5253902614;
      pmgi_n[855] = 1.5253543127;
      pmgi_n[856] = 1.5253183527;
      pmgi_n[857] = 1.5252823786;
      pmgi_n[858] = 1.5252463871;
      pmgi_n[859] = 1.5252103752;
      pmgi_n[860] = 1.5251743398;
      pmgi_n[861] = 1.5251382776;
      pmgi_n[862] = 1.5251021855;
      pmgi_n[863] = 1.5250660603;
      pmgi_n[864] = 1.5250298985;
      pmgi_n[865] = 1.5249936970;
      pmgi_n[866] = 1.5249574522;
      pmgi_n[867] = 1.5249211608;
      pmgi_n[868] = 1.5248848194;
      pmgi_n[869] = 1.5248484244;
      pmgi_n[870] = 1.5248119723;
      pmgi_n[871] = 1.5247754595;
      pmgi_n[872] = 1.5247388824;
      pmgi_n[873] = 1.5247022373;
      pmgi_n[874] = 1.5246655204;
      pmgi_n[875] = 1.5246287281;
      pmgi_n[876] = 1.5245918565;
      pmgi_n[877] = 1.5245549017;
      pmgi_n[878] = 1.5245178599;
      pmgi_n[879] = 1.5244807272;
      pmgi_n[880] = 1.5244434994;
      pmgi_n[881] = 1.5244061727;
      pmgi_n[882] = 1.5243687428;
      pmgi_n[883] = 1.5243312057;
      pmgi_n[884] = 1.5242935572;
      pmgi_n[885] = 1.5242557930;
      pmgi_n[886] = 1.5242179089;
      pmgi_n[887] = 1.5241799005;
      pmgi_n[888] = 1.5241417635;
      pmgi_n[889] = 1.5241034934;
      pmgi_n[890] = 1.5240650857;
      pmgi_n[891] = 1.5240265360;
      pmgi_n[892] = 1.5239878395;
      pmgi_n[893] = 1.5239489917;
      pmgi_n[894] = 1.5239099879;
      pmgi_n[895] = 1.5238708233;
      pmgi_n[896] = 1.5238314932;
      pmgi_n[897] = 1.5237919926;
      pmgi_n[898] = 1.5237523167;
      pmgi_n[899] = 1.5237124605;
      pmgi_n[900] = 1.5236724189;
      for(i=900;i<1000;i++)
	pmgi_n[i] = 1.5236724189;


      i1 = (long) lambdanm;
      i2 = i1 + 1;
      ifrac = (lambdanm-i1);

      n = pmgi_n[i1]*(1.0-ifrac) + pmgi_n[i2]*ifrac;
    }

  if(material==4) // PMMA resist
    {                  
      if(lambdanm>1001)
	{
	  printf("ERROR : PMMA refractive index data does not exist past 1000nm\n");
	  exit(0);
	}

      for(i=0;i<400;i++)
	pmma_n[i] = 1.5072519581;

      pmma_n[400] = 1.5072519581;
      pmma_n[401] = 1.5071011822;
      pmma_n[402] = 1.5069517124;
      pmma_n[403] = 1.5068035315;
      pmma_n[404] = 1.5066566227;
      pmma_n[405] = 1.5065109694;
      pmma_n[406] = 1.5063665554;
      pmma_n[407] = 1.5062233648;
      pmma_n[408] = 1.5060813819;
      pmma_n[409] = 1.5059405914;
      pmma_n[410] = 1.5058009783;
      pmma_n[411] = 1.5056625278;
      pmma_n[412] = 1.5055252254;
      pmma_n[413] = 1.5053890569;
      pmma_n[414] = 1.5052540082;
      pmma_n[415] = 1.5051200656;
      pmma_n[416] = 1.5049872157;
      pmma_n[417] = 1.5048554452;
      pmma_n[418] = 1.5047247410;
      pmma_n[419] = 1.5045950905;
      pmma_n[420] = 1.5044664809;
      pmma_n[421] = 1.5043389000;
      pmma_n[422] = 1.5042123357;
      pmma_n[423] = 1.5040867759;
      pmma_n[424] = 1.5039622089;
      pmma_n[425] = 1.5038386233;
      pmma_n[426] = 1.5037160076;
      pmma_n[427] = 1.5035943507;
      pmma_n[428] = 1.5034736417;
      pmma_n[429] = 1.5033538697;
      pmma_n[430] = 1.5032350241;
      pmma_n[431] = 1.5031170945;
      pmma_n[432] = 1.5030000706;
      pmma_n[433] = 1.5028839423;
      pmma_n[434] = 1.5027686996;
      pmma_n[435] = 1.5026543327;
      pmma_n[436] = 1.5025408321;
      pmma_n[437] = 1.5024281881;
      pmma_n[438] = 1.5023163915;
      pmma_n[439] = 1.5022054331;
      pmma_n[440] = 1.5020953037;
      pmma_n[441] = 1.5019859946;
      pmma_n[442] = 1.5018774968;
      pmma_n[443] = 1.5017698018;
      pmma_n[444] = 1.5016629010;
      pmma_n[445] = 1.5015567860;
      pmma_n[446] = 1.5014514486;
      pmma_n[447] = 1.5013468806;
      pmma_n[448] = 1.5012430739;
      pmma_n[449] = 1.5011400207;
      pmma_n[450] = 1.5010377132;
      pmma_n[451] = 1.5009361437;
      pmma_n[452] = 1.5008353045;
      pmma_n[453] = 1.5007351883;
      pmma_n[454] = 1.5006357877;
      pmma_n[455] = 1.5005370954;
      pmma_n[456] = 1.5004391043;
      pmma_n[457] = 1.5003418072;
      pmma_n[458] = 1.5002451973;
      pmma_n[459] = 1.5001492677;
      pmma_n[460] = 1.5000540116;
      pmma_n[461] = 1.4999594224;
      pmma_n[462] = 1.4998654935;
      pmma_n[463] = 1.4997722183;
      pmma_n[464] = 1.4996795905;
      pmma_n[465] = 1.4995876037;
      pmma_n[466] = 1.4994962517;
      pmma_n[467] = 1.4994055284;
      pmma_n[468] = 1.4993154277;
      pmma_n[469] = 1.4992259436;
      pmma_n[470] = 1.4991370702;
      pmma_n[471] = 1.4990488016;
      pmma_n[472] = 1.4989611321;
      pmma_n[473] = 1.4988740560;
      pmma_n[474] = 1.4987875676;
      pmma_n[475] = 1.4987016616;
      pmma_n[476] = 1.4986163323;
      pmma_n[477] = 1.4985315744;
      pmma_n[478] = 1.4984473825;
      pmma_n[479] = 1.4983637514;
      pmma_n[480] = 1.4982806759;
      pmma_n[481] = 1.4981981508;
      pmma_n[482] = 1.4981161711;
      pmma_n[483] = 1.4980347318;
      pmma_n[484] = 1.4979538279;
      pmma_n[485] = 1.4978734545;
      pmma_n[486] = 1.4977936068;
      pmma_n[487] = 1.4977142800;
      pmma_n[488] = 1.4976354695;
      pmma_n[489] = 1.4975571705;
      pmma_n[490] = 1.4974793785;
      pmma_n[491] = 1.4974020889;
      pmma_n[492] = 1.4973252973;
      pmma_n[493] = 1.4972489991;
      pmma_n[494] = 1.4971731901;
      pmma_n[495] = 1.4970978659;
      pmma_n[496] = 1.4970230222;
      pmma_n[497] = 1.4969486547;
      pmma_n[498] = 1.4968747594;
      pmma_n[499] = 1.4968013319;
      pmma_n[500] = 1.4967283684;
      pmma_n[501] = 1.4966558647;
      pmma_n[502] = 1.4965838168;
      pmma_n[503] = 1.4965122209;
      pmma_n[504] = 1.4964410729;
      pmma_n[505] = 1.4963703690;
      pmma_n[506] = 1.4963001055;
      pmma_n[507] = 1.4962302785;
      pmma_n[508] = 1.4961608843;
      pmma_n[509] = 1.4960919192;
      pmma_n[510] = 1.4960233796;
      pmma_n[511] = 1.4959552619;
      pmma_n[512] = 1.4958875625;
      pmma_n[513] = 1.4958202778;
      pmma_n[514] = 1.4957534044;
      pmma_n[515] = 1.4956869389;
      pmma_n[516] = 1.4956208778;
      pmma_n[517] = 1.4955552177;
      pmma_n[518] = 1.4954899554;
      pmma_n[519] = 1.4954250874;
      pmma_n[520] = 1.4953606106;
      pmma_n[521] = 1.4952965216;
      pmma_n[522] = 1.4952328174;
      pmma_n[523] = 1.4951694947;
      pmma_n[524] = 1.4951065504;
      pmma_n[525] = 1.4950439814;
      pmma_n[526] = 1.4949817846;
      pmma_n[527] = 1.4949199571;
      pmma_n[528] = 1.4948584957;
      pmma_n[529] = 1.4947973976;
      pmma_n[530] = 1.4947366598;
      pmma_n[531] = 1.4946762794;
      pmma_n[532] = 1.4946162535;
      pmma_n[533] = 1.4945565792;
      pmma_n[534] = 1.4944972538;
      pmma_n[535] = 1.4944382744;
      pmma_n[536] = 1.4943796383;
      pmma_n[537] = 1.4943213427;
      pmma_n[538] = 1.4942633851;
      pmma_n[539] = 1.4942057625;
      pmma_n[540] = 1.4941484725;
      pmma_n[541] = 1.4940915124;
      pmma_n[542] = 1.4940348796;
      pmma_n[543] = 1.4939785715;
      pmma_n[544] = 1.4939225855;
      pmma_n[545] = 1.4938669193;
      pmma_n[546] = 1.4938115701;
      pmma_n[547] = 1.4937565357;
      pmma_n[548] = 1.4937018135;
      pmma_n[549] = 1.4936474011;
      pmma_n[550] = 1.4935932962;
      pmma_n[551] = 1.4935394962;
      pmma_n[552] = 1.4934859990;
      pmma_n[553] = 1.4934328021;
      pmma_n[554] = 1.4933799033;
      pmma_n[555] = 1.4933273002;
      pmma_n[556] = 1.4932749907;
      pmma_n[557] = 1.4932229724;
      pmma_n[558] = 1.4931712432;
      pmma_n[559] = 1.4931198008;
      pmma_n[560] = 1.4930686431;
      pmma_n[561] = 1.4930177679;
      pmma_n[562] = 1.4929671731;
      pmma_n[563] = 1.4929168566;
      pmma_n[564] = 1.4928668163;
      pmma_n[565] = 1.4928170500;
      pmma_n[566] = 1.4927675558;
      pmma_n[567] = 1.4927183316;
      pmma_n[568] = 1.4926693754;
      pmma_n[569] = 1.4926206852;
      pmma_n[570] = 1.4925722591;
      pmma_n[571] = 1.4925240950;
      pmma_n[572] = 1.4924761910;
      pmma_n[573] = 1.4924285452;
      pmma_n[574] = 1.4923811556;
      pmma_n[575] = 1.4923340205;
      pmma_n[576] = 1.4922871379;
      pmma_n[577] = 1.4922405060;
      pmma_n[578] = 1.4921941229;
      pmma_n[579] = 1.4921479869;
      pmma_n[580] = 1.4921020961;
      pmma_n[581] = 1.4920564486;
      pmma_n[582] = 1.4920110429;
      pmma_n[583] = 1.4919658770;
      pmma_n[584] = 1.4919209493;
      pmma_n[585] = 1.4918762581;
      pmma_n[586] = 1.4918318016;
      pmma_n[587] = 1.4917875781;
      pmma_n[588] = 1.4917435860;
      pmma_n[589] = 1.4916998237;
      pmma_n[590] = 1.4916562893;
      pmma_n[591] = 1.4916129814;
      pmma_n[592] = 1.4915698983;
      pmma_n[593] = 1.4915270384;
      pmma_n[594] = 1.4914844002;
      pmma_n[595] = 1.4914419819;
      pmma_n[596] = 1.4913997822;
      pmma_n[597] = 1.4913577994;
      pmma_n[598] = 1.4913160320;
      pmma_n[599] = 1.4912744785;
      pmma_n[600] = 1.4912331374;
      pmma_n[601] = 1.4911920071;
      pmma_n[602] = 1.4911510862;
      pmma_n[603] = 1.4911103733;
      pmma_n[604] = 1.4910698669;
      pmma_n[605] = 1.4910295655;
      pmma_n[606] = 1.4909894677;
      pmma_n[607] = 1.4909495721;
      pmma_n[608] = 1.4909098773;
      pmma_n[609] = 1.4908703819;
      pmma_n[610] = 1.4908310846;
      pmma_n[611] = 1.4907919838;
      pmma_n[612] = 1.4907530784;
      pmma_n[613] = 1.4907143669;
      pmma_n[614] = 1.4906758480;
      pmma_n[615] = 1.4906375204;
      pmma_n[616] = 1.4905993828;
      pmma_n[617] = 1.4905614338;
      pmma_n[618] = 1.4905236722;
      pmma_n[619] = 1.4904860968;
      pmma_n[620] = 1.4904487062;
      pmma_n[621] = 1.4904114991;
      pmma_n[622] = 1.4903744745;
      pmma_n[623] = 1.4903376309;
      pmma_n[624] = 1.4903009672;
      pmma_n[625] = 1.4902644821;
      pmma_n[626] = 1.4902281745;
      pmma_n[627] = 1.4901920432;
      pmma_n[628] = 1.4901560869;
      pmma_n[629] = 1.4901203046;
      pmma_n[630] = 1.4900846950;
      pmma_n[631] = 1.4900492569;
      pmma_n[632] = 1.4900139893;
      pmma_n[633] = 1.4899788910;
      pmma_n[634] = 1.4899439609;
      pmma_n[635] = 1.4899091978;
      pmma_n[636] = 1.4898746007;
      pmma_n[637] = 1.4898401684;
      pmma_n[638] = 1.4898058999;
      pmma_n[639] = 1.4897717940;
      pmma_n[640] = 1.4897378497;
      pmma_n[641] = 1.4897040660;
      pmma_n[642] = 1.4896704417;
      pmma_n[643] = 1.4896369759;
      pmma_n[644] = 1.4896036675;
      pmma_n[645] = 1.4895705154;
      pmma_n[646] = 1.4895375187;
      pmma_n[647] = 1.4895046762;
      pmma_n[648] = 1.4894719871;
      pmma_n[649] = 1.4894394504;
      pmma_n[650] = 1.4894070649;
      pmma_n[651] = 1.4893748298;
      pmma_n[652] = 1.4893427441;
      pmma_n[653] = 1.4893108068;
      pmma_n[654] = 1.4892790169;
      pmma_n[655] = 1.4892473736;
      pmma_n[656] = 1.4892158758;
      pmma_n[657] = 1.4891845226;
      pmma_n[658] = 1.4891533131;
      pmma_n[659] = 1.4891222464;
      pmma_n[660] = 1.4890913216;
      pmma_n[661] = 1.4890605376;
      pmma_n[662] = 1.4890298938;
      pmma_n[663] = 1.4889993891;
      pmma_n[664] = 1.4889690227;
      pmma_n[665] = 1.4889387937;
      pmma_n[666] = 1.4889087012;
      pmma_n[667] = 1.4888787443;
      pmma_n[668] = 1.4888489223;
      pmma_n[669] = 1.4888192342;
      pmma_n[670] = 1.4887896792;
      pmma_n[671] = 1.4887602565;
      pmma_n[672] = 1.4887309652;
      pmma_n[673] = 1.4887018046;
      pmma_n[674] = 1.4886727737;
      pmma_n[675] = 1.4886438718;
      pmma_n[676] = 1.4886150980;
      pmma_n[677] = 1.4885864517;
      pmma_n[678] = 1.4885579319;
      pmma_n[679] = 1.4885295379;
      pmma_n[680] = 1.4885012689;
      pmma_n[681] = 1.4884731241;
      pmma_n[682] = 1.4884451028;
      pmma_n[683] = 1.4884172042;
      pmma_n[684] = 1.4883894275;
      pmma_n[685] = 1.4883617721;
      pmma_n[686] = 1.4883342370;
      pmma_n[687] = 1.4883068216;
      pmma_n[688] = 1.4882795252;
      pmma_n[689] = 1.4882523471;
      pmma_n[690] = 1.4882252864;
      pmma_n[691] = 1.4881983425;
      pmma_n[692] = 1.4881715147;
      pmma_n[693] = 1.4881448023;
      pmma_n[694] = 1.4881182045;
      pmma_n[695] = 1.4880917207;
      pmma_n[696] = 1.4880653501;
      pmma_n[697] = 1.4880390921;
      pmma_n[698] = 1.4880129460;
      pmma_n[699] = 1.4879869112;
      pmma_n[700] = 1.4879609868;
      pmma_n[701] = 1.4879351724;
      pmma_n[702] = 1.4879094672;
      pmma_n[703] = 1.4878838705;
      pmma_n[704] = 1.4878583817;
      pmma_n[705] = 1.4878330002;
      pmma_n[706] = 1.4878077254;
      pmma_n[707] = 1.4877825564;
      pmma_n[708] = 1.4877574929;
      pmma_n[709] = 1.4877325340;
      pmma_n[710] = 1.4877076793;
      pmma_n[711] = 1.4876829280;
      pmma_n[712] = 1.4876582795;
      pmma_n[713] = 1.4876337333;
      pmma_n[714] = 1.4876092887;
      pmma_n[715] = 1.4875849452;
      pmma_n[716] = 1.4875607021;
      pmma_n[717] = 1.4875365588;
      pmma_n[718] = 1.4875125148;
      pmma_n[719] = 1.4874885694;
      pmma_n[720] = 1.4874647222;
      pmma_n[721] = 1.4874409724;
      pmma_n[722] = 1.4874173196;
      pmma_n[723] = 1.4873937631;
      pmma_n[724] = 1.4873703025;
      pmma_n[725] = 1.4873469371;
      pmma_n[726] = 1.4873236663;
      pmma_n[727] = 1.4873004897;
      pmma_n[728] = 1.4872774067;
      pmma_n[729] = 1.4872544168;
      pmma_n[730] = 1.4872315193;
      pmma_n[731] = 1.4872087138;
      pmma_n[732] = 1.4871859997;
      pmma_n[733] = 1.4871633765;
      pmma_n[734] = 1.4871408437;
      pmma_n[735] = 1.4871184008;
      pmma_n[736] = 1.4870960472;
      pmma_n[737] = 1.4870737824;
      pmma_n[738] = 1.4870516059;
      pmma_n[739] = 1.4870295172;
      pmma_n[740] = 1.4870075159;
      pmma_n[741] = 1.4869856013;
      pmma_n[742] = 1.4869637730;
      pmma_n[743] = 1.4869420305;
      pmma_n[744] = 1.4869203734;
      pmma_n[745] = 1.4868988011;
      pmma_n[746] = 1.4868773131;
      pmma_n[747] = 1.4868559090;
      pmma_n[748] = 1.4868345883;
      pmma_n[749] = 1.4868133505;
      pmma_n[750] = 1.4867921951;
      pmma_n[751] = 1.4867711218;
      pmma_n[752] = 1.4867501299;
      pmma_n[753] = 1.4867292192;
      pmma_n[754] = 1.4867083890;
      pmma_n[755] = 1.4866876389;
      pmma_n[756] = 1.4866669686;
      pmma_n[757] = 1.4866463775;
      pmma_n[758] = 1.4866258653;
      pmma_n[759] = 1.4866054313;
      pmma_n[760] = 1.4865850754;
      pmma_n[761] = 1.4865647969;
      pmma_n[762] = 1.4865445954;
      pmma_n[763] = 1.4865244706;
      pmma_n[764] = 1.4865044220;
      pmma_n[765] = 1.4864844492;
      pmma_n[766] = 1.4864645517;
      pmma_n[767] = 1.4864447291;
      pmma_n[768] = 1.4864249811;
      pmma_n[769] = 1.4864053072;
      pmma_n[770] = 1.4863857070;
      pmma_n[771] = 1.4863661801;
      pmma_n[772] = 1.4863467261;
      pmma_n[773] = 1.4863273445;
      pmma_n[774] = 1.4863080351;
      pmma_n[775] = 1.4862887973;
      pmma_n[776] = 1.4862696308;
      pmma_n[777] = 1.4862505353;
      pmma_n[778] = 1.4862315102;
      pmma_n[779] = 1.4862125553;
      pmma_n[780] = 1.4861936702;
      pmma_n[781] = 1.4861748544;
      pmma_n[782] = 1.4861561076;
      pmma_n[783] = 1.4861374294;
      pmma_n[784] = 1.4861188195;
      pmma_n[785] = 1.4861002774;
      pmma_n[786] = 1.4860818029;
      pmma_n[787] = 1.4860633954;
      pmma_n[788] = 1.4860450548;
      pmma_n[789] = 1.4860267806;
      pmma_n[790] = 1.4860085724;
      pmma_n[791] = 1.4859904299;
      pmma_n[792] = 1.4859723528;
      pmma_n[793] = 1.4859543406;
      pmma_n[794] = 1.4859363931;
      pmma_n[795] = 1.4859185099;
      pmma_n[796] = 1.4859006906;
      pmma_n[797] = 1.4858829350;
      pmma_n[798] = 1.4858652426;
      pmma_n[799] = 1.4858476132;
      pmma_n[800] = 1.4858300463;
      pmma_n[801] = 1.4858125417;
      pmma_n[802] = 1.4857950991;
      pmma_n[803] = 1.4857777180;
      pmma_n[804] = 1.4857603982;
      pmma_n[805] = 1.4857431394;
      pmma_n[806] = 1.4857259411;
      pmma_n[807] = 1.4857088032;
      pmma_n[808] = 1.4856917253;
      pmma_n[809] = 1.4856747070;
      pmma_n[810] = 1.4856577481;
      pmma_n[811] = 1.4856408482;
      pmma_n[812] = 1.4856240070;
      pmma_n[813] = 1.4856072243;
      pmma_n[814] = 1.4855904997;
      pmma_n[815] = 1.4855738328;
      pmma_n[816] = 1.4855572235;
      pmma_n[817] = 1.4855406714;
      pmma_n[818] = 1.4855241762;
      pmma_n[819] = 1.4855077376;
      pmma_n[820] = 1.4854913553;
      pmma_n[821] = 1.4854750290;
      pmma_n[822] = 1.4854587584;
      pmma_n[823] = 1.4854425433;
      pmma_n[824] = 1.4854263833;
      pmma_n[825] = 1.4854102782;
      pmma_n[826] = 1.4853942277;
      pmma_n[827] = 1.4853782314;
      pmma_n[828] = 1.4853622892;
      pmma_n[829] = 1.4853464007;
      pmma_n[830] = 1.4853305656;
      pmma_n[831] = 1.4853147838;
      pmma_n[832] = 1.4852990548;
      pmma_n[833] = 1.4852833785;
      pmma_n[834] = 1.4852677545;
      pmma_n[835] = 1.4852521826;
      pmma_n[836] = 1.4852366625;
      pmma_n[837] = 1.4852211940;
      pmma_n[838] = 1.4852057768;
      pmma_n[839] = 1.4851904107;
      pmma_n[840] = 1.4851750953;
      pmma_n[841] = 1.4851598304;
      pmma_n[842] = 1.4851446158;
      pmma_n[843] = 1.4851294512;
      pmma_n[844] = 1.4851143363;
      pmma_n[845] = 1.4850992709;
      pmma_n[846] = 1.4850842548;
      pmma_n[847] = 1.4850692876;
      pmma_n[848] = 1.4850543692;
      pmma_n[849] = 1.4850394993;
      pmma_n[850] = 1.4850246776;
      pmma_n[851] = 1.4850099040;
      pmma_n[852] = 1.4849951781;
      pmma_n[853] = 1.4849804998;
      pmma_n[854] = 1.4849658687;
      pmma_n[855] = 1.4849512847;
      pmma_n[856] = 1.4849367474;
      pmma_n[857] = 1.4849222568;
      pmma_n[858] = 1.4849078125;
      pmma_n[859] = 1.4848934143;
      pmma_n[860] = 1.4848790620;
      pmma_n[861] = 1.4848647554;
      pmma_n[862] = 1.4848504942;
      pmma_n[863] = 1.4848362781;
      pmma_n[864] = 1.4848221071;
      pmma_n[865] = 1.4848079808;
      pmma_n[866] = 1.4847938990;
      pmma_n[867] = 1.4847798615;
      pmma_n[868] = 1.4847658681;
      pmma_n[869] = 1.4847519186;
      pmma_n[870] = 1.4847380127;
      pmma_n[871] = 1.4847241502;
      pmma_n[872] = 1.4847103310;
      pmma_n[873] = 1.4846965547;
      pmma_n[874] = 1.4846828213;
      pmma_n[875] = 1.4846691304;
      pmma_n[876] = 1.4846554819;
      pmma_n[877] = 1.4846418756;
      pmma_n[878] = 1.4846283112;
      pmma_n[879] = 1.4846147886;
      pmma_n[880] = 1.4846013075;
      pmma_n[881] = 1.4845878678;
      pmma_n[882] = 1.4845744692;
      pmma_n[883] = 1.4845611115;
      pmma_n[884] = 1.4845477945;
      pmma_n[885] = 1.4845345182;
      pmma_n[886] = 1.4845212821;
      pmma_n[887] = 1.4845080862;
      pmma_n[888] = 1.4844949302;
      pmma_n[889] = 1.4844818140;
      pmma_n[890] = 1.4844687374;
      pmma_n[891] = 1.4844557001;
      pmma_n[892] = 1.4844427020;
      pmma_n[893] = 1.4844297429;
      pmma_n[894] = 1.4844168226;
      pmma_n[895] = 1.4844039409;
      pmma_n[896] = 1.4843910976;
      pmma_n[897] = 1.4843782926;
      pmma_n[898] = 1.4843655256;
      pmma_n[899] = 1.4843527965;
      pmma_n[900] = 1.4843401051;
      pmma_n[901] = 1.4843274512;
      pmma_n[902] = 1.4843148346;
      pmma_n[903] = 1.4843022552;
      pmma_n[904] = 1.4842897128;
      pmma_n[905] = 1.4842772071;
      pmma_n[906] = 1.4842647381;
      pmma_n[907] = 1.4842523055;
      pmma_n[908] = 1.4842399092;
      pmma_n[909] = 1.4842275490;
      pmma_n[910] = 1.4842152247;
      pmma_n[911] = 1.4842029361;
      pmma_n[912] = 1.4841906832;
      pmma_n[913] = 1.4841784656;
      pmma_n[914] = 1.4841662833;
      pmma_n[915] = 1.4841541361;
      pmma_n[916] = 1.4841420238;
      pmma_n[917] = 1.4841299462;
      pmma_n[918] = 1.4841179033;
      pmma_n[919] = 1.4841058947;
      pmma_n[920] = 1.4840939204;
      pmma_n[921] = 1.4840819802;
      pmma_n[922] = 1.4840700739;
      pmma_n[923] = 1.4840582015;
      pmma_n[924] = 1.4840463626;
      pmma_n[925] = 1.4840345572;
      pmma_n[926] = 1.4840227850;
      pmma_n[927] = 1.4840110461;
      pmma_n[928] = 1.4839993401;
      pmma_n[929] = 1.4839876669;
      pmma_n[930] = 1.4839760265;
      pmma_n[931] = 1.4839644185;
      pmma_n[932] = 1.4839528430;
      pmma_n[933] = 1.4839412996;
      pmma_n[934] = 1.4839297884;
      pmma_n[935] = 1.4839183090;
      pmma_n[936] = 1.4839068615;
      pmma_n[937] = 1.4838954455;
      pmma_n[938] = 1.4838840611;
      pmma_n[939] = 1.4838727080;
      pmma_n[940] = 1.4838613860;
      pmma_n[941] = 1.4838500952;
      pmma_n[942] = 1.4838388352;
      pmma_n[943] = 1.4838276060;
      pmma_n[944] = 1.4838164074;
      pmma_n[945] = 1.4838052392;
      pmma_n[946] = 1.4837941014;
      pmma_n[947] = 1.4837829938;
      pmma_n[948] = 1.4837719163;
      pmma_n[949] = 1.4837608687;
      pmma_n[950] = 1.4837498508;
      pmma_n[951] = 1.4837388626;
      pmma_n[952] = 1.4837279039;
      pmma_n[953] = 1.4837169746;
      pmma_n[954] = 1.4837060745;
      pmma_n[955] = 1.4836952035;
      pmma_n[956] = 1.4836843615;
      pmma_n[957] = 1.4836735483;
      pmma_n[958] = 1.4836627638;
      pmma_n[959] = 1.4836520079;
      pmma_n[960] = 1.4836412805;
      pmma_n[961] = 1.4836305813;
      pmma_n[962] = 1.4836199104;
      pmma_n[963] = 1.4836092675;
      pmma_n[964] = 1.4835986525;
      pmma_n[965] = 1.4835880653;
      pmma_n[966] = 1.4835775058;
      pmma_n[967] = 1.4835669739;
      pmma_n[968] = 1.4835564694;
      pmma_n[969] = 1.4835459922;
      pmma_n[970] = 1.4835355421;
      pmma_n[971] = 1.4835251191;
      pmma_n[972] = 1.4835147231;
      pmma_n[973] = 1.4835043538;
      pmma_n[974] = 1.4834940113;
      pmma_n[975] = 1.4834836953;
      pmma_n[976] = 1.4834734058;
      pmma_n[977] = 1.4834631426;
      pmma_n[978] = 1.4834529056;
      pmma_n[979] = 1.4834426947;
      pmma_n[980] = 1.4834325098;
      pmma_n[981] = 1.4834223508;
      pmma_n[982] = 1.4834122175;
      pmma_n[983] = 1.4834021098;
      pmma_n[984] = 1.4833920277;
      pmma_n[985] = 1.4833819709;
      pmma_n[986] = 1.4833719395;
      pmma_n[987] = 1.4833619332;
      pmma_n[988] = 1.4833519520;
      pmma_n[989] = 1.4833419957;
      pmma_n[990] = 1.4833320643;
      pmma_n[991] = 1.4833221576;
      pmma_n[992] = 1.4833122755;
      pmma_n[993] = 1.4833024179;
      pmma_n[994] = 1.4832925848;
      pmma_n[995] = 1.4832827759;
      pmma_n[996] = 1.4832729912;
      pmma_n[997] = 1.4832632306;
      pmma_n[998] = 1.4832534940;
      pmma_n[999] = 1.4832437812;
      pmma_n[1000] = 1.4832340922;

      i1 = (long) lambdanm;
      i2 = i1 + 1;
      ifrac = (lambdanm-i1);

      n = pmma_n[i1]*(1.0-ifrac) + pmma_n[i2]*ifrac;
    }


  pha = 2.0*M_PI * (n-nair)*z / lambda; 

  return(pha);
}


