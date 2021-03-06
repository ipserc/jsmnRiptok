/*
 * jsmnRiptok.c
 *
 *  Created on: 28 abr. 2018
 *      Author: ipserc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <jsmn.h>
#include <jsmnRipper.h>
#include <errtra.h>

void printTokenValue(char * tpath, char * jsonMsg, jsmntok_t * jsmnTokenArray)
{
	char * tokenValue = getTokenValue(tpath, jsonMsg, jsmnTokenArray);
	printf("%s:%s:\n", tpath, tokenValue ? tokenValue : "Token not found");
	free(tokenValue);
}

int getBestMusicScore(char * jsonMsg, jsmntok_t * jsonTokenArray)
{
	int bestMusicScore = 0;
	int musicScore = 0;
	int bestIndex = 0;
	int index = 0;
	char * tokenValue;
	char tpath[25];
	//char score[100];

	sprintf(tpath, "%s%d%s", "metadata.music[", index, "].score");
	while ((tokenValue = getTokenValue(tpath, jsonMsg, jsonTokenArray)) != NULL)
	{
		musicScore = atoi(tokenValue);
		free(tokenValue);
		if (bestMusicScore < musicScore)
		{
			bestMusicScore = musicScore;
		}	bestIndex = index;
		if (++index > 9) break;
		sprintf(tpath, "%s%d%s", "metadata.music[", index, "].score");
	}
	return bestIndex;
}

int main(int argc, char ** argv)
{
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBCUY9900001\",\"upc\":\"9340813591694\"},\"play_offset_ms\":229460,\"external_metadata\":{\"spotify\":{\"album\":{\"name\":\"Gatecrasher 20 - Past Present Forever\",\"id\":\"49dZMFbMjRhKQqqQwLUv6z\"},\"artists\":[{\"name\":\"Chicane\",\"id\":\"5GxyeQagayzZOg4UwffQlD\"}],\"track\":{\"name\":\"Saltwater\",\"id\":\"5zWTqPR3c4KSUyrmPdM13N\"}},\"deezer\":{\"album\":{\"name\":\"100 Biggest Trance Anthems Ever!\",\"id\":\"14665436\"},\"artists\":[{\"name\":\"Chicane\",\"id\":\"1617\"}],\"track\":{\"name\":\"Saltwater\",\"id\":\"136995842\"}},\"youtube\":{\"vid\":\"IQR6pKLd-ho\"}},\"release_date\":\"2011-04-09\",\"artists\":[{\"name\":\"Chicane\"}],\"genres\":[{\"name\":\"Electro1\"},{\"name\":\"Electro\"},{\"name\":\"Dance\"},{\"name\":\"Trance\"},{\"name\":\"Chillout\"}],\"label\":\"Central Station Records\",\"title\":\"Saltwater\",\"duration_ms\":590180,\"album\":{\"name\":\"Gatecrasher 20 - Past Present Forever\"},\"acrid\":\"8a08abeb9e6d842ff474068e614e9826\",\"result_from\":3,\"score\":91}],\"timestamp_utc\":\"2018-04-28 08:31:43\"},\"cost_time\":0.005000114440918,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"ES5151300020\",\"upc\":\"825646465361\"},\"play_offset_ms\":56820,\"external_metadata\":{\"musicstory\":{\"album\":{\"id\":\"469610\"},\"release\":{\"id\":\"1209467\"},\"track\":{\"id\":\"5572187\"}},\"youtube\":{\"vid\":\"yXG1AvCcJZU\"},\"spotify\":{\"album\":{\"id\":\"18UM58huO9mAZwvKDPhOvw\"},\"artists\":[{\"id\":\"7CJiKj8TrQSms0WSCKbHm4\"}],\"track\":{\"id\":\"1k3Zpp8iHNoORaFkPhG9mh\"}},\"deezer\":{\"album\":{\"id\":6357512},\"artists\":[{\"id\":4993}],\"track\":{\"id\":64908150}}},\"artists\":[{\"name\":\"Fangoria\"}],\"title\":\"Cuatro colores\",\"release_date\":\"2013-06-30\",\"label\":\"WM Spain\",\"duration_ms\":298000,\"album\":{\"name\":\"Cuatricromía\"},\"acrid\":\"be72876f00099b75b9187ab359818a81\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-10 18:41:48\"},\"cost_time\":0.0090000629425049,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"USNLR1100005\",\"upc\":\"884977927375\"},\"play_offset_ms\":55120,\"title\":\"Where Is My Mind?\",\"external_metadata\":{\"musicstory\":{\"track\":{\"id\":\"3744826\"}},\"youtube\":{\"vid\":\"K8-uhmgGBF0\"},\"spotify\":{\"album\":{\"name\":\"Sucker Punch\",\"id\":\"0pdTBKhW8Du8Iher1xi8Gb\"},\"artists\":[{\"name\":\"Yoav\",\"id\":\"2TUFDVa7aZJ4O9U0qjrSJH\"},{\"name\":\"Emily Browning\",\"id\":\"0ncLUhzYnidjOPYR2DPd7d\"}],\"track\":{\"name\":\"Where Is My Mind? - Sucker Punch: Original Motion Picture Soundtrack\",\"id\":\"1NI5tG2wFwIwnysPlt0Pl3\"}},\"lyricfind\":{\"lfid\":\"001-23062327\"},\"deezer\":{\"album\":{\"name\":\"Sucker Punch\",\"id\":\"932597\"},\"artists\":[{\"name\":\"Yoav\",\"id\":\"75197\"},{\"name\":\"Emily Browning\",\"id\":\"1202416\"}],\"track\":{\"name\":\"Where Is My Mind?\",\"id\":\"10199948\"}}},\"artists\":[{\"name\":\"Yoav\"}],\"genres\":[{\"name\":\"Films//Games\"},{\"name\":\"Film Scores\"}],\"release_date\":\"2011-03-04\",\"label\":\"Sony Classical\",\"duration_ms\":371440,\"album\":{\"name\":\"Sucker Punch\"},\"acrid\":\"eb407ab6d4a4b0ccecc91e61ba1a1b63\",\"result_from\":1,\"score\":100}],\"timestamp_utc\":\"2018-05-11 15:56:41\"},\"cost_time\":0.2590000629425,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBAHT8403349\",\"upc\":\"745099284961\"},\"play_offset_ms\":14520,\"title\":\"Walk Out To Winter\",\"external_metadata\":{\"musicstory\":{\"track\":{\"id\":\"424309\"}},\"lyricfind\":{\"lfid\":\"001-2742036\"},\"spotify\":{\"album\":{\"name\":\"Classic Christmas\",\"id\":\"6SKSBZ0kJaYNQjK89PcnbM\"},\"artists\":[{\"name\":\"Aztec Camera\",\"id\":\"7sbwBqdkynNUDgiWU3TQ5J\"}],\"track\":{\"name\":\"Walk Out To Winter\",\"id\":\"0KzK6h2DMwA3flfOgtylfp\"}},\"deezer\":{\"album\":{\"name\":\"High Land, Hard Rain\",\"id\":\"90339\"},\"artists\":[{\"name\":\"Aztec Camera\",\"id\":\"12940\"}],\"track\":{\"name\":\"Walk Out To Winter\",\"id\":\"767801\"}},\"youtube\":{\"vid\":\"kE3lTlPwykE\"}},\"artists\":[{\"name\":\"Aztec Camera\"}],\"genres\":[{\"name\":\"Pop\"}],\"release_date\":\"1991-07-09\",\"label\":\"London Records\",\"duration_ms\":203000,\"album\":{\"name\":\"High Land, Hard Rain\"},\"acrid\":\"b8e89a7e2358e91813647cc989f79976\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-17 21:14:32\"},\"cost_time\":0.0060000419616699,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"BEUM70800110\",\"upc\":\"602517741317\"},\"play_offset_ms\":35880,\"genres\":[{\"name\":\"Electro\"},{\"name\":\"Dance\"},{\"name\":\"Pop\"},{\"name\":\"Rock\"}],\"external_metadata\":{\"musicstory\":{\"track\":{\"id\":\"1550331\"}},\"lyricfind\":{\"lfid\":\"001-14479725\"},\"youtube\":{\"vid\":\"CoPyXKqsDJo\"},\"deezer\":{\"album\":{\"name\":\"Free\",\"id\":\"100331\"},\"artists\":[{\"name\":\"Kate Ryan\",\"id\":\"3871\"}],\"track\":{\"name\":\"Ella Elle L A\",\"id\":\"884135\"}},\"spotify\":{\"album\":{\"name\":\"Los Número Uno De 40 Principales 2008\",\"id\":\"77EgReDYvN1iEarlQwp5NN\"},\"artists\":[{\"name\":\"Kate Ryan\",\"id\":\"47BNWfpngeFHYvBlPPyraM\"}],\"track\":{\"name\":\"Ella Elle L A - Radio Version\",\"id\":\"0t104D1SEdbCjGtz2mUX4j\"}}},\"artists\":[{\"name\":\"Kate Ryan\"}],\"title\":\"Ella Elle L A\",\"release_date\":\"2008-05-26\",\"label\":\"Universal Music\",\"duration_ms\":187293,\"album\":{\"name\":\"Free\"},\"acrid\":\"a4e55c5a84f409c81bf02080dec41c3d\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-17 21:18:16\"},\"cost_time\":0.0060000419616699,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"FRT170800047\",\"upc\":\"600753258279\"},\"play_offset_ms\":37520,\"label\":\"Universal Music\",\"external_metadata\":{\"musicstory\":{\"album\":{\"id\":\"105915\"},\"release\":{\"id\":\"476609\"},\"track\":{\"id\":\"1239791\"}},\"deezer\":{\"album\":{\"name\":\"Can't Fight This Feeling\",\"id\":\"490638\"},\"artists\":[{\"name\":\"Junior Caldera\",\"id\":\"74410\"},{\"name\":\"Sophie Ellis-Bextor\",\"id\":\"961\"}],\"track\":{\"name\":\"Can't Fight This Feeling\",\"id\":\"5354657\"}},\"spotify\":{\"album\":{\"name\":\"Clubland 18\",\"id\":\"7a5NhHpYH7V38B0Wx61Vxi\"},\"artists\":[{\"name\":\"Junior Caldera\",\"id\":\"0uRgQor0jDWaKojnCUhR0b\"},{\"name\":\"Sophie Ellis-Bextor\",\"id\":\"2cBh5lVMg222FFuRU7EfDE\"}],\"track\":{\"name\":\"Can't Fight This Feeling\",\"id\":\"4wvkWybqp53x93GD7XlYVx\"}},\"youtube\":{\"vid\":\"yKxaVriQaDU\"}},\"artists\":[{\"name\":\"Junior Caldera\"}],\"album\":{\"name\":\"Can't Fight This Feeling\"},\"release_date\":\"2010-01-01\",\"title\":\"Can't Fight This Feeling\",\"duration_ms\":220266,\"genres\":[{\"name\":\"Dance\"}],\"acrid\":\"50eb54a12d4b480d2ae269d6d0d5d2c0\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-17 21:27:23\"},\"cost_time\":0.0049998760223389,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBBBN8700002\",\"upc\":\"828768848722\"},\"play_offset_ms\":15300,\"release_date\":\"2006-10-09\",\"external_metadata\":{\"musicstory\":{\"track\":{\"id\":\"6839204\"}},\"deezer\":{\"album\":{\"name\":\"Singles\",\"id\":\"73593\"},\"artists\":[{\"name\":\"Deacon Blue\",\"id\":\"6170\"}],\"track\":{\"name\":\"Dignity\",\"id\":\"565523\"}},\"spotify\":{\"album\":{\"name\":\"Raintown\",\"id\":\"4n3PSt8a0uFZnzOVZ7iqdd\"},\"artists\":[{\"name\":\"Deacon Blue\",\"id\":\"5jqKIZLB5WA5KquEihB3ND\"}],\"track\":{\"name\":\"Dignity\",\"id\":\"78eeFJQFAZVdnBTMtFQoKC\"}},\"lyricfind\":{\"lfid\":\"001-4634592\"},\"youtube\":{\"vid\":\"-3ueYxrA-Zs\"}},\"artists\":[{\"name\":\"Deacon Blue\"}],\"genres\":[{\"name\":\"Alternative\"},{\"name\":\"Indie Pop\"},{\"name\":\"Indie Rock\"},{\"name\":\"Pop\"},{\"name\":\"Indie Pop//Folk\"},{\"name\":\"Rock\"}],\"title\":\"Dignity\",\"label\":\"Columbia\",\"duration_ms\":238440,\"album\":{\"name\":\"Singles\"},\"acrid\":\"bc6395268b93431e36f9a318db647664\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-17 21:29:34\"},\"cost_time\":0.0060000419616699,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"ITC940700719\",\"upc\":\"8032484019218\"},\"play_offset_ms\":46200,\"external_metadata\":{},\"artists\":[{\"name\":\"Robbie Rivera\"}],\"release_date\":\"2007-12-06\",\"source\":\"kkbox:CsqthOx93ZiY2XrR4S\",\"title\":\"Aye Aye Aye (Rivera & Ortega Mix)\",\"duration_ms\":500640,\"album\":{\"name\":\"Aye Aye Aye E.p. Part 2\"},\"acrid\":\"72eda261c95a87f3428febeaa08c7df3\",\"result_from\":1,\"score\":100},{\"external_ids\":{\"isrc\":\"ITC940700719\",\"upc\":\"8032484019218\"},\"play_offset_ms\":46180,\"release_date\":\"2007-12-06\",\"artists\":[{\"name\":\"Robbie Rivera\"}],\"external_metadata\":{\"youtube\":{\"vid\":\"LkFq4SnF774\"},\"spotify\":{\"album\":{\"id\":\"6lphQz5iGPJPe1FZOdI16S\"},\"artists\":[{\"id\":\"4bYwbb6k4ujHD2NXRxSwRP\"}],\"track\":{\"id\":\"0GnbvjRpF3sSpkOHleznUq\"}},\"deezer\":{\"album\":{\"id\":7626992},\"artists\":[{\"id\":7788}],\"genres\":[{\"id\":106},{\"id\":111}],\"track\":{\"id\":76852996}}},\"label\":\"Stop And Go\",\"genres\":[{\"name\":\"Electro\"},{\"name\":\"Techno//House\"}],\"title\":\"Aye Aye Aye\",\"duration_ms\":501708,\"album\":{\"name\":\"Aye Aye Aye E.p. Part 2\"},\"acrid\":\"0388fff610da44fe7c0fecc0e4609d42\",\"result_from\":1,\"score\":76}],\"timestamp_utc\":\"2018-05-17 21:23:36\"},\"cost_time\":0.28900003433228,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBAHT8403350\",\"upc\":\"022924048364\"},\"play_offset_ms\":35560,\"title\":\"All I Need Is Everything\",\"external_metadata\":{\"musicstory\":{\"track\":{\"id\":\"424343\"}},\"youtube\":{\"vid\":\"0dbNUKy6QXM\"},\"spotify\":{\"album\":{\"name\":\"Knife\",\"id\":\"3eAbnzPwbYmbHdXQ9fmfXv\"},\"artists\":[{\"name\":\"Aztec Camera\",\"id\":\"7sbwBqdkynNUDgiWU3TQ5J\"}],\"track\":{\"name\":\"All I Need Is Everything\",\"id\":\"6DXL1O6MDN9kcb1yWbtDGK\"}},\"lyricfind\":{\"lfid\":\"001-4691140\"},\"deezer\":{\"album\":{\"name\":\"Knife\",\"id\":\"83860\"},\"artists\":[{\"name\":\"Aztec Camera\",\"id\":\"12940\"}],\"track\":{\"name\":\"All I Need Is Everything\",\"id\":\"698323\"}}},\"artists\":[{\"name\":\"Aztec Camera\"}],\"genres\":[{\"name\":\"Pop\"}],\"release_date\":\"1991-07-09\",\"label\":\"WM UK\",\"duration_ms\":343227,\"album\":{\"name\":\"Knife\"},\"acrid\":\"dbcb46dcdf7c79035a65713932e0668e\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-18 15:34:37\"},\"cost_time\":0.013999938964844,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBAJH0400007\",\"upc\":\"00724387455955\"},\"play_offset_ms\":6820,\"external_metadata\":{},\"release_date\":\"2013-06-28\",\"artists\":[{\"name\":\"Depeche Mode\"}],\"title\":\"Strangelove (Blind Mix)\",\"duration_ms\":391580,\"album\":{\"name\":\"Remixes 81>04\"},\"acrid\":\"0681bf55cf52ec93d09567f9a1ee0d26\",\"result_from\":1,\"score\":100},{\"external_ids\":{\"isrc\":\"GBAJH0000173\",\"upc\":\"093624032861\"},\"play_offset_ms\":7100,\"release_date\":\"2004-11-02\",\"external_metadata\":{\"spotify\":{\"album\":{\"id\":\"5331VtcJopcteVzgUHMH9R\"},\"artists\":[{\"id\":\"762310PdDnwsDxAQxzQkfX\"}],\"track\":{\"id\":\"1oNqhWK4rdbqgA1jaBLoU4\"}},\"deezer\":{\"album\":{\"id\":1346619},\"artists\":[{\"id\":545}],\"genres\":[{\"id\":132}],\"track\":{\"id\":14627099}},\"youtube\":{\"vid\":\"JIrm0dHbCDU\"}},\"artists\":[{\"name\":\"Depeche Mode\"}],\"title\":\"Strangelove\",\"genres\":[{\"name\":\"Pop\"}],\"label\":\"Reprise//Mute\",\"duration_ms\":393707,\"album\":{\"name\":\"Strangelove (U.S. Maxi Single)\"},\"acrid\":\"31489564c20465c5b8adbbbc90a852f0\",\"result_from\":1,\"score\":73}],\"timestamp_utc\":\"2018-05-19 21:51:26\"},\"cost_time\":0.28999996185303,\"result_type\":0}";
	//char * jsonMsg = "{\"status\":{\"msg\":\"Success\",\"code\":0,\"version\":\"1.0\"},\"metadata\":{\"music\":[{\"external_ids\":{\"isrc\":\"GBAJH0600292\",\"upc\":\"0094636010359\"},\"play_offset_ms\":33340,\"external_metadata\":{\"spotify\":{\"album\":{\"name\":\"Violator\",\"id\":\"1v6DV6Bt0kDsX1Vd1f7CEe\"},\"artists\":[{\"name\":\"Depeche Mode\",\"id\":\"762310PdDnwsDxAQxzQkfX\"}],\"track\":{\"name\":\"Enjoy The Silence - 2006 Digital Remaster\",\"id\":\"3enkvSCLKtGCCXfRyEK9Fl\"}},\"deezer\":{\"album\":{\"name\":\"The Best Of Depeche Mode Volume 1\",\"id\":86578},\"artists\":[{\"name\":\"Depeche Mode\",\"id\":545}],\"genres\":[{\"id\":85}],\"track\":{\"name\":\"Enjoy The Silence (Remastered Version Original)\",\"id\":726176}}},\"acrid\":\"f9377e92e75d5dee3f0cd90a9c163f6a\",\"artists\":[{\"name\":\"Depeche Mode\"}],\"label\":\"(C) 2006 Depeche Mode under exclusive licence to Mute Records LtdThis label copy information is the subject of copyright protection. All rights reserved.(C) 2006 Mute Records Ltd\",\"release_date\":\"1990-03-19\",\"title\":\"Enjoy The Silence - 2006 Digital Remaster\",\"duration_ms\":372813,\"album\":{\"name\":\"Violator\"},\"result_from\":3,\"score\":82},{\"external_ids\":{\"isrc\":\"GBAJH0602198\",\"upc\":\"093624425663\"},\"play_offset_ms\":33440,\"release_date\":\"2006-11-14\",\"external_metadata\":{\"musicstory\":{\"album\":{\"id\":\"162576\"},\"release\":{\"id\":\"815068\"},\"track\":{\"id\":\"2206341\"}},\"deezer\":{\"album\":{\"name\":\"The Best Of Depeche Mode Volume 1\",\"id\":\"86578\"},\"artists\":[{\"name\":\"Depeche Mode\",\"id\":\"545\"}],\"track\":{\"name\":\"Enjoy The Silence (Remastered Version) (Original)\",\"id\":\"726176\"}},\"spotify\":{\"album\":{\"name\":\"Classic Rock: Les Classiques de Marc Ysaye_90s00s\",\"id\":\"3fjD2coxF2SQwLRcjm0ctg\"},\"artists\":[{\"name\":\"Depeche Mode\",\"id\":\"762310PdDnwsDxAQxzQkfX\"}],\"track\":{\"name\":\"Enjoy The Silence\",\"id\":\"6pznJ6pWLmxc69pAUVfgRq\"}},\"lyricfind\":{\"lfid\":\"001-9836867\"},\"youtube\":{\"vid\":\"aGSKrC7dGcY\"}},\"artists\":[{\"name\":\"Depeche Mode\"}],\"genres\":[{\"name\":\"Alternative\"}],\"title\":\"Enjoy The Silence (Remastered Version) (Original)\",\"label\":\"Sire//Reprise\",\"duration_ms\":372000,\"album\":{\"name\":\"The Best Of Depeche Mode Volume 1\"},\"acrid\":\"4ac1fdcab64947a971dee1163f3f2374\",\"result_from\":3,\"score\":100}],\"timestamp_utc\":\"2018-05-19 22:08:18\"},\"cost_time\":0.0060000419616699,\"result_type\":0}";
	char * jsonMsg = "{\"metadata\":{\"timestamp_utc\":\"2020-01-25 10:59:04\",\"music\":[{\"play_offset_ms\":335380,\"artists\":[{\"name\":\"Tears For Fears\"}],\"lyrics\":{\"copyrights\":[\"BMG Rights Management\"]},\"acrid\":\"bec7e81617c39bae5412311d1576723c\",\"genres\":[{\"name\":\"Pop\"},{\"name\":\"Rock\"}],\"album\":{\"name\":\"Guilty Pleasures\"},\"label\":\"Universal Music\",\"external_ids\":{\"isrc\":\"GBF088990128\",\"upc\":\"600753051122\"},\"result_from\":3,\"contributors\":{\"lyricists\":[\"CURT SMITH\",\"ROLAND ORZABAL\"]},\"title\":\"Sowing The Seeds Of Love\",\"duration_ms\":378173,\"score\":100,\"external_metadata\":{\"deezer\":{\"track\":{\"name\":\"Sowing The Seeds Of Love\",\"id\":\"908434\"},\"artists\":[{\"name\":\"Tears for Fears\",\"id\":\"1192\"}],\"album\":{\"name\":\"Guilty Pleasures\",\"id\":\"102529\"}},\"spotify\":{\"track\":{\"name\":\"Sowing The Seeds Of Love\",\"id\":\"0Mri4DItrIor5yN8nj7DRw\"},\"artists\":[{\"name\":\"Tears For Fears\",\"id\":\"4bthk9UfsYUYdcFyqxmSUU\"}],\"album\":{\"name\":\"De 100 Største Pop Hits (Vol. 2)\",\"id\":\"33UVNuGJNIPbe8IPpFcmHJ\"}},\"lyricfind\":{\"lfid\":\"001-2046491\"},\"youtube\":{\"vid\":\"VAtGOESO7W8\"},\"musicstory\":{\"track\":{\"id\":\"31854\"},\"release\":{\"id\":\"1113708\"},\"album\":{\"id\":\"400478\"}}},\"release_date\":\"2007-01-01\"}]},\"cost_time\":0.049000024795532,\"status\":{\"msg\":\"Success\",\"version\":\"1.0\",\"code\":0},\"result_type\":0}";

	jsmn_parser parser;
	jsmntok_t * jsmnTokenArray;

	int tokenCount = parseJSON(jsonMsg, &parser, &jsmnTokenArray);
	if (tokenCount < 0) return EXIT_FAILURE;

	jsmntok_t * jsmnToken = jsmnTokenArray;
	if (getJsmnTokenLen(jsmnToken) < 0) return JSMN_ERROR_PART;
	if (!memcmp("", &jsonMsg[jsmnToken->start], (size_t)getJsmnTokenLen(jsmnToken))) return JSMN_ERROR_PART;
	/**/
	puts("*******************************************");
	printJsmnTokens(jsonMsg, jsmnTokenArray);
	puts("*******************************************");

	printTokenValue("status.msg", jsonMsg, jsmnTokenArray);
	printTokenValue("status.code", jsonMsg, jsmnTokenArray);
	printTokenValue("status.version", jsonMsg, jsmnTokenArray);

	printf("Best Music Score index:%d\n", getBestMusicScore(jsonMsg, jsmnTokenArray));

	puts("------------ 1st entry ------------");
	printTokenValue("metadata.music[0].score", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].album.name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].artists[0].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].artists[1].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].genres[0].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].genres[1].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].title", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].release_date", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].external_metadata.spotify.album.id", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].external_metadata.spotify.track.id", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].external_metadata.spotify.track.name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[0].external_metadata.youtube.vid", jsonMsg, jsmnTokenArray);
	puts("------------ 2nd entry ------------");
	printTokenValue("metadata.music[1].score", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].album.name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].artists[0].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].artists[1].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].genres[0].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].genres[1].name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].title", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].release_date", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].external_metadata.spotify.album.id", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].external_metadata.spotify.track.id", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].external_metadata.spotify.track.name", jsonMsg, jsmnTokenArray);
	printTokenValue("metadata.music[1].external_metadata.youtube.vid", jsonMsg, jsmnTokenArray);
	free(jsmnTokenArray);
	return EXIT_SUCCESS;
}
